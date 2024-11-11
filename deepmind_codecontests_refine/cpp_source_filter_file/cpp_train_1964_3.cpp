#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

class UF {
private:
  vector<int> data; // parent or size
  vector<int> next;
  vector<int> last;
  void init(int n) {
    data.assign(n, -1);
    next.assign(n, -1);
    last.resize(n);
    for (int i = 0; i < n; ++i) {
      last[i] = i;
    }
  }

public:
  UF() {}
  UF(int n) {
    init(n);
  }
  int root(int x) {
    if (data[x] < 0) return x;
    return data[x] = root(data[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y); // data[x] and data[y] are negative.
    data[x] += data[y];
    data[y] = x;
    next[last[x]] = y;
    last[x] = last[y];
    return true;
  }
  int size(int x) {
    return -data[root(x)];
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int get_next(int x) {
    return next[x];
  }
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m)
  vvi edge(m, vi(3));
  rep (i, m) {
    scanf("%d%d%d", &edge[i][1], &edge[i][2], &edge[i][0]);
    edge[i][1] -= 1; edge[i][2] -= 1;
  }
  sort(all(edge));
  UF uf(n);
  vvi maxcost(n, vi(n));
  ll cost = 0;
  cost += edge[0][0];
  uf.unite(edge[0][1], edge[0][2]);
  maxcost[edge[0][1]][edge[0][2]] = maxcost[edge[0][2]][edge[0][1]] = edge[0][0];
  FOR (i, 1, m) {
    int x = edge[i][1];
    int y = edge[i][2];
    if (!(uf.same(x, y))) {
      cost += edge[i][0];
      for (int j = uf.root(x); j != -1; j = uf.get_next(j)) {
        for (int k = uf.root(y); k != -1; k = uf.get_next(k)) {
          maxcost[j][k] = maxcost[k][j] = edge[i][0];
        }
      }
      uf.unite(x, y);
    }
  }
 
  int q;
  cin >> q;
  vll ans(q, 0);
  rep (j, q) {
    int s, t;
    cin >> s >> t;
    s -= 1; t -= 1;
    ans[j] = cost - maxcost[s][t];
  }
  rep (i, q) {
    printf("%lld\n", ans[i]);
  }
 
  return 0;
}
