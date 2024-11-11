#include <bits/stdc++.h>
using namespace std;
bool area[1050][1050];
int tmp[1050][1050];
int sumup[1050][1050];
int sumleft[1050][1050];
int zblackx[10000];
int zblacky[10000];
struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
};
bool operator<(const pt &a, const pt &b) {
  return (a.x < b.x) || (a.x == b.x && (a.y < b.y));
}
pt black[10000];
inline int subsumup(int i, int j, int k) {
  if (j == 0) return sumup[k][i];
  return sumup[k][i] - sumup[j - 1][i];
}
inline int subsumleft(int i, int j, int k) {
  if (j == 0) return sumleft[i][k];
  return sumleft[i][k] - sumleft[i][j - 1];
}
inline bool correct(int i, int j, int k, int p) {
  return (k - i > 1 && p - j > 1 && subsumup(j, i, k) == k - i + 1 &&
          subsumup(p, i, k) == k - i + 1 && subsumleft(i, j, p) == p - j + 1 &&
          subsumleft(k, j, p) == p - j + 1);
}
struct rect {
  short a, b, c, d;
  rect() {}
  rect(short a, short b, short c, short d) : a(a), b(b), c(c), d(d) {}
};
rect r[3000000];
;
bool operator<(const rect &a, const rect &b) {
  return (a.c - a.a + 1) * 2 + (a.d - a.b + 1) * 2 <
         (b.c - b.a + 1) * 2 + (b.d - b.b + 1) * 2;
}
int main() {
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  int minx = (int)1e9;
  int miny = (int)1e9;
  int maxx = -(int)1e9;
  int maxy = -(int)1e9;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; j++) {
      area[i][j] = tmp[j] == '#';
      if (area[i][j]) {
        cnt++;
        minx = min(minx, i);
        miny = min(miny, j);
        maxx = max(maxx, i);
        maxy = max(maxy, j);
      }
    }
  }
  if (cnt > (n + m) * 4) {
    cout << "NO";
    return 0;
  }
  if (maxy - miny == 3 && cnt == (maxx - minx + 1) * (maxy - miny + 1)) {
    cout << "YES" << endl;
    cout << minx + 1 << ' ' << miny + 1 << ' ' << maxx + 1 << ' ' << miny + 3
         << endl;
    cout << minx + 1 << ' ' << miny + 2 << ' ' << maxx + 1 << ' ' << miny + 4
         << endl;
    return 0;
  }
  if (maxx - minx == 3 && cnt == (maxx - minx + 1) * (maxy - miny + 1)) {
    cout << "YES" << endl;
    cout << minx + 1 << ' ' << miny + 1 << ' ' << maxx << ' ' << maxy + 1
         << endl;
    cout << minx + 2 << ' ' << miny + 1 << ' ' << maxx + 1 << ' ' << maxy + 1
         << endl;
    return 0;
  }
  cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (area[i][j] &&
          ((i > 0 && j > 0 && area[i - 1][j] && area[i][j - 1]) ||
           (i < n - 1 && j < m - 1 && area[i][j + 1] && area[i + 1][j])))
        black[cnt++] = pt(i, j);
  sort(black, black + cnt);
  int cnt3 = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (area[i][j]) zblackx[cnt3] = i, zblacky[cnt3++] = j;
  for (int i = 0; i < n; i++) {
    sumleft[i][0] = area[i][0];
    for (int j = 1; j < m; j++) sumleft[i][j] = sumleft[i][j - 1] + area[i][j];
  }
  for (int i = 0; i < m; i++) {
    sumup[0][i] = area[0][i];
    for (int j = 1; j < n; j++) sumup[j][i] = sumup[j - 1][i] + area[j][i];
  }
  bool cont = 1;
  int cnt2 = 0;
  for (int i = 0; i < cnt - 1 && cnt2 < 1000000; i++) {
    if (correct(black[i].x, black[i].y, black[cnt - 1].x, black[cnt - 1].y)) {
      r[cnt2++] =
          rect(black[i].x, black[i].y, black[cnt - 1].x, black[cnt - 1].y);
    }
    if (correct(black[0].x, black[0].y, black[i].x, black[i].y)) {
      r[cnt2++] = rect(black[0].x, black[0].y, black[i].x, black[i].y);
    }
    for (int j = cnt - 1; j > i && cnt2 < 1000000; j--)
      if (correct(black[i].x, black[i].y, black[j].x, black[j].y)) {
        r[cnt2++] = rect(black[i].x, black[i].y, black[j].x, black[j].y);
      }
  }
  sort(r, r + cnt2);
  reverse(r, r + cnt2);
  int BIGS = 1000;
  int f = 1;
  for (int i = 0; i < min(BIGS, cnt2); i++)
    for (int j = i; j < min(BIGS, cnt2); j++) {
      f++;
      for (int k = r[i].a; k <= r[i].c; k++)
        tmp[k][r[i].b] = tmp[k][r[i].d] = f;
      for (int k = r[i].b; k <= r[i].d; k++)
        tmp[r[i].a][k] = tmp[r[i].c][k] = f;
      for (int k = r[j].a; k <= r[j].c; k++)
        tmp[k][r[j].b] = tmp[k][r[j].d] = f;
      for (int k = r[j].b; k <= r[j].d; k++)
        tmp[r[j].a][k] = tmp[r[j].c][k] = f;
      bool ok = 1;
      for (int k = 0; k < cnt3; k++)
        if (tmp[zblackx[k]][zblacky[k]] != f) {
          ok = 0;
          break;
        }
      if (ok) {
        cout << "YES" << endl;
        cout << r[i].a + 1 << ' ' << r[i].b + 1 << ' ' << r[i].c + 1 << ' '
             << r[i].d + 1 << endl;
        cout << r[j].a + 1 << ' ' << r[j].b + 1 << ' ' << r[j].c + 1 << ' '
             << r[j].d + 1 << endl;
        return 0;
      }
    }
  cout << "NO";
  return 0;
}
