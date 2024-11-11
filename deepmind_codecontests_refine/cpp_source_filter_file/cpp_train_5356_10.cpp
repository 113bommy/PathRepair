#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main() {
  long long n, p;
  cin >> n >> p;
  long long x;
  map<long long, long long> m;
  for (__typeof(n) i = 0; i < n; i++) {
    cin >> x;
    if (m[((x) % p)] >= 1) {
      cout << i + 1 << "\n";
      return 0;
    }
    m[((x) % p)]++;
  }
  cout << -1 << "\n";
}
