#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)2e5 + 7;
struct data {
  int v, t, id;
  data(){};
  data(int _v, int _t, int _id = 0) { v = _v, t = _t, id = _id; }
  data operator+(const data &p2) { return data(v + p2.v, p2.t, id); }
  const bool operator<(const data &p2) const {
    if (v != p2.v)
      return v < p2.v;
    else
      return t > p2.t;
  }
  const bool operator>(const data &p2) const {
    if (v != p2.v)
      return v > p2.v;
    else
      return t < p2.t;
  }
} st[MXN];
int b[MXN];
int ans[MXN];
int main(void) {
  int n, k, m, a;
  scanf("%d %d %d %d", &n, &k, &m, &a);
  for (int i = 1; i < a + 1; ++i) scanf("%d", b + i);
  for (int i = 1; i < n + 1; ++i) st[i] = data(0, 0, i);
  for (int i = 1; i < a + 1; ++i) st[b[i]] = st[b[i]] + data(1, i);
  if (m == a) {
    sort(st + 1, st + n + 1);
    for (int i = n; i >= n - k + 1; --i) {
      if (st[i].v == 0) break;
      ans[st[i].id] = 1;
    }
    for (int i = 1; i < n + 1; ++i)
      if (!ans[i]) ans[i] = 3;
    for (int i = 1; i < n + 1; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
  }
  int la = m - a;
  for (int i = 1; i < n + 1; ++i) {
    data v = st[i] + data(la, m);
    int num = 0;
    for (int j = 1; j < n + 1; ++j) {
      if (i == j) continue;
      if (st[j] > v) num++;
    }
    if (num >= k) {
      ans[i] = 3;
      continue;
    }
    int sum = 0;
    num = 0;
    vector<int> buf;
    for (int j = 1; j < n + 1; ++j) {
      if (i == j) continue;
      if (st[j] > st[i])
        num++;
      else
        buf.push_back(st[i].v - st[j].v + 1);
    }
    sort(begin(buf), end(buf), greater<int>());
    while (num < k && !buf.empty()) {
      num++;
      sum += buf.back();
      buf.pop_back();
    }
    if (sum <= la && num >= k)
      ans[i] = 2;
    else if (st[i].v)
      ans[i] = 1;
    else
      ans[i] = 2;
  }
  for (int i = 1; i < n + 1; ++i) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
