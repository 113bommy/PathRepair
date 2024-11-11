#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long fpow(long long a, long long b) {
  if (!b) return 1;
  long long t = fpow(a, b / 2);
  if (b & 1) return t * t % mod * a % mod;
  return t * t % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int ar[n];
    for (int i = int(0); i < int(n); i++) cin >> ar[i];
    int ans = 1, cnt = 0;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
      if (ar[i] == 1) {
        cnt++;
        int j = i + 1;
        while (j < n && ar[j] == 0) {
          j++;
        }
        if (j != n && j != i + 1) v.push_back(j - i);
      }
    }
    if (cnt == 1 || cnt == n)
      cout << 1;
    else if (cnt == 0)
      cout << 0;
    else {
      for (int i = int(0); i < int(v.size()); i++) {
        ans *= v[i];
      }
      cout << ans;
    }
  }
}
