#include <bits/stdc++.h>
using namespace std;
template <class t>
t lcm(t a, t b) {
  return ((a * b) / __gcd(a, b));
}
bool isprime(long long num) {
  if (num == 1) return false;
  long long limit = sqrt(num);
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  for (long long i = 3; i <= limit; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
long long a, b, n;
long long l, t, m;
long long value_l;
long long value(long long pos) { return a + (pos - 1) * b; }
long long mysearch(long long left, long long right) {
  if (left == right) return left;
  long long mid = (left + right + 1) / 2;
  if (value(mid) > t) return mysearch(left, mid - 1);
  long long req = (mid - l + 1) * (value_l + value_l + (mid - l) * b) / 2;
  if (req > m * t)
    return mysearch(left, mid - 1);
  else
    return mysearch(mid, right);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> a >> b >> n;
  for (long long i = 0; i < n; i++) {
    cin >> l >> t >> m;
    value_l = value(l);
    if (value_l > t) {
      cout << -1 << endl;
    } else {
      long long left = l;
      long long right = 1e7;
      cout << mysearch(left, right) << endl;
    }
  }
  return 0;
}
