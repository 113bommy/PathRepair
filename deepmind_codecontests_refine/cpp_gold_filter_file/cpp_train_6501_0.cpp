#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
const int maxm = 320;
deque<int> d[maxm + 1];
int n, q, num[maxm][maxn];
int query(int l, int x) {
  if (l == 0) {
    return 0;
  }
  int i = 1, ret = 0, ind = 0;
  while ((i - 1) * maxm <= n && ind + (int)d[i].size() <= l) {
    ret += num[i][x];
    ind += d[i].size();
    i++;
  }
  ++ind;
  for (deque<int>::iterator j = d[i].begin(); j != d[i].end() && ind <= l;
       ++j, ++ind) {
    if (*j == x) {
      ++ret;
    }
  }
  return ret;
}
void modify(int l, int r) {
  if (l == r) {
    return;
  }
  int i = 1, ind = 0;
  while ((i - 1) * maxm <= n && ind + (int)d[i].size() < l) {
    ind += d[i].size();
    i++;
  }
  int li = i, lp = l - ind - 1;
  while ((i - 1) * maxm <= n && ind + (int)d[i].size() < r) {
    ind += d[i].size();
    i++;
  }
  int rx = d[i][r - ind - 1];
  d[i].erase(d[i].begin() + r - ind - 1);
  d[li].insert(d[li].begin() + lp, rx);
  --num[i][rx];
  ++num[li][rx];
}
void debug() {
  for (int i = 1; (i - 1) * maxm <= n; ++i) {
    for (deque<int>::iterator k = d[i].begin(); k != d[i].end(); ++k) {
      printf("%d ", *k);
    }
  }
  printf("\n");
}
int decode(int x, int last) { return (x + last - 1) % n + 1; }
int main() {
  scanf("%d", &n);
  int x = (n + maxm - 1) / maxm;
  for (int i = 1, t; i <= x; ++i) {
    for (int j = (i - 1) * maxm + 1; j <= i * maxm && j <= n; ++j) {
      scanf("%d", &t);
      d[i].push_back(t);
      ++num[i][t];
    }
  }
  scanf("%d", &q);
  int last = 0;
  while (q--) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    l = decode(l, last);
    r = decode(r, last);
    if (l > r) {
      swap(l, r);
    }
    if (t == 2) {
      int v;
      scanf("%d", &v);
      v = decode(v, last);
      printf("%d\n", last = query(r, v) - query(l - 1, v));
    } else {
      modify(l, r);
    }
  }
  return 0;
}
