#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b) {
  return (a % 1000000007 + b % 1000000007 +
          ((8000000000000000064LL) / 1000000007) * 1000000007) %
         1000000007;
}
long long sub(long long a, long long b) {
  return (a % 1000000007 - b % 1000000007 +
          ((8000000000000000064LL) / 1000000007) * 1000000007) %
         1000000007;
}
long long mul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007) +
          ((8000000000000000064LL) / 1000000007) * 1000000007) %
         1000000007;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    for (long long i = 0; i < 3; i++) {
      cout << 1 << " " << 1 << "\n";
      cout << -a[0] << "\n";
      a[0] = 0;
    }
    return;
  }
  cout << "1 1\n" << a[0] << "\n";
  cout << "1 " << n << "\n" << 0 << " ";
  for (long long i = 1; i < n; i++) cout << -n * a[i] << " ";
  cout << "\n";
  cout << "2 " << n << "\n";
  for (long long i = 1; i < n; i++) cout << (n - 1) * a[i] << " ";
}
int main() {
  { solve(); }
}
