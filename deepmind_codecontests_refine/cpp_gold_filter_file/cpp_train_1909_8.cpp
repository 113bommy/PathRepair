#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
char buf[1000];
string nextLine(int length = 100) {
  cin.getline(buf, length);
  string s(buf);
  return s;
}
string next(int length = 100) {
  string tmp;
  cin >> tmp;
  return tmp;
}
int nextInt() {
  int tmp;
  scanf("%d", &tmp);
  return tmp;
}
long long mod = 1E9 + 7;
long long add(long long a, long long b) { return (a + b) % mod; }
const int MAXN = 5010;
string s1, s2;
int m, n;
long long dp[MAXN][MAXN];
long long get(int starta, int startb) {
  if (starta == m) return 0;
  if (startb == n) return 0;
  long long &ret = dp[starta][startb];
  if (ret != -1) return ret;
  ret = 0;
  if (s2[startb] == s1[starta]) {
    ret++;
    ret = add(ret, get(starta + 1, startb + 1));
  }
  ret = add(ret, get(starta, startb + 1));
  return ret;
}
int main() {
  s1 = next();
  s2 = next();
  m = ((int)(s1).size());
  n = ((int)(s2).size());
  long long sum = 0;
  for (int i = 0, _i = (MAXN); i < _i; ++i)
    for (int j = 0, _j = (MAXN); j < _j; ++j) dp[i][j] = -1;
  for (int i = 0, _i = (m); i < _i; ++i) {
    sum = add(sum, get(i, 0));
  }
  cout << sum << endl;
}
