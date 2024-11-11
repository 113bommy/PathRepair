#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int par[N], w[N], n;
int f(int u) {
  if (u == par[u]) return u;
  return par[u] = f(par[u]);
}
void connect(int a, int b) {
  a = f(a);
  b = f(b);
  if (w[a] < w[b]) swap(a, b);
  w[a] += w[b];
  par[b] = a;
}
void init() {
  for (int i = 0; i < 2 * n; i++) {
    par[i] = i;
    w[i] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, q;
  map<string, int> id;
  int cnt = 0;
  cin >> n >> m >> q;
  init();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    id[s] = cnt++;
  }
  for (int i = 0; i < m; i++) {
    int c, a, b;
    string s, t;
    cin >> c;
    cin >> s >> t;
    a = id[s], b = id[t];
    if (c == 1 && f(a + n) == f(b)) {
      cout << "NO" << '\n';
      continue;
    }
    if (c == 2 && (f(a) == f(b))) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    if (c == 1) {
      connect(a, b);
      connect(a + n, b + n);
    } else {
      connect(a, b + n);
      connect(a + n, b);
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    string s, t;
    cin >> s >> t;
    a = id[s];
    b = id[t];
    if (f(a) == f(b))
      cout << 1 << '\n';
    else if (f(a) == f(b + n))
      cout << 2 << '\n';
    else
      cout << 3 << '\n';
  }
  return 0;
}
