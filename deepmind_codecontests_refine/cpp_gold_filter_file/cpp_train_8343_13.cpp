#include <bits/stdc++.h>
using namespace std;
const int N = 200004;
long long t[4 * N];
long long d[4 * N];
void upd(int v, long long x) {
  t[v] += x;
  d[v] += x;
}
void push(int v) {
  if (d[v]) {
    upd(2 * v + 1, d[v]);
    upd(2 * v + 2, d[v]);
    d[v] = 0;
  }
}
void upd(int v, int l, int r, long long x, int tl = 0, int tr = N) {
  if (r <= tl || tr <= l) {
    return;
  } else if (l <= tl && tr <= r) {
    upd(v, x);
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    upd(2 * v + 1, l, r, x, tl, tm);
    upd(2 * v + 2, l, r, x, tm, tr);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
}
long long get(int v, int l, int r, int tl = 0, int tr = N) {
  if (r <= tl || tr <= l) {
    return 0;
  } else if (l <= tl && tr <= r) {
    return t[v];
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    return max(get(2 * v + 1, l, r, tl, tm), get(2 * v + 2, l, r, tm, tr));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<tuple<int, int, int>> race;
  vector<vector<int>> here(n + 1);
  for (int i = 0; i < m; i++) {
    int l, r, p;
    cin >> l >> r >> p;
    race.emplace_back(l, r, p);
    here[r].push_back(i);
  }
  vector<long long> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    upd(0, i, i + 1, dp[i - 1]);
    upd(0, 0, i, -a[i]);
    for (int t : here[i]) {
      int l = get<0>(race[t]);
      int p = get<2>(race[t]);
      upd(0, 0, l, p);
    }
    dp[i] = max(0ll, get(0, 0, i + 1));
  }
  cout << dp[n] << '\n';
  return 0;
}
