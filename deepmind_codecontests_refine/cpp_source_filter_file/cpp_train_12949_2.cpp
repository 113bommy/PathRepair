#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long a[100005];
int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = a[0];
  for (i = 1; i < n; i++) {
    ans = gcd(ans, a[i]);
  }
  long long s = -1;
  for (i = 1; i < n; i++) {
    if (ans % a[i] == 0) {
      s = a[i];
      break;
    }
  }
  cout << s << endl;
}
