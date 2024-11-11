#include <bits/stdc++.h>
const int md = 1000000007;
inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}
const int N = 200000;
int t, n, s[N], ord[N << 1], suf[N], b[N << 1];
std::pair<int, int> a[N];
bool s_cmp(int x, int y) { return a[x].first < a[y].first; }
void inc(int i, int d) {
  while (i < 2 * n) {
    b[i] = add(b[i], d);
    i |= i + 1;
  }
}
int get(int i) {
  int s = 0;
  while (i >= 0) {
    s = add(s, b[i]);
    i = (i & i + 1) - 1;
  }
  return s;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    --a[i].first;
    --a[i].second;
    ord[a[i].first] = ord[a[i].second] = i;
  }
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d", s + i);
    --s[i];
  }
  std::sort(s, s + t, s_cmp);
  for (int i = t - 1; i >= 0; --i) {
    if (i == t - 1 || a[s[i]].second > a[suf[i + 1]].second)
      suf[i] = s[i];
    else
      suf[i] = suf[i + 1];
  }
  std::vector<std::pair<int, int> > qr;
  int last = 0;
  for (int i = 0; i < t;) {
    qr.push_back(std::make_pair(a[suf[i]].second, last));
    last = a[suf[i]].first + 1;
    while (i < t && a[s[i]].first < last) ++i;
  }
  std::sort(qr.begin(), qr.end());
  int ans = 0;
  for (int i = 0, j = 0; i < n << 1; ++i) {
    if (a[ord[i]].second == i) {
      while (j < (int)qr.size() && qr[j].first == i) {
        ans = add(ans, get(qr[j].second) + 1);
        ++j;
      }
      int val = get(a[ord[i]].first) + 1;
      inc(0, val);
      inc(a[ord[i]].first + 1, sub(0, -val));
    }
  }
  printf("%d\n", ans);
  return 0;
}
