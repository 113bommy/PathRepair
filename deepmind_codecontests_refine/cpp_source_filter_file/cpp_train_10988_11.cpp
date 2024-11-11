#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265359;
class Grid {
 public:
  long long t;
  int n, m;
  vector<int> mults;
  vector<vector<bool>> hasTop, hasLeft;
  int iend, jend;
  vector<pair<int, int>> vp1, vp2;
  Grid(long long _t, int _iend, int _jend) : t(_t), iend(_iend), jend(_jend) {
    vector<vector<long long>> v(iend, vector<long long>(jend, 0));
    for (int i = 1; i < iend; i++) {
      for (int j = 1; j < jend; j++) {
        v[i][j] = (j == 1 && i == 1
                       ? 1
                       : min(1000000000000000001ll,
                             min(1000000000000000001ll, v[i - 1][j]) +
                                 min(1000000000000000001ll, v[i][j - 1])));
      }
    }
    vector<int> vm(iend, 0);
    for (int pos = 33; pos > 0; pos--) {
      vm[pos] = t / v[pos][jend - 1];
      t %= v[pos][jend - 1];
    }
    mults = vm;
    vector<vector<bool>> vb(51, vector<bool>(51, true));
    hasTop = vb;
    hasLeft = vb;
    for (int j = 2; j <= jend; j++) {
      hasLeft[2][j] = false;
    }
    for (int i = 2; i <= iend; i++) {
      hasTop[i][3] = false;
    }
    hasTop[iend + 1][1] = false;
  }
  void makeHpath(int imin, int imax, int ct) {
    if (ct) {
      for (int j = jend + 1; j < 50; j++) {
        hasTop[imax + 1][j] = false;
      }
    }
    for (int i = imin; i <= imax; i++) {
      if (i > imin) hasLeft[i][jend + 1] = false;
      if (i < imax) hasLeft[i][jend + 1 + ct] = false;
    }
  }
  void makeVpath(int jmin, int jmax, int ct) {
    if (ct) {
      for (int i = iend + 1; i < 50; i++) {
        hasLeft[i][jmax + 1] = false;
      }
    }
    for (int j = jmin; j <= jmax; j++) {
      if (j > jmin) hasTop[iend + 1][j] = false;
      if (j < jmax) hasTop[iend + ct + 1][j] = false;
    }
  }
  void fillGrid() {
    n = 0, m = 0;
    vector<int> nums = {0, 1, 3, 6, 10, 15, 21, 28, 36};
    for (int pos = 1, ip = 1, jp = 2; pos < iend; pos++) {
      if (pos % 2) {
        if (pos == 1) {
          int p = 0;
          while (nums[p] < mults[1]) {
            p++;
          }
          int diff = nums[p] - mults[1];
          makeHpath(1, 3, p);
          if (diff) hasTop[3][jend + diff] = false;
          ip = 4;
          m = max(m, jend + p);
        } else {
          makeHpath(ip, ip + 1, mults[pos]);
          ip += 2;
          m = max(m, jend + mults[pos]);
        }
      } else {
        if (pos == 2) {
          int p = 0;
          while (nums[p] < mults[2]) {
            p++;
          }
          int diff = nums[p] - mults[2];
          makeVpath(2, 4, p);
          if (diff) hasLeft[iend + diff][4] = false;
          jp = 5;
          n = max(n, iend + 1 + p);
        } else {
          makeVpath(jp, jp + 1, mults[pos]);
          jp += 2;
          n = max(n, iend + 1 + mults[pos]);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      hasTop[i][m] = true;
    }
    for (int j = 1; j <= m; j++) {
      hasLeft[n][j] = true;
    }
  }
  long long getVal() {
    vector<vector<long long>> v(51, vector<long long>(51, 0));
    for (int i = 1; i <= 50; i++) {
      for (int j = 1; j <= 50; j++) {
        if (i == 1 && j == 1)
          v[i][j] = 1;
        else {
          if (hasTop[i][j]) v[i][j] += v[i - 1][j];
          if (hasLeft[i][j]) v[i][j] += v[i][j - 1];
        }
      }
    }
    return v[n][m];
  }
  void createPairs() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (j > 1 && !hasLeft[i][j]) {
          vp1.push_back({i, j - 1});
          vp2.push_back({i, j});
        }
        if (i > 1 && !hasTop[i][j]) {
          vp1.push_back({i - 1, j});
          vp2.push_back({i, j});
        }
      }
    }
  }
  void disp() {
    cout << n << " " << m << endl;
    cout << vp1.size() << endl;
    for (int i = 0; i < vp1.size(); i++) {
      cout << vp1[i].first << " " << vp1[i].second << " " << vp2[i].first << " "
           << vp2[i].second << endl;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (int i = 35; i <= 36; i++) {
    Grid gr(t, i, i);
    gr.fillGrid();
    gr.createPairs();
    if (gr.vp1.size() <= 300) {
      gr.disp();
      return 0;
    }
  }
  return 0;
}
