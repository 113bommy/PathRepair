#include <bits/stdc++.h>
using namespace std;
int sortindex[20][500010];
pair<pair<int, int>, int> sa[500010];
int lcp[500010];
int n;
char s[500010];
vector<int> pos_string[2 * 500010];
vector<int> pos_sa[2 * 500010];
int pre[500010];
void buildSA() {
  int i, j;
  for (i = 0; i < n; ++i) sortindex[0][i] = s[i] - '(';
  for (i = 0; i < n; ++i) sa[i].second = i;
  for (i = 1; (1 << (i - 1)) < n; ++i) {
    for (j = 0; j < n; ++j) {
      sa[j].first.first = sortindex[i - 1][sa[j].second];
      if (sa[j].second + (1 << (i - 1)) < n)
        sa[j].first.second = sortindex[i - 1][sa[j].second + (1 << (i - 1))];
      else
        sa[j].first.second = -1;
    }
    sort(sa, sa + n);
    int cnt = 0;
    sortindex[i][sa[0].second] = 0;
    for (j = 1; j < n; ++j) {
      if (sa[j].first == sa[j - 1].first)
        sortindex[i][sa[j].second] = sortindex[i][sa[j - 1].second];
      else
        sortindex[i][sa[j].second] = ++cnt;
    }
  }
}
int findlcp(int x, int y) {
  int i;
  int ret = 0;
  for (i = 0; (1 << (i - 1)) < n; ++i)
    ;
  --i;
  for (; i >= 0; --i) {
    if (sortindex[i][x] == sortindex[i][y]) {
      ret += (1 << i);
      x += (1 << i);
      y += (1 << i);
      if (x >= n || y >= n) break;
    }
  }
  return ret;
}
void buildlcp() {
  int i;
  for (i = 1; i < n; ++i) lcp[i] = findlcp(sa[i - 1].second, sa[i].second);
}
int bit[2][500010];
inline void update(int i, int val, bool f) {
  while (i <= n) {
    bit[f][i] += val;
    i = i + (i & (-i));
  }
}
inline int query(int i, bool f) {
  int ret = 0;
  while (i) {
    ret += bit[f][i];
    i = i - (i & (-i));
  }
  return ret;
}
inline int query(int i, int j, bool f) {
  if (j < i) return 0;
  ++i;
  ++j;
  return query(j, f) - query(i - 1, f);
}
int main() {
  int i;
  scanf("%d", &n);
  scanf("%s", &s);
  buildSA();
  buildlcp();
  lcp[0] = 0;
  pre[0] = 0;
  for (i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1];
    if (s[i - 1] == '(')
      pre[i]++;
    else
      pre[i]--;
    pos_string[pre[i] + n].push_back(i - 1);
  }
  for (i = 0; i < n; ++i) pos_sa[pre[sa[i].second] + n].push_back(i);
  memset(bit[0], 0, sizeof(bit[0]));
  memset(bit[1], 0, sizeof(bit[1]));
  long long ans = 0;
  for (i = 0; i < 2 * n; ++i) {
    for (auto j : pos_string[i]) update(j + 1, 1, 0);
    for (auto j : pos_sa[i]) {
      int lo = sa[j].second, hi = n - 1, mid;
      while (lo < hi) {
        mid = (lo + hi) / 2;
        if (query(sa[j].second, mid, 1))
          hi = mid;
        else
          lo = mid + 1;
      }
      if (query(sa[j].second, lo, 1)) --lo;
      hi = min(lo, n - 1);
      lo = sa[j].second + lcp[j];
      ans = ans + query(lo, hi, 0);
    }
    for (auto j : pos_string[i]) {
      update(j + 1, -1, 0);
      update(j + 1, 1, 1);
    }
  }
  printf("%lld\n", ans);
}
