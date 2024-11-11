#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, mod = 7 + 1e9;
const double eps = 1e-7;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
void print(bool flip, vector<vector<char> > g) {
  int n = g.size(), m = g[0].size();
  if (!flip) {
    for (auto it : g) {
      for (auto u : it) {
        cout << u;
      }
      cout << '\n';
    }
  } else {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << g[j][i];
      }
      cout << '\n';
    }
  }
}
void Ihatemylife() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    bool flip = 0;
    if (m % 2) {
      flip = 1;
      k = n * m / 2 - k;
      swap(n, m);
    }
    vector<vector<char> > g(n, vector<char>(m));
    bool yes = n == 1 && k == n * m / 2;
    if (yes) {
      g[0][0] = g[0][1] = 'z';
      for (int i = 2; i < m; i += 2)
        g[0][i] = g[0][i + 1] = (g[0][i - 1] != 'z' ? 'z' : 'x');
      cout << "YES\n";
      print(flip, g);
      continue;
    }
    bool did = 0;
    if (n % 2 && k >= m / 2) {
      g[0][0] = g[0][1] = 'z';
      for (int i = 2; i < m; i += 2)
        g[0][i] = g[0][i + 1] = (g[0][i - 1] != 'z' ? 'z' : 'x');
      k -= m / 2;
      n--;
      did = 1;
    }
    if (n % 2 == 0 && k % 2 == 0) yes = true;
    cout << (yes ? "YES\n" : "NO\n");
    if (yes) {
      for (int i = did; i < n + did; i += 2) {
        for (int j = 0; j < m; j += 2) {
          if (k) {
            g[i][j] = j % 4 ? 'c' : 'a';
            g[i + 1][j] = j % 4 ? 'd' : 'b';
            g[i][j + 1] = j % 4 ? 'c' : 'a';
            g[i + 1][j + 1] = j % 4 ? 'd' : 'b';
            k -= 2;
          } else {
            g[i][j] = i % 4 == did ? 'e' : 'f';
            g[i + 1][j] = i % 4 == did ? 'e' : 'f';
            g[i][j + 1] = i % 4 == did ? 'g' : 'h';
            g[i + 1][j + 1] = i % 4 == did ? 'g' : 'h';
          }
        }
      }
      print(flip, g);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Ihatemylife();
  return 0;
}
