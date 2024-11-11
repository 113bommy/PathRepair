#include <bits/stdc++.h>
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 2e5 + 7;
int n, m;
int aa[N], sta[N], a[N], b[N], sta2[N];
std::pair<int, int> sa[N], sb[N];
std::vector<std::pair<int, int> > v[N], v2[N];
inline int dis(int x, int y) {
  if (x > y) std::swap(x, y);
  return std::min(y - x, x + n - y);
}
inline int ff(int x) { return std::upper_bound(b + 1, b + m + 1, x) - b - 1; }
inline int f2(int x) { return std::lower_bound(a + 1, a + m + 1, x) - a; }
inline void work() {
  std::sort(sa + 1, sa + m + 1);
  std::sort(sb + 1, sb + m + 1);
  for (int i = 1; i <= m; ++i) a[i] = sa[i].first, b[i] = sb[i].first;
  int n2 = n / 2;
  for (int i = 1; i <= m; ++i) {
    int p1 = a[i] - n2 - 1, p2 = a[i] - 1, p3 = a[i] + n / 2, p4 = n;
    p1 = ff(p1) % m, p2 = ff(p2) % m, p3 = ff(p3) % m, p4 = ff(p4) % m;
    if (p1 != p2) v[(p1 - i + 1 + m) % m].push_back(std::pair<int, int>(i, 1));
    if (p2 != p3) v[(p2 - i + 1 + m) % m].push_back(std::pair<int, int>(i, 2));
    if (p3 != p4) v[(p3 - i + 1 + m) % m].push_back(std::pair<int, int>(i, 3));
    if (p4 != p1) v[(p4 - i + 1 + m) % m].push_back(std::pair<int, int>(i, 0));
  }
  for (int i = 1; i <= m; ++i) {
    int p1 = b[i] - n2, p2 = b[i] + 1, p3 = b[i] + n / 2 + 1, p4 = 1;
    p1 = f2(p1) % m, p2 = f2(p2) % m, p3 = f2(p3) % m, p4 = f2(p4) % m;
    if (p1 != p4)
      v2[(-p1 + i + 1 + m) % m].push_back(std::pair<int, int>(i, 3));
    if (p2 != p1)
      v2[(-p2 + i + 1 + m) % m].push_back(std::pair<int, int>(i, 2));
    if (p3 != p2)
      v2[(-p3 + i + 1 + m) % m].push_back(std::pair<int, int>(i, 1));
    if (p4 != p3)
      v2[(-p4 + i + 1 + m) % m].push_back(std::pair<int, int>(i, 0));
  }
  long long sum_a[4] = {0}, sum_b[4] = {0}, pos, cnt[4] = {0}, cnt2[4] = {0};
  long long ans = 0x7fffffffffffffff;
  memset(sta, -1, sizeof(sta));
  for (int i = 1; i <= m; ++i) {
    int x = i, y;
    if (b[i] < a[i] - n2)
      y = 0;
    else if (b[i] < a[i])
      y = 1;
    else if (b[i] <= a[i] + n2)
      y = 2;
    else
      y = 3;
    sum_a[y] += a[x], sum_b[y] += b[x], cnt[y] += 1, cnt2[y] += 1;
    sta[x] = y, sta2[x] = y;
  }
  for (int i = 1; i <= m; ++i) {
    if (i)
      smin(ans, sum_b[0] + n * cnt[0] - sum_a[0] + sum_a[1] - sum_b[1] +
                    sum_b[2] - sum_a[2] + sum_a[3] + n * cnt[3] - sum_b[3]) &&
          (pos = i);
    if (cnt[0] != cnt2[0] || cnt[1] != cnt2[1] || cnt[2] != cnt2[2] ||
        cnt[3] != cnt2[3]) {
      return;
    }
    for (std::pair<int, int> j : v[i]) {
      int x = j.first, &y = sta[x];
      if (~y) sum_a[y] -= a[x], cnt[y] -= 1;
      y = j.second;
      sum_a[y] += a[x], cnt[y] += 1;
    }
    for (std::pair<int, int> j : v2[i]) {
      int x = j.first, &y = sta2[x];
      if (~y) sum_b[y] -= b[x], cnt2[y] -= 1;
      y = j.second;
      sum_b[y] += b[x], cnt2[y] += 1;
    }
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= m; ++i)
    aa[sa[i].second] = sb[(i + pos - 2) % m + 1].second;
  for (int i = 1; i <= m; ++i) printf("%d%c", aa[i], " \n"[i == n]);
}
inline void init() {
  read(n), read(m);
  for (int i = 1; i <= m; ++i) read(sa[i].first), sa[i].second = i;
  for (int i = 1; i <= m; ++i) read(sb[i].first), sb[i].second = i;
}
int main() {
  init();
  work();
  fclose(stdin), fclose(stdout);
  return 0;
}
