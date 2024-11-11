#include <bits/stdc++.h>
const double eps = 1e-7, PI = 3.1415926;
const int N = 1e6 + 10;
using namespace std;
int n, q, m, k, x, y, a[N], mx = -1, mn = 1e9, sum, mem[501][501];
char c[N];
string s, s1, s2;
map<int, int> mp;
vector<int> vec;
int dp(int i, int j) {
  if (i == j) return 1;
  if (i > j) return 0;
  if (mem[i][j] != -1) return mem[i][j];
  int p1 = 1e9, p2 = 1e9;
  p1 = 1 + dp(i + 1, j - 1);
  for (int k = i + 1; k <= j; k++) {
    if (s[k] == s[i]) p2 = min(p2, dp(i + 1, k - 1) + dp(k, j));
  }
  return mem[i][j] = min(p1, p2);
}
int main() {
  memset(mem, -1, sizeof mem);
  cin >> n >> s;
  cout << dp(0, n - 1);
  return 0;
}
