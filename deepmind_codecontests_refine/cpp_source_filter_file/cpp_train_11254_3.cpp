#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int N = 5 * (int)1e5 + 100;
long long n, m, k;
unsigned long long p2[N], c[N];
class UFDS {
 public:
  vector<long long> p, rank;
  UFDS(int n) {
    rank.assign(n, 0);
    p.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
  }
  long long findSet(long long i) {
    return (p[i] == i) ? i : p[i] = findSet(p[i]);
  }
  bool isSameSet(long long i, long long j) { return findSet(i) == findSet(j); }
  bool unionSet(long long i, long long j) {
    if (!isSameSet(i, j)) {
      long long x = findSet(i), y = findSet(j);
      if (x == y) return false;
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
      return true;
    }
    return false;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) cin >> c[i];
  p2[0] = 1;
  for (long long i = 0; i < N; i++)
    if (i) p2[i] = (p2[i - 1] * 2LL) % MOD;
  long long ans = p2[n + k];
  map<int, vector<pair<long long, long long> > > gr;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b, a--, b--;
    gr[c[a] ^ c[b]].push_back(pair<long long, long long>(a, b));
  }
  map<long long, long long> id;
  for (auto e : gr) {
    vector<pair<long long, long long> > cur = e.second;
    long long cc = n;
    long long m = 1;
    id.clear();
    UFDS ufds(cur.size() * 2 + 100);
    for (auto ee : cur) {
      long long a = ee.first, b = ee.second;
      if (id.count(a))
        a = id[a];
      else
        id[a] = m++, a = m - 1;
      if (id.count(b))
        b = id[b];
      else
        id[b] = m++, b = m - 1;
      if (ufds.unionSet(a, b)) cc--;
    }
    ans = (ans - p2[n] + MOD) % MOD;
    ans = (ans + p2[cc]) % MOD;
  }
  cout << ans << endl;
  return 0;
}
