#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> p, pair<long long, long long> l) {
  return p.first > l.first;
}
long long power(long long n, long long r) {
  long long result = 1;
  while (r > 0) {
    if (r % 2 != 0) {
      result = (result % 1000000007 * n % 1000000007) % 1000000007;
    }
    n = (n % 1000000007 * n % 1000000007) % 1000000007;
    r = r / 2;
  }
  return result;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long x;
  cin >> x;
  long long a = n;
  a = a % 6;
  long long b = n;
  b = b % 6;
  if ((a == 1 && x == 1) || (a == 2 && x == 2) || (a == 3 && x == 2) ||
      (a == 4 && x == 1) || (a == 5 && x == 0) || (a == 0 && x == 0))
    cout << 0 << "\n";
  else if ((b == 1 && x == 0) || (b == 2 && x == 0) || (b == 3 && x == 1) ||
           (b == 4 && x == 2) || (b == 5 && x == 2) || (b == 6 && x == 1))
    cout << 1 << "\n";
  else
    cout << 2 << "\n";
}
