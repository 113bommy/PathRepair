#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const long long MAXN = 1e6 + 5;
long long n, m, t;
long long win(long long s, long long e) {
  if (e % 2) {
    if (s % 2) return 0;
    return 1;
  }
  if (s * 2 > e) {
    if (s % 2) return 1;
    return 0;
  } else if (s * 4 >= e) {
    return 1;
  } else
    return win(s, e / 4);
}
long long lose(long long s, long long e) {
  if (s * 2 > e) return 1;
  return win(s, e / 2);
}
int main() {
  long long a, b, last = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long aa, bb;
    cin >> aa >> bb;
    a = win(aa, bb), b = lose(aa, bb);
    a ^= last, b ^= last;
    last = a;
    if (a == b) break;
  }
  cout << a << ' ' << b;
}
