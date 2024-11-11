#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
int H, W;
string S[401];
int num[405][405][4];
void solve() {
  int f, i, j, k, l, x, y, x2, y2;
  cin >> H >> W;
  for (y = 0; y < H; y++) cin >> S[y];
  for (y = 0; y < H; y++)
    for (x = 0; x < W; x++) S[y][x] = S[y][x] == '0';
  for (y = 0; y < H; y++) {
    for (x = 0; x < W; x++)
      num[y + 1][x + 1][0] = S[y][x] ? (1 + num[y + 1][x][0]) : 0;
    for (x = W - 1; x >= 0; x--)
      num[y + 1][x + 1][1] = S[y][x] ? (1 + num[y + 1][x + 2][1]) : 0;
    for (x = 0; x < W; x++)
      num[y + 1][x + 1][2] = S[y][x] ? (1 + num[y][x + 1][2]) : 0;
  }
  for (y = H - 1; y >= 0; y--) {
    for (x = 0; x < W; x++)
      num[y + 1][x + 1][3] = S[y][x] ? (1 + num[y + 2][x + 1][3]) : 0;
  }
  signed long long ret = 0;
  for (y = 0; y < H; y++)
    for (x = 0; x < W; x++)
      if (S[y][x]) {
        x2 = x + 1;
        y2 = y - 1;
        while (x2 < W && y2 >= 0 && S[y2][x2] && S[y][x2]) {
          if (num[y + 1][x2 + 1][2] >= x2 - x + 1) ret++;
          x2++;
          y2--;
        }
        x2 = x + 1;
        y2 = y + 1;
        while (x2 < W && y2 < H && S[y2][x2] && S[y][x2]) {
          if (num[y + 1][x2 + 1][3] >= x2 - x + 1) ret++;
          x2++;
          y2++;
        }
        x2 = x - 1;
        y2 = y - 1;
        while (x2 >= 0 && y2 >= 0 && S[y2][x2] && S[y][x2]) {
          if (num[y + 1][x2 + 1][2] >= x2 - x + 1) ret++;
          x2--;
          y2--;
        }
        x2 = x - 1;
        y2 = y + 1;
        while (x2 >= 0 && y2 < H && S[y2][x2] && S[y][x2]) {
          if (num[y + 1][x2 + 1][3] >= x2 - x + 1) ret++;
          x2--;
          y2++;
        }
        x2 = 1;
        y2 = y - 1;
        while (x + x2 < W && x - x2 >= 0 && y2 >= 0 && S[y2][x + x2] &&
               S[y2][x - x2]) {
          if (num[y2 + 1][x - x2 + 1][1] >= x2 * 2 + 1) ret++;
          x2++;
          y2--;
        }
        x2 = 1;
        y2 = y + 1;
        while (x + x2 < W && x - x2 >= 0 && y2 < H && S[y2][x + x2] &&
               S[y2][x - x2]) {
          if (num[y2 + 1][x - x2 + 1][1] >= x2 * 2 + 1) ret++;
          x2++;
          y2++;
        }
        x2 = x - 1;
        y2 = 1;
        while (x2 >= 0 && y + y2 < H && y - y2 >= 0 && S[y + y2][x2] &&
               S[y - y2][x2]) {
          if (num[y - y2 + 1][x2 + 1][3] >= y2 * 2 + 1) ret++;
          x2--;
          y2++;
        }
        x2 = x + 1;
        y2 = 1;
        while (x2 >= 0 && y + y2 < H && y - y2 >= 0 && S[y + y2][x2] &&
               S[y - y2][x2]) {
          if (num[y - y2 + 1][x2 + 1][3] >= y2 * 2 + 1) ret++;
          x2++;
          y2++;
        }
      }
  cout << ret << endl;
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
