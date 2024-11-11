#include <bits/stdc++.h>
using namespace std;
const int maxn = 262144;
int n;
int t[maxn], x[maxn], y[maxn];
vector<int> X;
int l[maxn], r[maxn], d[maxn], N;
set<pair<int, int> > s[maxn * 2];
set<int> bag;
int dad(int i) {
  if (d[i] == i) return i;
  return d[i] = dad(d[i]);
}
void go(int seg, int ls, int rs, int x) {
  if (x <= ls or rs <= 0) return;
  if (0 <= ls and rs <= x) {
    for (auto it = s[seg].lower_bound({x + 1, 0}); it != s[seg].end(); it++)
      bag.insert(it->second);
    return;
  }
  int mid = (ls + rs) >> 1;
  go((seg + seg + 1), ls, mid, x);
  go((seg + seg + 2), mid, rs, x);
}
void fo(int seg, int ls, int rs, int i) {
  if (l[i] + 1 <= ls or rs <= l[i]) return;
  s[seg].erase({r[i], i});
  if (ls == rs - 1) return;
  int mid = (ls + rs) >> 1;
  fo((seg + seg + 1), ls, mid, i);
  fo((seg + seg + 2), mid, rs, i);
}
void so(int seg, int ls, int rs, int i) {
  if (l[i] + 1 <= ls or rs <= l[i]) return;
  s[seg].insert({r[i], i});
  if (ls == rs - 1) return;
  int mid = (ls + rs) >> 1;
  so((seg + seg + 1), ls, mid, i);
  so((seg + seg + 2), mid, rs, i);
}
void add(int a, int b) {
  l[N] = a;
  r[N] = b;
  d[N] = N;
  go(0, 0, maxn, a);
  go(0, 0, maxn, b);
  for (auto i : bag) {
    l[N] = min(l[N], l[i]);
    r[N] = max(r[N], r[i]);
    d[dad(i)] = N;
    fo(0, 0, maxn, i);
  }
  so(0, 0, maxn, N);
  N++;
  bag.clear();
}
void answer(int i, int j) {
  i = dad(i);
  j = dad(j);
  if (i == j or (l[j] < r[i] and r[i] < r[j]) or (l[j] < l[i] and l[i] < r[j]))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    if (t[i] == 1) {
      X.push_back(x[i]);
      X.push_back(y[i]);
    } else {
      x[i]--;
      y[i]--;
    }
  }
  sort(X.begin(), X.end());
  unique(X.begin(), X.end());
  for (int i = 0; i < n; i++)
    if (t[i] == 1) {
      x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
      y[i] = lower_bound(X.begin(), X.end(), y[i]) - X.begin();
    }
  for (int i = 0; i < n; i++)
    if (t[i] == 1)
      add(x[i], y[i]);
    else
      answer(x[i], y[i]);
  return 0;
}
