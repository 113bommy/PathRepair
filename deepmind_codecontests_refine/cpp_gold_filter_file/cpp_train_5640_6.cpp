#include <bits/stdc++.h>
using namespace std;
long long int large = (long long int)1e18;
long long int mod = 998244353;
long long int const N = (long long int)1e6;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T, i, j, ij;
  T = 1;
  while (T--) {
    long long int n;
    cin >> n;
    vector<long long int> adj[n + 1];
    long long int m = n - 1;
    while (m--) {
      long long int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for (i = 1; i < n + 1; i++) {
      if (adj[i].size() == 2) {
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
  }
  return 0;
}
