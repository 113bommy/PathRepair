#include <bits/stdc++.h>
using namespace std;
int arr[500][500];
bool barr[500][500];
int dph[500][500];
int dpv[500][500];
int h, w;
void process() {
  for (int i = h - 1; i >= 0; --i) {
    for (int j = w - 2; j >= 0; --j) {
      if (barr[i][j] && barr[i][j + 1])
        dph[i][j] = dph[i][j + 1] + 1;
      else
        dph[i][j] = dph[i][j + 1];
      if (i < h - 1) dph[i][j] += dph[i + 1][j] - dph[i + 1][j + 1];
    }
  }
  for (int i = h - 2; i >= 0; --i) {
    for (int j = w - 1; j >= 0; --j) {
      if (barr[i][j] && barr[i + 1][j])
        dpv[i][j] = dpv[i + 1][j] + 1;
      else
        dpv[i][j] = dpv[i + 1][j];
      if (j < w - 1) dpv[i][j] += dpv[i][j + 1] - dpv[i + 1][j + 1];
    }
  }
}
inline int get_good(int r1, int r2, int c1, int c2) {
  int hor = dph[r1][c1] - dph[r2 + 1][c1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> h >> w;
  char temp;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> temp;
      if (temp == '.') barr[i][j] = true;
    }
  }
  process();
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int ways = 0;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1, --c1, --r2, --c2;
    int topleft = dph[r1][c1] + dpv[r1][c1];
    int bottom = 0, right = 0, bottom_right = 0;
    int hor_sum = dph[r1][c1] - dph[r2 + 1][c1] - dph[r1][c2] + dph[r2 + 1][c2];
    int ver_sum = dpv[r1][c1] - dpv[r2][c1] - dpv[r1][c2 + 1] + dpv[r2][c2 + 1];
    cout << hor_sum + ver_sum << "\n";
  }
}
