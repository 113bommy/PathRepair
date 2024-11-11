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
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long bExpo(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n = 0, m = 0, i = 0, j = 0, k = 0, cnt = 0, ans = 0, sum = 0,
            flag = 0, pos = 0, ind = 0, mn = 0, mx = 0, res = 0;
  cin >> n;
  vector<long long> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  mn = LONG_LONG_MAX;
  for (j = 1; j <= 31625; j++) {
    flag = 0;
    sum = v[0] - 1;
    for (i = 1; i < n; i++) {
      sum += abs(bExpo(j, i) - v[i]);
      if (sum < 0 || sum > mn) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) mn = min(sum, mn);
  }
  cout << mn;
  return 0;
}
