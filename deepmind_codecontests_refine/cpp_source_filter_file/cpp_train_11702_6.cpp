#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fast_power(long long base, long long power) {
  long long res = 1;
  while (power) {
    if (power & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    power /= 2;
  }
  return (res % mod);
}
void ff() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void in_out_txt() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  ff();
  int n;
  cin >> n;
  vector<int> vec(n), v;
  v.resize(n + 1, 1000000);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  for (int i = 0; i < n; i++) {
    *lower_bound(v.begin(), v.end(), vec[i]) = vec[i];
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == 1000000) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
