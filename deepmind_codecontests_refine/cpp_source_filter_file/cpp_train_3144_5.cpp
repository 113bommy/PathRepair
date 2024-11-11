#include <bits/stdc++.h>
using namespace std;
const int Nmax = 3e5 + 5;
int n, a[Nmax];
int dep[Nmax];
int l[Nmax * 20], r[Nmax * 20], vl[Nmax * 20];
int aint[Nmax];
int id;
int update(int node, int st, int dr, int pos, int val) {
  if (st == dr) {
    ++id;
    vl[id] = val;
    return id;
  }
  if (pos <= ((st + dr) >> 1)) {
    ++id;
    int now = id;
    l[now] = update(l[node], st, ((st + dr) >> 1), pos, val);
    r[now] = r[node];
    return now;
  } else {
    ++id;
    int now = id;
    l[now] = l[node];
    r[now] = update(r[node], ((st + dr) >> 1) + 1, dr, pos, val);
    return now;
  }
}
int query(int node, int st, int dr, int pos) {
  if (st == dr) return vl[node];
  if (pos <= ((st + dr) >> 1))
    return query(l[node], st, ((st + dr) >> 1), pos);
  else
    return query(r[node], ((st + dr) >> 1) + 1, dr, pos);
}
void solve() {
  int i;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  aint[n + 1] = ++id;
  dep[n + 1] = 0;
  for (i = n; i; --i) {
    int x = query(aint[i + 1], 1, n, a[i]);
    if (x) {
      aint[i] = aint[x + 1];
      dep[i] = dep[x + 1] + 1;
      aint[i] = update(aint[i], 1, n, a[i], i);
    } else {
      dep[i] = 0;
      aint[i] = ++id;
      aint[i] = update(aint[i], 1, n, a[i], i);
    }
  }
  long long ans = 0;
  for (i = 1; i <= n; ++i) ans += dep[i];
  cout << ans << '\n';
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
