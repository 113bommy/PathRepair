#include <bits/stdc++.h>
using namespace std;
int l[100100];
int l1[100100];
int r[100100];
int v[100100];
int n;
struct nd {
  int x, b, i;
  bool operator<(const nd& z) const {
    if (x == z.x) return b < z.b;
    return x < z.x;
  }
};
nd st[200200];
pair<int, int> dp[540100];
int z[500100];
void build(int l = 1, int h = n, int p = 1) {
  if (l == h) {
    dp[p].first = 0;
    dp[p].second = l;
    return;
  }
  int m = (l + h) / 2;
  build(m + 1, h, 2 * p + 1);
  build(l, m, 2 * p);
  dp[p] = max(dp[2 * p], dp[2 * p + 1]);
}
void add(int a, int b, int x, int l = 1, int h = n, int p = 1) {
  if (a == l && b == h) {
    dp[p].first += x;
    z[p] += x;
    return;
  }
  if (z[p]) {
    dp[2 * p].first += z[p];
    dp[2 * p + 1].first += z[p];
    z[2 * p + 1] += z[p];
    z[2 * p] += z[p];
    z[p] = 0;
  }
  int m = (l + h) / 2;
  if (b <= m) {
    add(a, b, x, l, m, 2 * p);
  } else if (a > m) {
    add(a, b, x, m + 1, h, 2 * p + 1);
  } else {
    add(m + 1, b, x, m + 1, h, 2 * p + 1);
    add(a, m, x, l, m, 2 * p);
  }
  dp[p] = max(dp[2 * p], dp[2 * p + 1]);
}
pair<int, int> cal(int a, int b, int x = 0, int l = 1, int h = n, int p = 1) {
  if (a == l && b == h) {
    return dp[p];
  }
  if (z[p]) {
    dp[2 * p].first += z[p];
    dp[2 * p + 1].first += z[p];
    z[2 * p + 1] += z[p];
    z[2 * p] += z[p];
    z[p] = 0;
  }
  int m = (l + h) / 2;
  if (b <= m) {
    return cal(a, b, x, l, m, 2 * p);
  } else if (a > m) {
    return cal(a, b, x, m + 1, h, 2 * p + 1);
  } else {
    return max(cal(m + 1, b, x, m + 1, h, 2 * p + 1),
               cal(a, m, x, l, m, 2 * p));
  }
}
int main() {
  cin >> n;
  build();
  int k = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &l[i], &v[i], &r[i]);
    st[k].x = v[i];
    st[k].b = 0;
    st[k++].i = i;
    st[k].x = r[i];
    st[k].b = 1;
    st[k++].i = i;
    l1[i] = l[i];
  }
  sort(st, st + k);
  pair<int, pair<int, int> > res = make_pair(0, make_pair(0, 0));
  sort(l1 + 1, l1 + n + 1);
  for (int i = 0; i < k;) {
    if (st[i].b == 1) {
      int j;
      int e = upper_bound(l1 + 1, l1 + n + 1, v[st[i].i]) - l1 - 1;
      pair<int, int> t = cal(1, e);
      res = max(res, make_pair(t.first, make_pair(l1[t.second], st[i].x)));
      for (j = i; j < k; j++) {
        if (st[i].x != st[j].x) break;
        int s = lower_bound(l1 + 1, l1 + n + 1, l[st[j].i]) - l1;
        int e = upper_bound(l1 + 1, l1 + n + 1, v[st[j].i]) - l1 - 1;
        if (s <= e) add(s, e, -1);
        add(s, s, -n);
      }
      i = j;
    } else {
      int s = lower_bound(l1 + 1, l1 + n + 1, l[st[i].i]) - l1;
      int e = upper_bound(l1 + 1, l1 + n + 1, v[st[i].i]) - l1 - 1;
      if (s <= e) add(s, e, 1);
      i++;
    }
  }
  cout << res.first << endl;
  for (int i = 1; i <= n; i++) {
    if (v[i] >= res.second.first && v[i] <= res.second.second &&
        l[i] <= res.second.first && r[i] >= res.second.second)
      printf("%d ", i);
  }
  return 0;
}
