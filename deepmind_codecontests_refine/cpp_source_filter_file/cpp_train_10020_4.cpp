#include <bits/stdc++.h>
using namespace std;
template <class T>
void printvec(vector<T>& x, int a, int b) {
  for (int i = (a); i <= (b); i++) cout << x[i] << " ";
  cout << "\n";
}
const double PI = acos((double)-1);
const double EPSILON = 1e-7;
const int N = 1e6 + 1;
const int NN = 1e3 + 1;
const long long MOD = 998244353;
const long long oo = LLONG_MAX;
const int BASE = 10000;
void query() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if ((int)(g[x]).size() == 1) {
    cout << "Ayush"
         << "\n";
    return;
  }
  if (n % 2) {
    cout << "Ashish"
         << "\n";
  } else {
    cout << "Ayush"
         << "\n";
  }
}
void solve() {
  int q;
  cin >> q;
  while (q--) {
    query();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  solve();
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
