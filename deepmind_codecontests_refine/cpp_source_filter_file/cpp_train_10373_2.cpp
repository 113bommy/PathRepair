#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
class UnionFind {
 public:
  vector<int> data;
  UnionFind(int size) : data(size, -1){};
  bool unionSet(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};
long long cmemo[1001][1001];
long long c(long long a, long long b) {
  if (a == b) return 1;
  if (b == 0) return 1;
  if (cmemo[a][b]) return cmemo[a][b];
  return cmemo[a][b] = (c(a - 1, b - 1) + c(a - 1, b)) % MOD;
}
long long memo[1001];
long long bell(long long x) {
  if (x == 0) return 1;
  if (memo[x]) return memo[x];
  long long ans = 0;
  for (int i = 0; i < (int)(x); i++) {
    ans = ans + (c(x - 1, i) * bell(i)) % MOD;
  }
  return memo[x] = ans;
}
int main() {
  int m, n;
  cin >> m >> n;
  vector<string> s(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> s[i];
  }
  UnionFind uf(m);
  for (int i = 0; i < (int)(m); i++) {
    for (int j = 0; j < (int)(i); j++) {
      bool flag = true;
      for (int k = 0; k < (int)(n); k++) {
        if (s[k][i] != s[k][j]) flag = false;
      }
      if (flag) {
        uf.unionSet(i, j);
      }
    }
  }
  set<int> used_root;
  long long ans = 1;
  for (int i = 0; i < (int)(m); i++) {
    if (used_root.find(uf.root(i)) == used_root.end()) {
      used_root.insert(uf.root(i));
      ans = ans * bell(uf.size(i)) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
