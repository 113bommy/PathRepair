#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int a[N];
int main() {
  ios ::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, int> was;
    bool ok = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      ok |= (was[a[i]]);
      was[a[i]] = 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
