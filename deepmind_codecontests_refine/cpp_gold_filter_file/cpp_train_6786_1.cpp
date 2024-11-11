#include <bits/stdc++.h>
using namespace std;
long long n, m, kq, kqx, kqy, t, b[1000005], ax[1000005], ct;
map<int, int> mp;
pair<long long, int> x;
pair<pair<long long, int>, long long> st[4000005];
pair<pair<int, int>, long long> a[500005];
void build(int id, int l, int r) {
  if (l > r) return;
  if (l == r) {
    st[id].first.second = l;
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
}
void down(int id) {
  long long gt = st[id].second;
  st[id].second = 0;
  st[id * 2].first.first += gt;
  st[id * 2].second += gt;
  st[id * 2 + 1].first.first += gt;
  st[id * 2 + 1].second += gt;
}
void update(int id, int l, int r, int u, int v, long long gt) {
  if (l > r || l > v || r < u) return;
  if (u <= l && r <= v) {
    st[id].first.first += gt;
    st[id].second += gt;
    return;
  }
  int mid = (l + r) / 2;
  down(id);
  update(id * 2, l, mid, u, v, gt);
  update(id * 2 + 1, mid + 1, r, u, v, gt);
  st[id].first = max(st[id * 2].first, st[id * 2 + 1].first);
}
pair<long long, int> get(int id, int l, int r, int u, int v) {
  if (l > r || l > v || r < u) return {-1000000000, -1};
  if (l >= u && r <= v) return st[id].first;
  int mid = (l + r) / 2;
  down(id);
  return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  m = n * 2;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    if (a[i].first.second > a[i].first.first)
      swap(a[i].first.second, a[i].first.first);
    b[i] = a[i].first.second;
    b[i + n] = a[i].first.first;
  }
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; ++i) {
    if (i == 1 || b[i] != b[i - 1]) {
      mp[b[i]] = ++t;
      ax[t] = b[i];
    }
  }
  build(1, 1, t);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].first.first = mp[a[i].first.first];
    a[i].first.second = mp[a[i].first.second];
  }
  ct = 1;
  for (int i = 1; i <= t; ++i) {
    update(1, 1, t, i, i, ax[i]);
    while (ct <= n && a[ct].first.first <= i) {
      update(1, 1, t, 1, a[ct].first.second, a[ct].second);
      ct++;
    }
    x = get(1, 1, t, 1, i);
    x.first = x.first - ax[i];
    if (x.first > kq) {
      kq = x.first;
      kqx = ax[x.second];
      kqy = ax[i];
    }
  }
  cout << kq << '\n';
  if (kq == 0)
    for (int i = 0; i <= 1000001; ++i)
      if (mp[i] == 0) kqx = kqy = i;
  cout << kqx << ' ' << kqx << ' ' << kqy << ' ' << kqy;
  return 0;
}
