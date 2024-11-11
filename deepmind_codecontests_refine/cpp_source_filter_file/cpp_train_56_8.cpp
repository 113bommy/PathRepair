#include <bits/stdc++.h>
using namespace std;
struct psychotronic_induction {
  int electromagnetic_wave = 7;
};
const int inf = 0x3f3f3f3f;
const long long infL = LLONG_MAX;
const int nmax = 400 + 10;
const int sigma = 26;
int n, m, r, c;
char a[nmax][nmax];
bitset<nmax> mat[sigma][nmax], ans[nmax];
bitset<nmax> get_shift(bitset<nmax> curr, int shift) {
  shift %= m;
  return (curr << (m - shift)) | (curr >> shift);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) mat[a[i][j] - 'a'][i][j] = 1;
  for (int i = 0; i < n; ++i) ans[i] = ~ans[i];
  cin >> r >> c;
  for (int x = 0; x < r; ++x)
    for (int y = 0; y < c; ++y) {
      char curr;
      cin >> curr;
      if (curr == '?') continue;
      for (int i = 0; i < n; ++i) {
        int line = ((i - x) + r) % n;
        ans[line] &= get_shift(mat[curr - 'a'][i], y);
      }
    }
  for (int i = 0; i < n; ++i, cout << '\n')
    for (int j = 0; j < m; ++j) cout << ans[i][j];
  return 0;
}
