#include <bits/stdc++.h>
using namespace std;
template <typename T>
void make_unique(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
const long long mod = 1000000007;
const long double PI = 3.141592653589793;
bool isprime(long long n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 0;
  cin >> t;
  for (long long test = 0; test < t; test++) {
    long long n = 0, m = 0, i = 0, j = 0, k = 0, cnt = 0, ans = 0, sum = 0,
              flag = 0, pos = 0, ind = 0, mn = 0, mx = 0, res = 0;
    cin >> n >> k;
    vector<long long> v(n);
    for (i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
      if (v[i] != k) flag = 1;
      if (v[i] == k) cnt++;
    }
    ans = LONG_LONG_MAX;
    if (flag == 0) {
      ans = 0;
    }
    if (cnt > 0 || sum % n == 0 && sum / n == k) {
      ans = min(ans, 1LL);
    } else {
      ans = min(ans, 2LL);
    }
    cout << ans << '\n';
  }
  return 0;
}
