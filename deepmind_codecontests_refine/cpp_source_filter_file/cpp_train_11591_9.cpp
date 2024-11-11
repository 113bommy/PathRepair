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
const int MAXN = 4100;
int t[MAXN], d[MAXN];
int dp[MAXN][MAXN];
int start(int call, int ignored);
int end(int call, int ignored) {
  return max(start(call, ignored), t[call]) + d[call] - 1;
}
int start(int call, int ignored) {
  if (ignored < 0) return inf;
  if (call == 0) return 0;
  int &ret = dp[call][ignored];
  if (ret) return ret;
  ret = min(end(call - 1, ignored) + 1, start(call - 1, ignored - 1));
  return ret;
}
int main() {
  int n = nextInt(), k = nextInt();
  for (int i = 0, _i = (n); i < _i; ++i) {
    t[i] = nextInt();
    d[i] = nextInt();
  }
  t[n] = 86400;
  int maxsleep = 0;
  for (int i = 0; i <= n; i++) {
    maxsleep = max(maxsleep, t[i] - start(i, k));
  }
  cout << maxsleep << endl;
}
