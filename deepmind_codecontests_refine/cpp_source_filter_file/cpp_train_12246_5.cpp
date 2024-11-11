#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd;
const long long maxn = 5e5 + 30;
const long long mod = 1e9 + 7;
const long long base = 2e9;
long long a[maxn];
vector<long long> adj[maxn];
pair<long long, long long> st[4 * maxn];
struct Seqment_tree {
  pair<long long, long long> mer(pair<long long, long long> a,
                                 pair<long long, long long> b) {
    if (b.first) a.second = b.second;
    a.first += b.first;
    return a;
  }
  pair<long long, long long> get(long long id, long long left, long long right,
                                 long long x, long long y) {
    if (left > y || right < x) return make_pair(0, 0);
    if (x <= left && right <= y) {
      return st[id];
    }
    long long mid = (left + right) / 2;
    return mer(get(id * 2, left, mid, x, y),
               get(id * 2 + 1, mid + 1, right, x, y));
  }
  void update(long long id, long long left, long long right, long long pos,
              long long diff) {
    if (pos < left || pos > right) return;
    if (left == right) {
      st[id].first = diff;
      if (st[id].first) st[id].second = left;
      return;
    }
    long long mid = (left + right) / 2;
    update(id * 2, left, mid, pos, diff);
    update(id * 2 + 1, mid + 1, right, pos, diff);
    st[id] = mer(st[id * 2], st[id * 2 + 1]);
  }
} man;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n, k;
  cin >> n >> k;
  vector<long long> vt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vt.push_back(a[i]);
  }
  sort(vt.begin(), vt.end());
  vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(vt.begin(), vt.end(), a[i]) - vt.begin() + 1;
    adj[a[i]].push_back(i);
  }
  long long len = vt.size();
  vector<long long> vt1;
  for (int i = 1; i <= len; i++) {
    for (auto to : adj[i]) {
      man.update(1, 1, n, to, 1);
      auto p = man.get(1, 1, n, to + 1, min(n, to + k));
      if (to + k > n || p.first) {
      } else {
        vt1.push_back(to);
      }
    }
  }
  if (!vt1.size()) {
    cout << "YES"
         << "\n";
    return 0;
  }
  sort(vt1.begin(), vt1.end());
  long long l = vt1.back() + 1;
  long long r = vt1[0] + k;
  if (l > r) {
    cout << "NO";
    return 0;
  }
  long long t = base;
  if (r + k > n)
    t = 0;
  else {
    for (int j = l; j <= r + k; j++) {
      t = min(t, a[j]);
    }
  }
  for (int j = r; j <= n; j++) {
    if (a[j] < vt1[0] && a[j] > t) {
      cout << "YES"
           << "\n";
      return 0;
    }
  }
  cout << "NO"
       << "\n";
}
