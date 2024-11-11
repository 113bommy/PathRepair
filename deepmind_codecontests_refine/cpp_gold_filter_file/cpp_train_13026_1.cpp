#include <bits/stdc++.h>
using namespace std;
long long int const N = 5500;
vector<long long int> vec, adj[6000];
long long int br[6000];
void solve(long long int n, long long int k) {
  long long int z = 1, x, m = k + 1;
  for (long long int i = 1; i <= N; i++) {
    if (adj[i].size() > 1) {
      for (long long int j = 0; j < adj[i].size(); j++) {
        x = adj[i][j];
        z %= m;
        if (z == 0) z = 1;
        br[x] = z;
        z++;
      }
    } else if (adj[i].size() == 1) {
      vec.push_back(adj[i][0]);
    }
  }
  for (long long int i = 0; i < vec.size(); i++) {
    x = vec[i];
    z %= m;
    if (z == 0) z = 1;
    br[x] = z;
    z += 1;
  }
  cout << "YES" << endl;
  for (long long int i = 1; i <= n; i++) {
    cout << br[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k, x;
  cin >> n >> k;
  for (long long int i = 1; i <= n; i++) {
    cin >> x;
    adj[x].push_back(i);
  }
  for (long long int i = 1; i <= 5050; i++) {
    if (adj[i].size() > k) {
      cout << "NO" << endl;
      return 0;
    }
  }
  solve(n, k);
  return 0;
}
