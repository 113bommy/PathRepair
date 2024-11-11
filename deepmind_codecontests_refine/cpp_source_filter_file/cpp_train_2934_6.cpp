#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-8);
int dcmp(long double x, long double y) {
  if (abs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
const int MAX_N = 100005;
int mem[MAX_N][2];
string s;
int solve(int i, int last) {
  if (i == (int)(s).size()) return 0;
  int &ret = mem[i][last];
  if (~ret) return ret;
  ret = solve(i + 1, last);
  if (s[i] - '0' >= last) ret = max(ret, 1 + solve(i + 1, s[i] - '0'));
  return ret;
}
int get(int i) { return mem[0][0] - max(mem[i + 1][0], mem[i + 1][1]); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  string t(s);
  int i = 0;
  memset(mem, -1, sizeof(mem));
  solve(0, 0);
  vector<int> a((int)(s).size());
  for (int i = 0; i < (int)(a).size(); ++i) a[i] = get(i);
  int countZeros = 0;
  for (int i = 0; i < (int)(a).size();) {
    int j = i;
    while (a[j] == a[i]) {
      if (s[j] == '0') countZeros++;
      ++j;
    }
    int giveZeros = max(0, get(i) - countZeros);
    for (int k = i; k <= j - 1 && giveZeros; ++k) {
      if (t[k] == '1') {
        t[k] = '0';
        giveZeros--;
        countZeros--;
      }
    }
    i = j;
  }
  cout << t;
  return 0;
}
