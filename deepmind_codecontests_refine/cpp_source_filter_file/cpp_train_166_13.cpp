#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
char ch[10005];
char chcp[10005];
int dpr[10005][4];
int dpc[10005][4];
int n, m;
int ggg[2000];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
string grid;
bool inside(int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; }
pair<int, int> move(int r, int c, int ggg) {
  if (!inside(r, c)) return make_pair(r, c);
  if (chcp[r * m + c] != '.') return make_pair(r, c);
  if (dpr[r * m + c][ggg] == -10) {
    dpr[r * m + c][ggg] = r + dr[ggg];
    dpc[r * m + c][ggg] = c + dc[ggg];
  }
  pair<int, int> hasil = move(dpr[r * m + c][ggg], dpc[r * m + c][ggg], ggg);
  dpr[r * m + c][ggg] = hasil.first;
  dpc[r * m + c][ggg] = hasil.second;
  return hasil;
}
int main() {
  ggg['R'] = 0;
  ggg['D'] = 1;
  ggg['L'] = 2;
  ggg['U'] = 3;
  cin >> n >> m;
  int best = 0;
  int ret = 0;
  for (int i = (int)0; i <= (int)n - 1; i++) {
    cin >> grid;
    for (int j = i * m; j < (i + 1) * m; ++j) ch[j] = grid[j - i * m];
  }
  for (int ir = (int)0; ir <= (int)n - 1; ir++)
    for (int ic = (int)0; ic <= (int)m - 1; ic++)
      if (ch[ir * m + ic] != '.') {
        for (int r = (int)0; r <= (int)n * m - 1; r++)
          for (int d = (int)0; d <= (int)3; d++) dpr[r][d] = dpc[r][d] = -10;
        for (int r = (int)0; r <= (int)n * m - 1; r++) chcp[r] = ch[r];
        int moves = -1;
        int r = ir, c = ic;
        while (inside(r, c)) {
          ++moves;
          int a = ggg[(int)chcp[r * m + c]];
          chcp[r * m + c] = '.';
          pair<int, int> p = move(r, c, a);
          r = p.first;
          c = p.second;
        }
        if (moves > best) {
          best = moves;
          ret = 0;
        }
        if (moves == best) ++ret;
      }
  cout << best << " " << ret << endl;
  return 0;
}
