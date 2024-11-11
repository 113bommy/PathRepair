#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
const int gx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int gy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int p[18000111], n, m, q;
int gf(int x) { return x == p[x] ? x : (p[x] = gf(p[x])); }
pair<int, int> tmp[100];
int sz, ans;
bool land[3011][6011];
vector<int> v1, v2;
int main() {
  for (int i = 1; i <= 18000000; i++) p[i] = i;
  n = getnum(), m = getnum(), q = getnum();
  m = m * 2;
  for (int i = 1; i <= q; i++) {
    v1.clear();
    v2.clear();
    int x, y, id;
    x = getnum(), y = getnum();
    id = (x - 1) * m + y;
    sz = 0;
    for (int j = 0; j < 8; j++) {
      int nx = x + gx[j], ny = y + gy[j];
      if (ny < 1) ny += m >> 1;
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && land[nx][ny]) {
        v1.push_back(gf((nx - 1) * m + ny));
        tmp[sz++] = make_pair(id, (nx - 1) * m + ny);
      }
    }
    for (int j = 0; j < 8; j++) {
      int nx = x + gx[j], ny = y + m / 2 + gy[j];
      if (ny > m) ny -= m;
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && land[nx][ny]) {
        v2.push_back(gf((nx - 1) * m + ny));
        tmp[sz++] = make_pair(id + m / 2, (nx - 1) * m + ny);
      }
    }
    bool ok = 0;
    for (int j = 0; j < v1.size(); j++)
      for (int k = 0; k < v2.size(); k++)
        if (v1[j] == v2[k]) ok = 1;
    if (!ok && m != 2) {
      ans++;
      land[x][y] = 1, land[x][y + m / 2] = 1;
      for (int j = 0; j < sz; j++) p[gf(tmp[j].first)] = gf(tmp[j].second);
    }
  }
  putnum(ans), putendl();
  return 0;
}
