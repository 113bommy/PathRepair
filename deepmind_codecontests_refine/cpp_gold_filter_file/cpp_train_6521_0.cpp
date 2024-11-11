#include <bits/stdc++.h>
using namespace std;
vector<long long> cnt;
vector<long long> st1, st2, v;
int n, m;
void build(int id, int l, int r) {
  if (l == r) {
    st1[id] = v[l];
    st2[id] = v[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * id + 1, l, mid);
  build(2 * id + 2, mid + 1, r);
  st1[id] = st1[2 * id + 1] + st1[2 * id + 2];
  st2[id] = max(st2[2 * id + 1], st2[2 * id + 2]);
}
void update(int low, int high, int id, int l, int r) {
  if (l > high || r < low) return;
  if (st2[id] <= 2) return;
  if (l == r) {
    v[l] = cnt[v[l]];
    st1[id] = v[l];
    st2[id] = v[l];
    return;
  }
  int mid = (l + r) / 2;
  update(low, high, 2 * id + 1, l, mid);
  update(low, high, 2 * id + 2, mid + 1, r);
  st1[id] = st1[2 * id + 1] + st1[2 * id + 2];
  st2[id] = max(st2[2 * id + 1], st2[2 * id + 2]);
}
long long query(int low, int high, int id, int l, int r) {
  if (l > high || r < low) return 0;
  if (l >= low && r <= high) return st1[id];
  int mid = (l + r) / 2;
  return query(low, high, 2 * id + 1, l, mid) +
         query(low, high, 2 * id + 2, mid + 1, r);
}
void solve(int test) {
  cin >> n >> m;
  st1.resize(4 * n);
  st2.resize(4 * n);
  v.resize(n);
  long long i, j;
  for (i = 0; i < n; i++) cin >> v[i];
  build(0, 0, n - 1);
  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;
    if (t == 1) {
      update(l, r, 0, 0, n - 1);
    } else {
      long long ans = query(l, r, 0, 0, n - 1);
      cout << ans << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cnt.resize(1e6 + 5, 1);
  for (int i = 2; i <= 1e6; i++) {
    for (int j = i; j <= 1e6; j += i) cnt[j]++;
  }
  int t = 1;
  for (int x = 1; x <= t; x++) {
    solve(x);
  }
  return 0;
}
