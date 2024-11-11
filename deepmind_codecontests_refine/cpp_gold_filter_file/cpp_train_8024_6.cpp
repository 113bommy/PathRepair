#include <bits/stdc++.h>
using namespace std;
const int pod = (1 << 17);
const int nax = 100111;
int n, m, X;
int a[nax];
int type, l, r;
struct node {
  long long ans = 0;
  vector<pair<int, int>> pref, suf;
  node() {
    ans = 0;
    pref.clear();
    suf.clear();
  }
} t[2 * pod];
node lacz(const node a, const node b) {
  node c = node();
  c.ans = a.ans + b.ans;
  int wsk = (int)b.pref.size() - 1;
  int sum = 0;
  if ((int)b.pref.size()) sum = b.pref.back().second;
  for (int i = 0; i < (int)a.suf.size(); ++i) {
    while (wsk > 0 && (a.suf[i].first | b.pref[wsk - 1].first) >= X) {
      wsk -= 1;
      sum += b.pref[wsk].second;
    }
    if (wsk >= 0 && (a.suf[i].first | b.pref[wsk].first) >= X)
      c.ans += (long long)a.suf[i].second * sum;
  }
  int val = -1;
  int ile = 0;
  for (auto it : a.pref) {
    if (val != -1 && (val | it.first) != val) {
      c.pref.push_back(make_pair(val, ile));
      ile = 0;
    }
    val = max(val, 0);
    val |= it.first;
    ile += it.second;
  }
  for (auto it : b.pref) {
    if (val != -1 && (val | it.first) != val) {
      c.pref.push_back(make_pair(val, ile));
      ile = 0;
    }
    val |= it.first;
    ile += it.second;
  }
  c.pref.push_back(make_pair(val, ile));
  val = -1;
  ile = 0;
  for (auto it : b.suf) {
    if (val != -1 && (val | it.first) != val) {
      c.suf.push_back(make_pair(val, ile));
      ile = 0;
    }
    val = max(val, 0);
    val |= it.first;
    ile += it.second;
  }
  for (auto it : a.suf) {
    if (val != -1 && (val | it.first) != val) {
      c.suf.push_back(make_pair(val, ile));
      ile = 0;
    }
    val |= it.first;
    ile += it.second;
  }
  c.suf.push_back(make_pair(val, ile));
  return c;
}
void mod(int x, int c) {
  x += pod;
  t[x].pref.clear();
  t[x].suf.clear();
  t[x].ans = (c >= X);
  t[x].pref.push_back(make_pair(c, 1));
  t[x].suf.push_back(make_pair(c, 1));
  x /= 2;
  while (x) {
    t[x] = lacz(t[2 * x], t[2 * x + 1]);
    x /= 2;
  }
}
node query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
  if (x <= l && r <= y) return t[u];
  int m = (l + r) / 2;
  node res = node();
  if (x <= m) res = query(x, y, 2 * u, l, m);
  if (m < y) res = lacz(res, query(x, y, 2 * u + 1, m + 1, r));
  return res;
}
int main() {
  scanf("%d %d %d", &n, &m, &X);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= 2 * pod - 1; ++i) t[i] = node();
  for (int i = 1; i <= n; ++i) mod(i, a[i]);
  while (m--) {
    scanf("%d %d %d", &type, &l, &r);
    if (type == 1)
      mod(l, r);
    else {
      printf("%lld\n", query(l, r).ans);
    }
  }
  return 0;
}
