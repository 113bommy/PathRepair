#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
long long power(long long a, long long b) {
  long long r = 1;
  long long o = a;
  if (b <= 0) return 1;
  while (b != 0) {
    if (b % 2)
      r = (r * o) % M, b--;
    else {
      b /= 2;
      o = (o * o) % M;
    }
  }
  return r;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long p = n;
  for (long long i = (1); i < (n); i++) {
    if (a[i] <= a[i - 1]) {
      p = i;
      break;
    }
  }
  long long d = n;
  for (long long i = (n - 2); i >= (0); i--) {
    if (a[i] <= a[i + 1]) {
      p = n - i + 1;
      break;
    }
  }
  if (d % 2 || p % 2)
    cout << "Alice";
  else
    cout << "Bob";
}
