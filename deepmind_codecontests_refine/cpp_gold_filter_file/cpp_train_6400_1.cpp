#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int a, b, c, d[500007], n, m, T[500007 * 4], tt[500007];
map<int, int> mk;
pair<pair<int, int>, int> p[500007];
void form_tree(int l, int r, int v) {
  if (l == r) {
    T[v] = 2 * 1000000009;
    return;
  }
  form_tree(l, (l + r) / 2, v * 2);
  form_tree((l + r) / 2 + 1, r, v * 2 + 1);
  T[v] = min(T[v * 2], T[v * 2 + 1]);
}
void upd(int x, int y, int l, int r, int v) {
  if (l == r) {
    T[v] = min(T[v], y);
    return;
  }
  if (x <= (l + r) / 2)
    upd(x, y, l, (l + r) / 2, v * 2);
  else
    upd(x, y, (l + r) / 2 + 1, r, v * 2 + 1);
  T[v] = min(T[v * 2], T[v * 2 + 1]);
}
int bul(int x, int y, int l, int r, int v) {
  if (x > r || y < l) return 2 * 1000000009;
  if (x <= l && r <= y) return T[v];
  return min(bul(x, y, l, (l + r) / 2, v * 2),
             bul(x, y, (l + r) / 2 + 1, r, v * 2 + 1));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &p[i].first.second, &p[i].first.first), p[i].second = i;
  sort(p, p + m + 1);
  b = 1;
  form_tree(1, n, 1);
  for (int i = 1; i <= m; i++) {
    while (b <= p[i].first.first) {
      if (mk[d[b]] > 0) upd(mk[d[b]], b - mk[d[b]], 1, n, 1);
      mk[d[b]] = b;
      b++;
    }
    tt[p[i].second] = bul(p[i].first.second, p[i].first.first, 1, n, 1);
  }
  for (int i = 1; i <= m; i++) {
    if (tt[i] == 2 * 1000000009)
      printf("%d\n", -1);
    else
      printf("%d\n", tt[i]);
  }
  return 0;
}
