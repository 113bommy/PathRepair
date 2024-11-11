#include <bits/stdc++.h>
using namespace std;
char map[10][10];
char grid[10][10];
int far[10][10];
int mx, my;
int mmask[10];
int smask[10];
int tmask[10];
int main() {
  memset(far, -1, sizeof far);
  int N = 8;
  for (int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
    smask[i] = (1 << 9) - 1;
    for (int j = 0; j < N; ++j)
      if (grid[i][j] == 'M')
        mmask[i] |= (1 << j);
      else if (grid[i][j] == 'S')
        smask[i] ^= (1 << j);
      else if (grid[i][j] == 'A')
        mx = i, my = j;
  }
  while (1) {
    for (int i = 0; i < N; ++i) {
      tmask[i] = 0;
      if (i > 0)
        tmask[i] |= mmask[i - 1] | (mmask[i - 1] >> 1) | (mmask[i - 1] << 1);
      tmask[i] |= mmask[i + 1] | (mmask[i + 1] >> 1) || (mmask[i + 1] << 1);
      tmask[i] |= mmask[i] | (mmask[i] << 1) | (mmask[i] >> 1);
      tmask[i] &= ((1 << 8) - 1);
    }
    for (int i = 0; i < N; ++i) {
      mmask[i] = tmask[i] & smask[i];
      tmask[i] = (1 << 9) - 1;
    }
    if (mmask[mx] & (1 << my)) {
      puts("WIN");
      return 0;
    }
    for (int i = 1; i < N; ++i) tmask[i] = smask[i - 1];
    for (int i = 0; i < N; ++i) smask[i] = tmask[i];
    bool ok = 0;
    for (int i = 0; i < N; ++i) {
      mmask[i] &= smask[i];
      ok |= (mmask[i] > 0);
    }
    if (!ok) {
      puts("LOSE");
      return 0;
    }
  }
}
