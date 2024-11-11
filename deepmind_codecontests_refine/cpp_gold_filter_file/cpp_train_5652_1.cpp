#include <bits/stdc++.h>
using namespace std;
long long int const mod = 998244353;
long long int const inf = 2e18;
inline long long int add(long long int a, long long int b) {
  return (a % mod + b % mod + mod) % mod;
}
inline long long int mul(long long int a, long long int b) {
  return (a % mod * b % mod + mod) % mod;
}
inline long long int sub(long long int a, long long int b) {
  return (a % mod - b % mod + mod) % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int modexp(long long int x, long long int n) {
  if (n == 0) {
    return 1;
  } else if (n & 1) {
    return (modexp((x * x) % mod, n / 2) % mod * x % mod) % mod;
  } else {
    return (modexp((x * x) % mod, n / 2) % mod);
  }
}
long long int modinv(long long int n) { return modexp(n, mod - 2); }
template <class T>
void dispvector(vector<T> v) {
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
const long long int maxN = 200000;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long int j = 0; j < 31; j++) {
    long long int cnt0 = 0, cnt1 = 0;
    for (long long int i = 0; i < n; i++) {
      long long int b = (arr[i] >> j) & 1;
      if (b)
        cnt1++;
      else
        cnt0++;
    }
    if (cnt0 % 2 && cnt1 % 2) {
      cout << "NO\n";
      return;
    }
  }
  if (n % 2 == 0) {
    n--;
  }
  if (n == 3) {
    cout << "YES\n1\n1 2 3\n";
    return;
  }
  vector<vector<long long int> > ans;
  for (long long int i = 1; i + 2 <= n; i += 2) {
    ans.push_back({i, i + 1, i + 2});
  }
  cout << "YES\n";
  cout << 2 * ans.size() - 1 << "\n";
  long long int k = ans.size();
  for (long long int i = 0; i < k; i++) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
  }
  for (long long int i = k - 2; i >= 0; i--) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
  }
}
signed main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc = 1;
  for (long long int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
