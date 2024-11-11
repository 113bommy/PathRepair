#include <bits/stdc++.h>
const double eps = (1e-10);
using namespace std;
int dcmp(double a, double b) {
  return fabs(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
long long getBit(long long num, int idx) { return ((num >> idx) & 1ll) == 1ll; }
long long setBit1(long long num, int idx) { return num | (1ll << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
int countNumBit1(long long mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1ll);
    ++ret;
  }
  return ret;
}
int n, m, k, mem[100 + 9][100 + 9][11 + 9], arr[100 + 9][100 + 9],
    nxtc[100 + 9][100 + 9][11 + 9];
string print[100 + 9][100 + 9][11 + 9];
int fun(int r, int c, int M) {
  if (c <= 0 || c > m) return -900000;
  if (r == 0) {
    if (M == 0) return 0;
    return -900000;
  }
  int &ret = mem[r][c][M];
  if (ret != -1) return ret;
  ret = 0;
  int a1 = 0, a2 = 0;
  a1 = arr[r][c] + fun(r - 1, c - 1, (M + arr[r][c]) % k);
  a2 = arr[r][c] + fun(r - 1, c + 1, (M + arr[r][c]) % k);
  if (a1 > a2)
    print[r][c][M] = "L", nxtc[r][c][M] = c - 1;
  else
    print[r][c][M] = "R", nxtc[r][c][M] = c + 1;
  ret = max(a1, a2);
  return ret;
}
int main() {
  cin >> n >> m >> k;
  k += 1;
  string st;
  for (int i = 0; i < n; i++) {
    cin >> st;
    for (int j = 0; j < m; j++) arr[i + 1][j + 1] = st[j] - '0';
  }
  int mx = -1;
  memset(mem, -1, sizeof(mem));
  int str;
  for (int i = 1; i <= m; i++) {
    int val = fun(n, i, 0);
    if (val > mx) {
      mx = val;
      str = i;
    }
  }
  if (mx == -1) {
    cout << "-1\n";
    return 0;
  }
  cout << mx << endl << str << endl;
  int r = n;
  int c = str;
  int M = 0;
  int T = n - 1;
  for (; T--;) {
    cout << print[r][c][M];
    int tM = (M + arr[r][c]) % k;
    c = nxtc[r][c][M];
    r = r - 1;
    M = tM;
  }
  cout << endl;
}
