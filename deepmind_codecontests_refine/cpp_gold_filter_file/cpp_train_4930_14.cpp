#include <bits/stdc++.h>
using namespace std;
int n, m, a[1100000], p[1100000];
pair<int, int> r[1100000];
double t[2 * (1 << 20)];
double get(int x) {
  x += (1 << 20);
  double ans = 0;
  while (x) {
    ans += t[x];
    x /= 2;
  }
  return ans;
}
void add(int x, int y, double delta) {
  x += (1 << 20);
  y += (1 << 20);
  t[x] += delta;
  if (x < y) t[y] += delta;
  while (x + 1 < y) {
    if (x % 2 == 0) t[x + 1] += delta;
    if (y % 2) t[y - 1] += delta;
    x /= 2;
    y /= 2;
  }
}
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  p[x] = y;
  r[y] = pair<int, int>(min(r[x].first, r[y].first),
                        max(r[x].second, r[y].second));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<pair<int, int> > s;
  for (int i = 0; i < n; i++) s.push_back(pair<int, int>(a[i], i));
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++) p[i] = -1;
  for (int i = s.size() - 1; i >= 0; i--) {
    int x = s[i].second;
    p[x] = x;
    r[x] = pair<int, int>(x, x);
    int left = 0, right = 0;
    if (x && p[x - 1] >= 0) {
      left = x - r[find(x - 1)].first;
    }
    if (x + 1 < n && p[x + 1] >= 0) {
      right = r[find(x + 1)].second - x;
    }
    if (left > right) swap(left, right);
    for (int j = 0; j <= left; j++) {
      add(j + 1, j + right + 1, s[i].first);
    }
    if (x && p[x - 1] >= 0) join(x - 1, x);
    if (x + 1 < n && p[x + 1] >= 0) join(x, x + 1);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int tmp;
    scanf("%d", &tmp);
    printf("%0.9lf\n", get(tmp) / (n - tmp + 1));
  }
}
