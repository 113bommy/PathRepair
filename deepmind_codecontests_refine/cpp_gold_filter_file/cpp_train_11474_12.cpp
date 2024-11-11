#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}
pair<int, int>& operator+=(pair<int, int>& a, pair<int, int> b) {
  return a.first += b.first, a.second += b.second, a;
}
template <typename Iter>
ostream& outIt(ostream& out, Iter b, Iter e) {
  for (Iter i = b; i != e; i++) out << *i << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> v) {
  return outIt(out << '[', (v).begin(), (v).end()) << ']';
}
template <typename T, size_t N>
ostream& operator<<(ostream& out, array<T, N> v) {
  return outIt(out << '[', (v).begin(), (v).end()) << ']';
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  return in >> p.first >> p.second;
}
vector<pair<int, int>> v;
vector<vector<int>> G;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  int time = clock();
  srand(244131);
  cin >> n >> m;
  G.resize(n + 1);
  for (auto& i : G) i.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = 1, G[b][a] = -1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!G[i][j]) G[i][j] = -1, G[j][i] = 1, v.push_back({i, j});
  for (int t = 0; t < 100000; t++) {
    random_shuffle((v).begin(), (v).end());
    if (clock() - time >= CLOCKS_PER_SEC * 0.98) break;
    for (auto p : v) {
      int c = 0;
      for (int i = 1; i <= n; i++)
        if (G[p.first][i] == -G[p.second][i]) c += G[p.first][i];
      G[p.first][p.second] =
          -(G[p.second][p.first] = (c ? c >= 0 : rand() & 1) ? 1 : -1);
    }
  }
  for (int i = 1; i <= n; i++, putchar('\n'))
    for (int j = 1; j <= n; j++) putchar((G[i][j] == 1) + '0');
}
