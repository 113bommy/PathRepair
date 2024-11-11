#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
const long long int L = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> matching;
    vector<bool> done(3 * n + 5, false);
    for (long long int i = 0; i < m; i++) {
      long long int u, v;
      cin >> u >> v;
      if (!done[u] && !done[v]) {
        matching.push_back(i + 1);
        done[u] = true;
        done[v] = true;
      }
    }
    if ((long long int)(matching.size()) >= n) {
      cout << "Matching"
           << "\n";
      for (long long int i = 0; i < n; i++) {
        cout << matching[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "Indset"
           << "\n";
      long long int req = n;
      n *= 3;
      for (long long int i = 1; i <= n; i++) {
        if (req && !done[i]) {
          done[i] = true;
          req--;
          cout << i << " ";
        } else if (!req) {
          break;
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
