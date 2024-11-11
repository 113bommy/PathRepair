#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> ocr;
map<pair<int, int>, int>::iterator it;
vector<pair<int, int> > v[4 * 300005];
long long ans[300005], now;
int sx[2 * 300000 + 5], sy[2 * 300000 + 5], p[2 * 300000 + 5];
int* where[3 * 300005];
int value[3 * 300005], cnt;
int q, x, y;
void add(int s, int l, int r, int ql, int qr, pair<int, int> p) {
  if (l > qr || r < ql) return;
  if (ql <= l && r <= qr) {
    v[s].push_back(p);
    return;
  }
  add(s * 2, l, (l + r) / 2, ql, qr, p);
  add(s * 2 + 1, (l + r) / 2 + 1, r, ql, qr, p);
}
int find(int x) {
  while (x != p[x]) x = p[x];
  return x;
}
void change(int& a, int b) {
  where[++cnt] = &a;
  value[cnt] = a;
  a = b;
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (sx[x] + sy[x] < sx[y] + sy[y]) swap(x, y);
  long long dec = (long long)sx[x] * sy[x] + (long long)sx[y] * sy[y];
  long long inc = (long long)(sx[x] + sx[y]) * (sy[x] + sy[y]);
  now = now - dec + inc;
  change(p[y], x);
  change(sx[x], sx[x] + sx[y]);
  change(sy[x], sy[x] + sy[y]);
}
void dfs(int s, int l, int r) {
  int l_now = now;
  int l_top = cnt;
  int n = v[s].size();
  for (int i = 0; i < n; i++) merge(v[s][i].first, v[s][i].second + 300000);
  if (l == r)
    ans[l] = now;
  else
    dfs(s * 2, l, (l + r) / 2), dfs(s * 2 + 1, (l + r) / 2 + 1, r);
  while (cnt != l_top) *(where[cnt]) = value[cnt], cnt--;
  now = l_now;
}
int main() {
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &x, &y);
    pair<int, int> tmp = make_pair(x, y);
    if (ocr.count(tmp)) {
      add(1, 1, q, ocr[tmp], i - 1, tmp);
      ocr.erase(tmp);
    } else
      ocr[tmp] = i;
  }
  it = ocr.begin();
  while (it != ocr.end()) {
    add(1, 1, q, it->second, q, it->first);
    it++;
  }
  now = cnt = 0;
  for (int i = 1; i <= 300000; i++) {
    p[i] = i;
    p[i + 300000] = i + 300000;
    sx[i] = 1;
    sy[i + 300000] = 1;
  }
  dfs(1, 1, q);
  for (int i = 1; i <= q; i++) printf("%I64d\n", ans[i]);
  return 0;
}
