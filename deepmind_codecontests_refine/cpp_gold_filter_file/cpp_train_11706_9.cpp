#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
int vert[400][400], horz[400][400], topleft[400][400], topright[400][400];
char arr[400][400];
int n, m;
void cvert() {
  for (int i = n - 1; i >= 0; --i) {
    for (int k = 0; k < (int)(m); ++k) {
      if (i == n - 1)
        vert[i][k] = arr[i][k];
      else
        vert[i][k] = vert[i + 1][k] + arr[i][k];
    }
  }
}
void chorz() {
  for (int i = 0; i < (int)(n); ++i) {
    for (int k = m - 1; k >= 0; k--) {
      if (k == m - 1)
        horz[i][k] = arr[i][k];
      else
        horz[i][k] = horz[i][k + 1] + arr[i][k];
    }
  }
}
void ctopleft() {
  for (int i = n - 1; i >= 0; i--) {
    for (int k = m - 1; k >= 0; k--) {
      if (i == n - 1 || k == m - 1)
        topleft[i][k] = arr[i][k];
      else
        topleft[i][k] = topleft[i + 1][k + 1] + arr[i][k];
    }
  }
}
void ctopright() {
  for (int i = n - 1; i >= 0; --i) {
    for (int k = 0; k < (int)(m); ++k) {
      if (i == n - 1 || k == 0)
        topright[i][k] = arr[i][k];
      else
        topright[i][k] = topright[i + 1][k - 1] + arr[i][k];
    }
  }
}
int test(int r, int c) {
  int ret = 0;
  for (int k = 1; k < m - c; k++) {
    if (arr[r][c + k]) break;
    if (r - k >= 0) {
      int cnt1 = abs(vert[r - k][c] - vert[r][c]);
      int cnt2 = abs(topleft[r - k][c] - topleft[r][c + k]);
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
    if (r - k >= 0) {
      int cnt1 = abs(vert[r - k][c + k] - vert[r][c + k]);
      int cnt2 = abs(topright[r - k][c + k] - topright[r][c]);
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
    if (k % 2 == 0 && r - k / 2 >= 0) {
      int cnt1 = abs(topleft[r - k / 2][c + k / 2] - topleft[r][c + k]);
      int cnt2 = abs(topright[r - k / 2][c + k / 2] - topright[r][c]);
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
  }
  for (int j = 1; j < min(m - c, r + 1); j++) {
    if (arr[r - j][c + j]) break;
    {
      int cnt1 = horz[r - j][c + j] - horz[r - j][c];
      int cnt2 = vert[r - j][c] - vert[r][c];
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
    if (r - 2 * j >= 0) {
      int cnt1 = vert[r - 2 * j][c] - vert[r][c];
      int cnt2 = topleft[r - 2 * j][c] - topleft[r - j][c + j];
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
    if (c - j >= 0) {
      int cnt1 = horz[r - j][c - j] - horz[r - j][c + j];
      int cnt2 = topleft[r - j][c - j] - topleft[r][c];
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
  }
  for (int i = 1; i < r + 1; i++) {
    if (arr[r - i][c]) break;
    if (c - i >= 0) {
      int cnt1 = horz[r - i][c] - horz[r - i][c - i];
      int cnt2 = topleft[r - i][c - i] - topleft[r][c];
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
    if (i % 2 == 0 && c - i / 2 >= 0) {
      int cnt1 = topleft[r - i / 2][c - i / 2] - topleft[r][c];
      int cnt2 = topright[r - i][c] - topright[r - i / 2][c - i / 2];
      if (cnt1 == 0 && cnt2 == 0) ret++;
    }
  }
  return ret;
}
int solve() {
  int ret = 0;
  for (int i = 0; i < (int)(n); ++i) {
    for (int k = 0; k < (int)(m); ++k) {
      if (arr[i][k]) continue;
      ret += test(i, k);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (int)(n); ++i)
    for (int k = 0; k < (int)(m); ++k) {
      cin >> arr[i][k];
      arr[i][k] -= '0';
    }
  cvert();
  chorz();
  ctopright();
  ctopleft();
  cout << solve() << endl;
  return 0;
}
