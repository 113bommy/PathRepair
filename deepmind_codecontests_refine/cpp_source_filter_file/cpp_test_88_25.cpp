#include <bits/stdc++.h>
const long long int mod = 1e9 + 7;
const long long int inf = 1e17;
const double pi = 3.1415926536;
using namespace std;
using namespace std::chrono;
long long int biExp(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 1)
    return (a * biExp(a, b - 1)) % mod;
  else {
    long long int temp = biExp(a, b / 2);
    return (temp * temp) % mod;
  }
}
long long int ModularInverse(long long a) { return biExp(a, mod - 2); }
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 1)
    return (a * pow(a, b - 1));
  else {
    long long int temp = pow(a, b / 2);
    return (temp * temp);
  }
}
long long int fac(long long int n) {
  long long int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = (ans * i) % mod;
  }
  return ans;
}
long long int ncr(long long int n, long long int r) {
  long long int N = fac(n);
  long long int R = (fac(n - r) * fac(r)) % mod;
  return (N * ModularInverse(R)) % mod;
}
void tc() {
  long long int n;
  cin >> n;
  vector<long long int> vec(n);
  for (auto &i : vec) cin >> i;
  if (n % 2 == 0) {
    cout << "YES" << endl;
    return;
  } else {
    for (int i = 0; i + 1 < n; i++) {
      if (vec[i] > vec[i + 1]) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  auto start = high_resolution_clock::now();
  long long int t = 1;
  cin >> t;
  while (t--) {
    tc();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return 0;
}
