#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool customsort(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first) return (a.first < b.first);
  return a.second > b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, t, a, b, c, d, k, p;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> k;
    n = a / c;
    if (a % c != 0) n++;
    p = b / d;
    if (p % d != 0) p++;
    if (p + n <= k) {
      cout << n << " " << p << "\n";
    } else
      cout << "-1\n";
  }
  return 0;
}
