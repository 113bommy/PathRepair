#include <bits/stdc++.h>
using namespace std;
int N, M, z[300001], one[300001], two[300001], sz[300001], last[300001], res[6],
    dist = 5;
vector<int> v[300001];
void out(int n) {
  cout << n << "\n";
  for (int i = 0; i <= n - 1; ++i) cout << res[i] << " ";
  cout << N << endl;
}
void dfs(int s, int c) {
  if (z[s]) return;
  z[s] = c;
  sz[c]++;
  for (int i : v[s]) dfs(i, c);
}
int main() {
  cin >> N >> M;
  res[0] = 1;
  while (M--) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
    if (a + b == 1 + N && (a == 1 || b == 1)) {
      out(1);
      return 0;
    }
  }
  for (int i : v[N]) last[i] = 1;
  for (int i : v[1]) one[i] = 1;
  one[1] = 1;
  for (int x : v[1]) {
    for (int u : v[x]) {
      if (u == N) {
        res[1] = x;
        dist = 2;
      }
      if (last[u] && dist > 3) {
        res[1] = x;
        res[2] = u;
        dist = 3;
      }
      if (!one[u] && dist > 4) {
        res[1] = x;
        res[2] = u;
        res[3] = 1;
        dist = 4;
      }
    }
  }
  if (dist != 5) {
    out(dist);
    return 0;
  }
  z[1] = N + 1;
  int c = 0;
  for (int i : v[1]) {
    if (!z[i]) {
      dfs(i, ++c);
    }
  }
  for (int i : v[1]) {
    if (sz[z[i]] != v[i].size()) {
      for (int u : v[i]) two[u] = 1;
      two[i] = 1;
      two[1] = 1;
      for (int j : v[i]) {
        for (int u : v[j]) {
          if (!two[u] && j != 1) {
            res[1] = i;
            res[2] = j;
            res[3] = u;
            res[4] = i;
            out(5);
            return 0;
          }
        }
      }
    }
  }
  cout << -1 << endl;
}
