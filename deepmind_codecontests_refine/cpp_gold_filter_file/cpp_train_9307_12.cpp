#include <bits/stdc++.h>
using namespace std;
int n, m;
int x1[300010], y1_[300010], x2[300010], y2[300010], id[300010];
int dx[300010], dy[300010], y0_[300010];
pair<pair<long long, long long>, long long> dy0[300010];
int d;
vector<pair<long long, long long> > x[300010];
vector<int> X[300010];
vector<int> val[300010];
int xx[1510], yy[1510], rr[1510];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
bool comp(pair<pair<long long, long long>, long long> a,
          pair<pair<long long, long long>, long long> b) {
  return a.first.second * b.first.first < a.first.first * b.first.second ||
         a.first.second * b.first.first == a.first.first * b.first.second &&
             a.second < b.second;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < (n); i++) {
    cin >> x1[i] >> y1_[i] >> x2[i] >> y2[i];
    x1[i] *= 2, y1_[i] *= 2, x2[i] *= 2, y2[i] *= 2;
    if (x1[i] > x2[i] || x1[i] == x2[i] && y1_[i] > y2[i]) {
      swap(x1[i], x2[i]);
      swap(y1_[i], y2[i]);
    }
    dx[i] = x2[i] - x1[i], dy[i] = y2[i] - y1_[i];
    int g = gcd(abs(dx[i]), abs(dy[i]));
    dx[i] /= g, dy[i] /= g;
    if (dx[i] == 0) {
      y0_[i] = x1[i];
    } else {
      y0_[i] = -dy[i] * x1[i] + dx[i] * y1_[i];
    }
    dy0[i] = make_pair(make_pair(dx[i], dy[i]), y0_[i]);
  }
  sort(dy0, dy0 + n, comp);
  d = unique(dy0, dy0 + n) - dy0;
  for (int i = 0; i < (n); i++) {
    id[i] = lower_bound(dy0, dy0 + d,
                        make_pair(make_pair(dx[i], dy[i]), y0_[i]), comp) -
            dy0;
    if (dx[i] == 0) {
      x[id[i]].push_back(make_pair(y1_[i] * 10, +1));
      x[id[i]].push_back(make_pair(y2[i] * 10 + 1, -1));
      X[id[i]].push_back(y1_[i] * 10);
      X[id[i]].push_back(y2[i] * 10 + 1);
    } else {
      x[id[i]].push_back(make_pair(x1[i] * 10, +1));
      x[id[i]].push_back(make_pair(x2[i] * 10 + 1, -1));
      X[id[i]].push_back(x1[i] * 10);
      X[id[i]].push_back(x2[i] * 10 + 1);
    }
  }
  for (int i = 0; i < (d); i++) {
    X[i].push_back(1070000000LL);
    sort(X[i].begin(), X[i].end());
    X[i].erase(unique(X[i].begin(), X[i].end()), X[i].end());
    val[i].resize(((int)(X[i]).size()));
    sort(x[i].begin(), x[i].end());
    int curx = -1070000000LL, curval = 0, pos = 0;
    val[i][0] = 0;
    for (int j = 0; j < (((int)(x[i]).size())); j++) {
      if (x[i][j].first != curx) {
        curx = x[i][j].first;
        pos++;
      }
      curval += x[i][j].second;
      val[i][pos] = curval;
    }
  }
  for (int i = 0; i < (m); i++) {
    cin >> xx[i] >> yy[i] >> rr[i];
    xx[i] *= 2, yy[i] *= 2, rr[i] *= 2;
  }
  long long ans = 0;
  for (int ii = 0; ii < (m); ii++)
    for (int jj = ii + 1; jj < (m); jj++) {
      if (rr[ii] != rr[jj]) continue;
      int cx = (xx[ii] + xx[jj]) / 2, cy = (yy[ii] + yy[jj]) / 2;
      int dist2 = ((xx[ii] - xx[jj]) * (xx[ii] - xx[jj])) +
                  ((yy[ii] - yy[jj]) * (yy[ii] - yy[jj]));
      if (((2 * rr[ii]) * (2 * rr[ii])) >= dist2) continue;
      int DX_ = xx[jj] - xx[ii], DY_ = yy[jj] - yy[ii];
      int DX = -DY_, DY = DX_;
      if (DX < 0 || DX == 0 && DY < 0) DX *= -1, DY *= -1;
      int g = gcd(abs(DX), abs(DY));
      DX /= g, DY /= g;
      int Y0;
      if (DX == 0) {
        Y0 = cx;
      } else {
        Y0 = -DY * cx + DX * cy;
      }
      pair<pair<long long, long long>, long long> t =
          make_pair(make_pair(DX, DY), Y0);
      int kind = lower_bound(dy0, dy0 + d, t, comp) - dy0;
      if (kind == d || dy0[kind] != t) continue;
      int pos = upper_bound(X[kind].begin(), X[kind].end(),
                            (DX == 0 ? cy : cx) * 10) -
                X[kind].begin();
      ans += val[kind][pos];
    }
  cout << ans << endl;
}
