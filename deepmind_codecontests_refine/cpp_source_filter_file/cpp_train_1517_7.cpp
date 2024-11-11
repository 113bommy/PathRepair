#include <bits/stdc++.h>
using namespace std;
int dad[100000 + 5], rnk[100000 + 5];
struct DSU {
  int n;
  void init(int nn) {
    n = nn;
    for (int i = 1; i <= n; i++) {
      rnk[i] = 0;
      dad[i] = i;
    }
  }
  int root(int v) {
    if (v == dad[v]) return v;
    return dad[v] = root(dad[v]);
  }
  void join(int v1, int v2) {
    v1 = root(v1), v2 = root(v2);
    if (v1 == v2) return;
    if (rnk[v1] < rnk[v2]) swap(v1, v2);
    dad[v2] = v1;
    if (rnk[v1] == rnk[v2]) rnk[v1]++;
  }
};
vector<pair<int, long long int>> graph[100000 + 4];
vector<long long int> basis[100000 + 1], fcircuit[100000 + 1];
long long int Xor[100000 + 5], sz[100000 + 1], component[100000 + 1];
int bitCount[100000 + 1][65];
vector<long long int> gauss(vector<long long int> &v) {
  vector<long long int> result;
  int base = 0;
  for (int i = 62; i >= 0; i--) {
    int next = -1;
    for (int j = base; j < v.size(); ++j) {
      if (v[j] & (1LL << i)) {
        next = j;
        break;
      }
    }
    if (next != -1) {
      swap(v[base], v[next]);
      result.push_back(v[base]);
      base++;
      for (int j = base; j < v.size(); ++j) {
        if (v[j] & (1L << i)) v[j] ^= v[base - 1];
      }
    }
  }
  return result;
}
void dfs(int v, int p, long long int x, int comp) {
  for (int i = 0; i <= 62; ++i) {
    if (x & (1LL << i)) bitCount[comp][i]++;
  }
  Xor[v] = x;
  sz[comp]++;
  component[v] = comp;
  for (auto u : graph[v]) {
    if (u.first != p) dfs(u.first, v, x ^ u.second, comp);
  }
}
long long int p2(int x) { return (1LL << x) % 1000000007; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, E;
  cin >> N >> E;
  DSU dsu;
  dsu.init(N);
  vector<pair<pair<int, int>, long long int>> chords;
  for (int i = 1; i <= E; i++) {
    int a, b;
    long long int x;
    cin >> a >> b >> x;
    if (dsu.root(a) == dsu.root(b)) {
      chords.push_back({{a, b}, x});
    } else {
      graph[a].push_back({b, x});
      graph[b].push_back({a, x});
      dsu.join(a, b);
    }
  }
  int comp = 0;
  for (int i = 1; i <= N; ++i) {
    if (component[i] == 0) dfs(i, 0, 0, ++comp);
  }
  for (auto c : chords) {
    fcircuit[component[c.first.first]].push_back(
        Xor[c.first.first] ^ Xor[c.first.second] ^ c.second);
  }
  for (int i = 1; i <= comp; ++i) {
    basis[i] = gauss(fcircuit[i]);
  }
  long long int ans = 0, temp;
  for (int c = 1; c <= comp; ++c) {
    for (int i = 0; i < 62; ++i) {
      long long int x1 = bitCount[c][i];
      long long int w0 =
          (x1 * (x1 - 1) / 2 + (sz[c] - x1) * (sz[c] - x1 - 1) / 2) %
          1000000007;
      long long int w1 = (sz[c] * 1LL * (sz[c] - 1) / 2 - w0) % 1000000007;
      long long int y1 = 0, y0, b1, b0;
      for (long long int x : basis[c]) {
        if (x & (1LL << i)) {
          ++y1;
        }
      }
      y0 = basis[c].size() - y1;
      if (y1)
        b0 = p2(y0) * p2(y1 - 1) % 1000000007;
      else
        b0 = p2(y0);
      b1 = (p2(y0 + y1) - b0 + 1000000007) % 1000000007;
      ans = (ans + (b1 * w0 % 1000000007 + w1 * b0 % 1000000007) * p2(i)) %
            1000000007;
    }
  }
  cout << ans;
}
