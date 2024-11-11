#include <bits/stdc++.h>
using namespace std;
char a[1111][1111];
int n, m;
inline bool rect(int sx, int sy, int fx, int fy) {
  for (int i = sx; i <= fx; ++i) {
    if (a[i][sy] == '.') return 0;
    if (a[i][fy] == '.') return 0;
  }
  for (int j = sy; j <= fy; ++j) {
    if (a[sx][j] == '.') return 0;
    if (a[fx][j] == '.') return 0;
  }
  return 1;
}
inline void fill(int sx, int sy, int fx, int fy, char sym) {
  for (int i = sx; i <= fx; ++i) {
    a[i][sy] = sym;
    a[i][fy] = sym;
  }
  for (int j = sy; j <= fy; ++j) {
    a[sx][j] = sym;
    a[fx][j] = sym;
  }
}
vector<pair<int, int> > col;
inline void check(int sx, int sy, int fx, int fy) {
  if (fx - sx < 2) return;
  if (fy - sy < 2) return;
  if (!rect(sx, sy, fx, fy)) return;
  fill(sx, sy, fx, fy, '?');
  bool alf = true;
  int mnx = 1000000000, mxx = -1000000000, mny = 1000000000, mxy = -1000000000;
  for (int i = 0; i < (int)(col).size(); ++i) {
    if (a[col[i].first][col[i].second] == '#') {
      alf = false;
      mnx = min(mnx, col[i].first);
      mxx = max(mnx, col[i].first);
      mny = min(mny, col[i].second);
      mxy = max(mny, col[i].second);
    }
  }
  if (alf) {
    cout << "YES\n";
    cout << sx + 1 << " " << sy + 1 << " " << fx + 1 << " " << fy + 1 << endl;
    cout << sx + 1 << " " << sy + 1 << " " << fx + 1 << " " << fy + 1 << endl;
    exit(0);
  }
  vector<int> xx(0);
  xx.push_back(sx);
  xx.push_back(fx);
  xx.push_back(mnx);
  xx.push_back(mxx);
  vector<int> yy(0);
  yy.push_back(sy);
  yy.push_back(fy);
  yy.push_back(mny);
  yy.push_back(mxy);
  sort((xx).begin(), (xx).end());
  xx.resize(unique((xx).begin(), (xx).end()) - xx.begin());
  sort((yy).begin(), (yy).end());
  yy.resize(unique((yy).begin(), (yy).end()) - yy.begin());
  for (int ix = 0; ix < (int)(xx).size(); ++ix) {
    for (int jx = ix + 1; jx < (int)(xx).size(); ++jx) {
      if (xx[jx] - xx[ix] < 2) continue;
      for (int iy = 0; iy < (int)(yy).size(); ++iy) {
        for (int jy = iy + 1; jy < (int)(yy).size(); ++jy) {
          if (yy[jy] - yy[iy] < 2) continue;
          bool ok = true;
          for (int i = 0; i < (int)(col).size(); ++i) {
            if (a[col[i].first][col[i].second] == '#') {
              if ((col[i].first == xx[ix] || col[i].first == xx[jx]) &&
                  col[i].second >= yy[iy] && col[i].second <= yy[jy])
                continue;
              if ((col[i].second == yy[iy] || col[i].second == yy[jy]) &&
                  col[i].first >= xx[ix] && col[i].first <= xx[jx])
                continue;
              ok = false;
              break;
            }
          }
          ok &= rect(xx[ix], yy[iy], xx[jx], yy[jy]);
          if (ok) {
            cout << "YES\n";
            cout << sx + 1 << " " << sy + 1 << " " << fx + 1 << " " << fy + 1
                 << endl;
            cout << xx[ix] + 1 << " " << yy[iy] + 1 << " " << xx[jx] + 1 << " "
                 << yy[jy] + 1 << endl;
            exit(0);
          }
        }
      }
    }
  }
  fill(sx, sy, fx, fy, '#');
}
inline void check2(pair<int, int> sa, pair<int, int> fa, pair<int, int> sb,
                   pair<int, int> fb) {
  if (!rect(sa.first, sa.second, fa.first, fa.second)) return;
  if (!rect(sb.first, sb.second, fb.first, fb.second)) return;
  fill(sa.first, sa.second, fa.first, fa.second, '?');
  fill(sb.first, sb.second, fb.first, fb.second, '?');
  bool ok = 1;
  for (int i = 0; i < (int)(col).size(); ++i) {
    if (a[col[i].first][col[i].second] == '#') {
      ok = 0;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
    cout << sa.first + 1 << " " << sa.second + 1 << " " << fa.first + 1 << " "
         << fa.second + 1 << endl;
    cout << sb.first + 1 << " " << sb.second + 1 << " " << fb.first + 1 << " "
         << fb.second + 1 << endl;
    exit(0);
  }
  fill(sa.first, sa.second, fa.first, fa.second, '#');
  fill(fa.first, fa.second, fb.first, fb.second, '#');
}
int main() {
  gets(a[0]);
  sscanf(a[0], "%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    gets(a[i]);
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#') col.push_back(make_pair(i, j));
    }
  }
  pair<int, int> top = make_pair(-1, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#') {
        top = make_pair(i, j);
        i = j = 1000000000;
      }
    }
  }
  vector<int> xc(0), yc(0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m;) {
      int oj = j;
      while (j < m && a[i][j] == '#') ++j;
      if (j - oj > 4) {
        xc.push_back(i);
        break;
      }
      ++j;
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n;) {
      int oi = i;
      while (i < n && a[i][j] == '#') ++i;
      if (i - oi > 4) {
        yc.push_back(j);
        break;
      }
      ++i;
    }
  }
  if ((int)(xc).size() < 5 && (int)(yc).size() < 5) {
    vector<pair<pair<int, int>, pair<int, int> > > vp(0);
    sort((xc).begin(), (xc).end());
    sort((yc).begin(), (yc).end());
    for (int ix = 0; ix < (int)(xc).size(); ++ix)
      for (int jx = ix + 1; jx < (int)(xc).size(); ++jx)
        if (xc[jx] - xc[ix] > 1)
          for (int iy = 0; iy < (int)(yc).size(); ++iy)
            for (int jy = iy + 1; jy < (int)(yc).size(); ++jy)
              if (yc[jy] - yc[iy] > 1) {
                vp.push_back(make_pair(make_pair(xc[ix], yc[iy]),
                                       make_pair(xc[jx], yc[jy])));
              }
    for (int i = 0; i < (int)(vp).size(); ++i)
      for (int j = 0; j < (int)(vp).size(); ++j) {
        check2(vp[i].first, vp[i].second, vp[j].first, vp[j].second);
      }
  }
  for (int i = n - 1; i > 0; --i) {
    for (int j = m - 1; j > 0; --j) {
      if (a[i][j] == '#' && a[i - 1][j] == '#' && a[i][j - 1] == '#') {
        check(top.first, top.second, i, j);
      }
    }
  }
  cout << "NO\n";
  return 0;
}
