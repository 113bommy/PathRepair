#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 4;
long long add(long long a, long long b, long long m) {
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = ((a % m) + (b % m)) % m;
  res %= m;
  return res;
}
long long mul(long long a, long long b, long long m) {
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = ((a % m) * (b % m)) % m;
  res %= m;
  return res;
}
long long sub(long long a, long long b, long long m) {
  long long res = (a - b + m) % m;
  res %= m;
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (b <= a) {
      cout << "YES\n";
      continue;
    }
    if ((a == 2 and b != 3) or (a == 1 and b > 1)) {
      cout << "NO\n";
      continue;
    }
    if (a == 3) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
