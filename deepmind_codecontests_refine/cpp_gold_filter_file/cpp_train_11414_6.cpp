#include <bits/stdc++.h>
using namespace std;
int Set(int n, int pos) { return n | (1 << pos); }
int Reset(int n, int pos) { return n = n & ~(1 << pos); }
bool Check(int n, int pos) { return (bool)(n & (1 << pos)); }
int n, w[5], mem[4][1001][(1 << 12)];
bool a[4][1001];
void show_mask(int mask) {
  int z[4][4];
  for (int i = 0; i < 12; i++) {
    z[i % 4][i / 4] = Check(mask, i);
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++) cout << z[i][j] << " \n"[j == 2];
  cout << '\n';
}
bool check_col(int mask) { return (((1 << 4) - 1) & mask); }
int get_mask(int x) {
  int mask = 0;
  for (int i = 0; i < 12; i++) {
    if (i / 4 < n && a[i % 4][x + i / 4]) mask = Set(mask, i);
  }
  return mask;
}
int reSet_mask(int x, int mask, int c) {
  for (int i = 0; i < 12; i++) {
    int u = i % 4, v = i / 4;
    if (u >= x && u < x + c && v < c) mask = Reset(mask, i);
  }
  return mask;
}
int next_mask(int mask) {
  mask = mask >> 8;
  return (mask << 8);
}
int dp(int i, int j, int mask) {
  if (j == n) return 0;
  if (i >= 4) return dp(0, j + 1, (mask >> 4) | next_mask(get_mask(j + 1)));
  int &ret = mem[i][j][mask];
  if (ret != -1) return ret;
  ret = INT_MAX;
  if (!Check(mask, i)) ret = min(ret, dp(i + 1, j, mask));
  for (int c = 1; c <= 3; c++) {
    if (i + c <= 4 && j + c <= n)
      ret = min(ret, w[c] + dp(i + 1, j, reSet_mask(i, (mask), c)));
  }
  if (i + 4 <= 4 && j + 4 <= n) ret = min(ret, w[4] + dp(0, j + 1, 0));
  return ret;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= 4; i++) cin >> w[i];
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = (s[j] == '*');
    }
  }
  memset(mem, -1, sizeof(mem));
  cout << dp(0, 0, get_mask(0)) << '\n';
}
int main() {
  int q = 1;
  for (int kase = 1; kase <= q; kase++) {
    solve();
  }
  return 0;
}
