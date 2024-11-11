#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 2040;
int b[kMaxN][kMaxN];
int used[kMaxN][kMaxN];
int circles = 0;
int rectangles = 0;
int n;
int dp[kMaxN][kMaxN][2];
int Go(int r, int c, int dir) {
  int a = dir;
  if (a == -1) a = 0;
  int& alias = dp[r][c][a];
  if (alias != -1) {
    return alias;
  }
  if (!b[r][c]) {
    return alias = c - dir;
  }
  used[r][c] = 1;
  return alias = Go(r, c + dir, dir);
}
vector<pair<int, int> > ExpandRow(int r, int lef, int rig, int dir) {
  vector<pair<int, int> > lens;
  int tr = r;
  int prevl = lef;
  int prevr = rig;
  while (true) {
    int best = 0;
    int bestl = 0;
    int bestr = 0;
    for (int i = prevl; i <= prevr; ++i) {
      int cbl = Go(tr, i, -1);
      int cbr = Go(tr, i, 1);
      if (cbr - cbl + 1 > best) {
        best = cbr - cbl + 1;
        bestl = cbl;
        bestr = cbr;
      }
    }
    if (best == 0) {
      break;
    } else {
      lens.push_back(make_pair(bestl, bestr));
      prevl = bestl;
      prevr = bestr;
    }
    tr += dir;
  }
  return lens;
}
int IsCircle(vector<pair<int, int> > shape) {
  long long center = (shape[0].second + shape[0].first) / 2;
  for (int(i) = 0; (i) < (((int)shape.size())); ++(i))
    if (abs((shape[i].second + shape[i].first) / 2 - center) > 2) {
      return 0;
    }
  long long area = 0LL;
  for (int(i) = 0; (i) < (((int)shape.size())); ++(i)) {
    area += (long long)(shape[i].second - shape[i].first + 1);
  }
  double diam = ((int)shape.size());
  double top = shape[0].second - shape[0].first + 1;
  if (top / diam > 0.8) return 0;
  area *= (diam / (double)((int)shape.size()));
  double pi = atan(1.0) * 4.0;
  double r = diam / 2.0;
  double approx = pi * r * r;
  if (abs(area < approx)) return 1;
  return 0;
}
void TryDetect(int r, int c) {
  int lef = Go(r, c, -1);
  int rig = Go(r, c, 1);
  vector<pair<int, int> > atas = ExpandRow(r, lef, rig, -1);
  vector<pair<int, int> > bawah = ExpandRow(r, lef, rig, +1);
  if (((int)atas.size()) + ((int)bawah.size()) <= 10) {
    return;
  }
  vector<pair<int, int> > all;
  reverse(atas.begin(), atas.end());
  for (int(i) = 0; (i) < (((int)atas.size())); ++(i)) all.push_back(atas[i]);
  all.push_back(make_pair(lef, rig));
  for (int(i) = 0; (i) < (((int)bawah.size())); ++(i)) all.push_back(bawah[i]);
  if (IsCircle(all)) {
    ++circles;
  } else {
    ++rectangles;
  }
}
int main() {
  cin >> n;
  for (int(i) = 0; (i) < (n + 60); ++(i))
    for (int(j) = 0; (j) < (n + 60); ++(j))
      for (int(k) = 0; (k) < (2); ++(k)) dp[i][j][k] = -1;
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < (n); ++(j)) {
      scanf("%d", &(b[i + 30][j + 30]));
    }
  n += 60;
  for (int(i) = 0; (i) < (n); ++(i)) {
    for (int(j) = 0; (j) < (n); ++(j)) {
      if (b[i][j] && !used[i][j]) {
        TryDetect(i, j);
      }
    }
  }
  cout << circles << " " << rectangles << endl;
}
