#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long fp(long long a, long long b) {
  if (b == 0) return 1;
  long long x = fp(a, b / 2);
  x = (x * x) % mod;
  if (b & 1) x = (x * a) % mod;
  return x;
}
const long long N = 1e5 + 5;
long long a[N];
struct node {
  long long x;
};
node merge(node a, node b) {
  node c;
  return c;
}
vector<long long> bit[4 * N];
void build(long long id, long long l, long long r) {
  if (l == r) {
    bit[id].push_back(a[l]);
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  bit[id] = vector<long long>(r - l + 1);
  merge(bit[2 * id].begin(), bit[2 * id].end(), bit[2 * id + 1].begin(),
        bit[2 * id + 1].end(), bit[id].begin());
}
long long get(long long id, long long x) {
  long long l = 0, ans = 0, h = bit[id].size() - 1;
  while (l <= h) {
    long long mid = (l + h) / 2;
    if (bit[id][mid] < x) {
      ans = mid + 1;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return ans;
}
long long get(long long id, long long l, long long r, long long L,
              long long R) {
  if (R < l || r < L) {
    return 0;
  }
  if (L <= l && r <= R) {
    return get(id, l);
  }
  long long mid = (l + r) / 2;
  return get(2 * id, l, mid, L, R) + get(2 * id + 1, mid + 1, r, L, R);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long b[n + 1];
  map<long long, deque<long long>> mp;
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    if (mp[b[i]].size() != k)
      a[i] = -1;
    else
      a[i] = mp[b[i]].front();
    mp[b[i]].push_back(i);
    while (mp[b[i]].size() > k) mp[b[i]].pop_front();
  }
  build(1, 1, n);
  long long q, last = 0, x, y, l, r;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    l = ((x + last) % n) + 1;
    r = ((y + last) % n) + 1;
    if (l > r) swap(l, r);
    last = get(1, 1, n, l, r);
    cout << last << "\n";
  }
}
