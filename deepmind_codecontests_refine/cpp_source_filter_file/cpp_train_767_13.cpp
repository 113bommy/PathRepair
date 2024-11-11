#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - '0';
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int mo = 1000000007;
template <class T>
T pow(T a, T b, int c = mo) {
  T res = 1;
  for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % mo)
    if (b & i) res = 1LL * res * a % mo;
  return res;
}
const int N = 3010;
int f[2 * N * N];
int n, m;
bool a[N][2 * N];
int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {1, 0, -1, 1, -1, 1, 0, -1};
int id(int x, int y) { return (x - 1) * 2 * m + y; }
pair<int, int> r[N * 3];
int idx;
int get(int u) {
  r[++idx] = std::make_pair(u, f[u]);
  if (u == f[u]) return u;
  f[u] = get(f[u]);
  return f[u];
}
void merge(int x, int y) {
  int s = id(x, y);
  for (int i = (0); i <= (7); ++i) {
    int xx = x + dirx[i], yy = y + diry[i];
    if (yy == 0) yy = 2 * m;
    if (yy > 2 * m) yy = 1;
    if (!a[xx][yy]) continue;
    int v = get(id(xx, yy));
    int u = get(s);
    if (v != u) f[v] = u;
  }
}
void resume() {
  for (int i = (idx); i >= (1); --i) f[r[i].first] = r[i].second;
}
int ans = 0;
int main() {
  int q;
  read(&n);
  read(&m);
  read(&q);
  if (m == 1) {
    puts("0");
    return 0;
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (2 * m); ++j) f[id(i, j)] = id(i, j);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    idx = 0;
    a[x][y] = a[x][y + m] = 1;
    merge(x, y);
    merge(x, y + m);
    if (get(id(x, y)) == get(id(x, y + m))) {
      a[x][y] = a[x][y + m] = 0;
      resume();
      continue;
    }
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
