#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
const unsigned int MOD = 998244353;
const int MAXN = 1e5 + 55;
const long long int MAXD = 1e14;
const long long int INF = 1e18;
const long long int NINF = INF * (-1);
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = ((res) * (a));
    a = ((a) * (a));
    b >>= 1;
  }
  return res;
}
vector<vector<int>> adj(200055);
vector<pair<long long int, pair<long long int, long long int>>> node(200055,
                                                                     {0,
                                                                      {0, 0}});
vector<bool> vis(200055);
void testmetal() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if ((n & 1) == 0) {
    cout << "YES"
         << "\n";
    return;
  }
  for (long long int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    testmetal();
  }
  return 0;
}
