#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAXN = 3e5 + 5;
int n, r, s;
pii a[MAXN];
vector<int> second;
int mx[MAXN * 8];
int ad[MAXN * 8];
void compress() {
  for (int(i) = 0; (i) < (n); ++(i)) {
    second.push_back(a[i].second);
  }
  sort((second).begin(), (second).end());
  second.resize(unique((second).begin(), (second).end()) - second.begin());
  for (int(i) = 0; (i) < (n); ++(i)) {
    a[i].second = lower_bound((second).begin(), (second).end(), a[i].second) -
                  second.begin();
  }
}
void push(int v) {
  if (ad[v] == 0) return;
  ad[v * 2 + 1] += ad[v];
  ad[v * 2 + 2] += ad[v];
  mx[v] += ad[v];
  ad[v] = 0;
}
void add(int v, int tl, int tr, int l, int r, int first) {
  if (l <= tl && tr <= r) {
    ad[v] += first;
    return;
  }
  if (r <= tl || tr <= l) return;
  push(v);
  int tm = tl + (tr - tl) / 2;
  add(v * 2 + 1, tl, tm, l, r, first);
  add(v * 2 + 2, tm, tr, l, r, first);
  mx[v] = max(mx[v * 2 + 1] + ad[v * 2 + 1], mx[v * 2 + 2] + ad[v * 2 + 2]);
}
int get() { return mx[0] + ad[0]; }
void add(int t, int k) {
  int lw = lower_bound((second).begin(), (second).end(), second[t] - s + 1) -
           second.begin();
  add(0, 0, MAXN * 2, lw, t + 1, k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> r;
  s = 2 * r - 1 + 2;
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> a[i].first >> a[i].second;
    tie(a[i].first, a[i].second) =
        make_tuple(a[i].first - a[i].second, a[i].first + a[i].second);
  }
  compress();
  sort(a, a + n, [&](const pii &a, const pii &b) { return a.first < b.first; });
  int res = 0;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    add(a[i].second, 1);
    while (a[i].first - a[j].first + 1 > s) {
      add(a[j].second, -1);
      j++;
    }
    res = max(res, get());
  }
  cout << res << endl;
}
