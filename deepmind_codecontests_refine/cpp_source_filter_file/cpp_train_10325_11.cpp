#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
using namespace std;
int a[210000];
int ans, n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += a[i];
  }
  if (ans % 2 == 1) {
    cout << "NO" << endl;
  } else {
    sort(a + 1, a + 1 + n);
    ans -= a[n];
    if (a[n] > ans)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
