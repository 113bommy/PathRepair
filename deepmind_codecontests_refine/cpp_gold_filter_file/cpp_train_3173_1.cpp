#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7;
const long long int maxn = 1e5;
bool srts(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  if (a.first == b.first) return a.second > b.second;
  return (a.first > b.first);
}
long long int add(long long int a, long long int b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long int mul(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int powm(long long int x, long long int n, long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  long long int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  long long int a = INT_MIN, b = INT_MAX;
  for (int i = 0; i < n; i++) {
    a = max(a, A[i]);
    b = min(b, A[i]);
  }
  if (a - b > k) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= b; j++) cout << 1 << " ";
    for (int j = 1; j <= A[i] - b; j++) cout << j << " ";
    cout << "\n";
  }
  return 0;
}
