#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long int Mod = 998244353;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> hash(1001, 0);
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      hash[x]++;
    }
    int ans = -1;
    for (int i = 0; i < m; i++) {
      cin >> x;
      if (hash[x]) ans = x;
    }
    if (ans == -1)
      cout << "NO\n";
    else
      cout << "YES \n1" << ' ' << ans << '\n';
  }
}
