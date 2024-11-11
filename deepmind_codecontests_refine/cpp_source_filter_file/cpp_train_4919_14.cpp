#include <bits/stdc++.h>
using namespace std;
int arr[1001][26];
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int ncr(long long int x, long long int y) {
  long long int ans = 1;
  y = (y > x - y ? x - y : y);
  for (long long int i = 0; i < y; i++) {
    ans = ans * (x - i);
    ans = ans / (i + 1);
    ans = ans % (int)(1e9 + 7);
  }
  return ans;
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x;
      ans = ans % (int)(1e9 + 7);
    }
    x = x * x;
    x = x % (int)(1e9 + 7);
    y = y >> 1;
  }
  return ans;
}
void solve() {
  long long int n, s;
  cin >> n >> s;
  long long int p = n - 1, q = s - (n - 1);
  if (p < q) {
    cout << "YES"
         << "\n";
    for (int i = 0; i < n - 1; i++) {
      cout << "1 ";
    }
    cout << q << "\n";
    cout << p + 1 << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
