#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T &a) {
  return a * a;
}
int s[110000];
double ans;
int f[110000], n, m, w[110000], p[110000], x, y;
pair<int, int> v[110000];
vector<int> a[110000];
int get(int v) {
  if (p[v] == v) return v;
  return p[v] = get(p[v]);
}
void unite(int x, int y) {
  x = get(x), y = get(y);
  if (x == y) return;
  if (w[x] == w[y]) w[x]++;
  if (w[x] < w[y]) swap(x, y);
  s[x] += s[y];
  p[y] = x;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)n; i++)
    scanf("%d", &v[i].first), f[i] = v[i].first, v[i].second = i;
  sort(v, v + n);
  for (int i = 0; i < (int)m; i++)
    scanf("%d%d", &x, &y), x--, y--, a[x].push_back(y), a[y].push_back(x);
  for (int i = 0; i < (int)n; i++) p[i] = i, s[i] = 1;
  for (int i = n - 1; i >= 0; i--) {
    x = v[i].second;
    y = s[get(x)];
    for (int j = 0; j < (int)(int)a[x].size(); j++) {
      if (f[x] <= f[a[x][j]] && get(x) != get(a[x][j]))
        ans += 1.0 * v[i].first * y * s[get(a[x][j])], y += s[get(a[x][j])],
            unite(x, a[x][j]);
    }
  }
  printf("%.20lf\n", 2 * ans / 1.0 / n / (n - 1));
}
