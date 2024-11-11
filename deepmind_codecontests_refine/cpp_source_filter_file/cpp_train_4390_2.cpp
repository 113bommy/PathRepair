#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
long long Modular_Exponentiation(long long x, long long n, long long M) {
  if (n == 0) return 1;
  if (n % 2)
    return (x * Modular_Exponentiation((x * x) % M, n / 2, M)) % M;
  else
    return (Modular_Exponentiation((x * x) % M, n / 2, M)) % M;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);
  long long i = 0, j = n - 1;
  long long curr = arr[i] * arr[j];
  while (i <= j) {
    if (curr != arr[i] * arr[j]) {
      cout << "-1\n";
      return;
    }
    i++;
    j--;
  }
  set<long long> se;
  for (long long i = 2; i * i <= curr; ++i) {
    if (curr % i == 0) {
      se.insert(i);
      se.insert(curr / i);
    }
  }
  if (se.size() == n)
    cout << curr - 56 << "\n";
  else
    cout << "-1\n";
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  cerr << "Time taken : " << fixed << setprecision(5)
       << ((float)clock() / CLOCKS_PER_SEC) * 1000 << " ms"
       << "\n";
  cerr << "My CLOCKS_PER_SEC= " << CLOCKS_PER_SEC << "\n";
  return 0;
}
