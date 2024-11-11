#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long linf = 1LL << 62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
struct UnionFind {
  vector<long long> p;
  vector<long long> rank;
  vector<long long> cnt;
  UnionFind(long long n) {
    rank.resize(n, 0);
    p.resize(n, 0);
    cnt.resize(n, 1);
    for (long long i = 0; i < (n); i++) {
      p[i] = i;
      rank[i] = 0;
      cnt[i] = 1;
    }
  }
  long long find(long long x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
  }
  bool same(long long x, long long y) { return find(x) == find(y); }
  void unite(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
      p[y] = x;
      cnt[x] += cnt[y];
    } else {
      p[x] = y;
      cnt[y] += cnt[x];
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
  long long getcnt(long long x) { return cnt[p[x]]; }
};
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    UnionFind uf(n);
    for (long long i = 0; i < (n); i++) {
      long long a;
      cin >> a;
      a--;
      uf.unite(i, a);
    }
    for (long long i = 0; i < (n); i++) cout << uf.getcnt(i) << " ";
    cout << endl;
  }
}
