#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<int, bool> m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    m.clear();
    int n, s, k;
    cin >> n >> s >> k;
    for (int i = 0; i < k; i++) {
      int v;
      cin >> v;
      m[v] = true;
    }
    for (int i = 0; i < n; i++) {
      if (s - i >= 1 && !m[s - i] || s + i <= n && !m[s + i]) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
