#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
int n, m;
bool vis[MAXN];
vector<int> idx, X, Y;
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
int query(int x, int y) {
  static int d;
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &d);
  return d;
}
void solve(int L, int R) {
  if (L > R) return;
  int mid = (L + R) / 2, d, pos = -INF;
  d = query(mid, mid);
  if (!d)
    return idx.push_back(mid), solve(L, mid - 1), solve(mid + 1, R), void();
  if (mid - d >= L && !query(mid - d, mid - d))
    idx.push_back(mid - d), pos = mid - d;
  if (mid + d <= R && !query(mid + d, mid + d))
    idx.push_back(mid + d), pos = mid + d;
  if (pos == -INF) return;
  solve(L, pos - 1), solve(pos + 1, R);
}
void calc() {
  int pos = 0;
  for (auto x : idx)
    if (0 <= x && x <= (int)1e4) vis[x] = true;
  while (vis[pos]) pos++;
  for (auto x : idx) {
    if (!query(x, pos)) X.push_back(x);
    if (!query(pos, x)) Y.push_back(x);
  }
  printf("1 %ld %ld\n", X.size(), Y.size());
  for (auto x : X) printf("%d ", x);
  putchar('\n');
  for (auto x : Y) printf("%d ", x);
  putchar('\n');
}
signed main() {
  solve(-1e8, 1e8);
  calc();
  return 0;
}
