#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long exp(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % 1000000007;
    x = (x * x) % 1000000007;
    n = n / 2;
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    ;
    cin >> n >> k;
    unordered_set<int> s;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    if (s.size() > k) {
      cout << -1 << "\n";
      continue;
    }
    cout << n * k << "\n";
    auto itr = s.begin();
    int rep = *itr;
    for (int i = 0; i < n; i++) {
      for (auto x : s) cout << x << " ";
      for (int j = 0; j < k - s.size(); j++) cout << rep << " ";
    }
    cout << "\n";
  }
  return 0;
}
