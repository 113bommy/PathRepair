#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAXN = 1e6 + 5;
const unsigned long long MAXD = 1e4 + 5;
const unsigned long long MOD = 1e9 + 7;
int mem[MAXN][4];
int n;
string s;
int solve(int i, int prev) {
  if (i >= n) return 0;
  int &ret = mem[i][prev];
  if (ret != -1) return ret;
  if (s[i] != prev)
    ret = solve(i + 1, s[i]) + 1;
  else
    ret = max(solve(i + 1, prev), solve(i + 1, s[i]));
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(mem, -1, sizeof(mem));
  cin >> n;
  cin >> s;
  cout << min(solve(0, 2) + 2, n);
}
