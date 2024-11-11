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
string grid[2010];
int n, m, pick, dpr[2010][2010] = {0}, dpc[2010][2010] = {0};
void pre(int mnr, int mxr, int mnc, int mxc) {
  pick = dpr[mnr][mxc] - dpr[mnr][mnc - 1];
  if (mxr > mnr) {
    pick += dpr[mxr][mxc] - dpr[mxr][mnc - 1];
    if (mxr - mnr > 1) {
      pick += dpc[mxr - 1][mnc] - dpc[mnr][mnc];
      if (mnr != mxr) {
        pick += dpc[mxr - 1][mxc] - dpc[mnr][mxc];
      }
    }
  }
}
void pre2(int mnr, int mxr, int mnc, int mxc) {
  for (int r = mnr; r <= mxr; ++r)
    if (grid[r][mnc - 1] == '.') grid[r][mnc - 1] = '+';
  for (int r = mnr; r <= mxr; ++r)
    if (grid[r][mxc - 1] == '.') grid[r][mxc - 1] = '+';
  for (int c = mnc; c <= mxc; ++c)
    if (grid[mnr][c - 1] == '.') grid[mnr][c - 1] = '+';
  for (int c = mnc; c <= mxc; ++c)
    if (grid[mxr][c - 1] == '.') grid[mxr][c - 1] = '+';
}
void print() {
  for (int r = int(1); r <= (int)n; r++) cout << grid[r] << endl;
}
int main() {
  int mxr = -1, mnr = 1e9, mnc = 1e9, mxc = -1, totWhitePixel = 0;
  cin >> n >> m;
  for (int r = int(1); r <= (int)n; r++) cin >> grid[r];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j - 1] == 'w') {
        mnc = min(mnc, j);
        mxc = max(mxc, j);
        mnr = min(mnr, i);
        mxr = max(mxr, i);
        totWhitePixel++;
        dpr[i][j] = dpr[i][j - 1] + 1, dpc[i][j] = dpc[i - 1][j] + 1;
      } else {
        dpr[i][j] = dpr[i][j - 1], dpc[i][j] = dpc[i - 1][j];
      }
    }
  }
  pre(mnr, mxr, mnc, mxc);
  if (pick != totWhitePixel) {
    cout << "-1\n";
    return 0;
  }
  if (mxr - mnr > mxc - mnc) {
    for (int c1 = 1; c1 <= m && c1 + mxr - mnr <= m; ++c1) {
      pre(mnr, mxr, c1, c1 + mxr - mnr);
      if (pick == totWhitePixel) {
        pre2(mnr, mxr, c1, c1 + mxr - mnr);
        print();
        return 0;
      }
    }
  }
  if (mxc - mnc > mxr - mnr) {
    for (int r1 = 1; r1 <= n && r1 + mxc - mnc <= n; ++r1) {
      pre(r1, r1 + mxc - mnc, mnc, mxc);
      if (pick == totWhitePixel) {
        pre2(r1, r1 + mxc - mnc, mnc, mxc);
        print();
        return 0;
      }
    }
  }
  if (mxc - mnc == mxr - mnr) {
    pre2(mnr, mxr, mnc, mxc);
    print();
  } else
    cout << -1 << endl;
  return 0;
}
