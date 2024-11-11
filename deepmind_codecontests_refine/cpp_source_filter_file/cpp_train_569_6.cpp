#include <bits/stdc++.h>
using namespace std;
const int maxn = 101010;
struct piece {
  int x, h, num;
} a[maxn];
bool cmp(const piece &a, const piece &b) { return a.x < b.x; }
int ans[maxn], t[maxn * 8], n, s[maxn * 3];
vector<int> v;
int lsh(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
int ask(int i, int l, int r, int x, int y) {
  if (y < l || r < x) return 0;
  if (x <= l && r <= y) return t[i];
  int m = (l + r) / 2;
  return max(ask(i * 2, l, m, x, y), ask(i * 2 + 1, m + 1, r, x, y));
}
void add(int i, int l, int r, int p, int dt) {
  if (p < l || r < p) return;
  if (p == l && l == r) {
    t[i] = max(t[i], dt);
    return;
  }
  int m = (l + r) / 2;
  add(i * 2, l, m, p, dt);
  add(i * 2 + 1, m + 1, r, p, dt);
  t[i] = max(t[i * 2], t[i * 2 + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].h);
    a[i].num = i;
    v.push_back(a[i].x);
    v.push_back(a[i].x + 1);
    v.push_back(a[i].h + a[i].x - 1);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int MM = v.size();
  for (int i = 1; i <= n; ++i) s[lsh(a[i].x)] = 1;
  for (int i = 1; i <= MM; ++i) s[i] += s[i - 1];
  sort(a + 1, a + n + 1, cmp);
  for (int i = n; i > 0; --i) {
    int now = ask(1, 1, MM, lsh(a[i].x + 1), lsh(a[i].x + a[i].h - 1));
    int here = lsh(a[i].x);
    if (now == 0) now = here;
    add(1, 1, MM, here, now);
    ans[a[i].num] = s[now] - s[here - 1];
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
