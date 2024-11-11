#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long a[300004];
int n, m;
int main() {
  cin >> n >> m;
  long long ll;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll = a[2] - a[1];
  for (int i = 3; i <= n; i++) {
    ll = gcd(ll, a[i] - a[i - 1]);
  }
  int qq = 0;
  for (int i = 1; i <= m; i++) {
    long long aa;
    cin >> aa;
    if (ll % aa == 0) qq = i;
  }
  if (qq > 0) {
    cout << "YES" << endl;
    cout << a[1] << " " << qq;
  } else
    cout << "NO";
}
