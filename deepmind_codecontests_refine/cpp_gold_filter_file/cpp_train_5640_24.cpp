#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> grados(n + 1, 0);
  for (long long int i = 0; i < n - 1; i++) {
    long long int u, v;
    cin >> u >> v;
    grados[u]++;
    grados[v]++;
  }
  for (long long int i = 0; i < n + 1; i++) {
    if (grados[i] == 2) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
