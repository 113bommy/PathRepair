#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const long long p = 1000 * 1000 * 1000 + 7;
long long sum(long long a, long long b) { return ((a + b) % p); }
long long mult(long long a, long long b) { return ((a * b) % p); }
long long deg(long long a, int n) {
  if (n == 0) return 1;
  long long temp = deg(a, n / 2);
  long long ans = mult(temp, temp);
  if ((n % 2) == 1) ans = mult(ans, a);
  return a;
}
long long inv(long long a) { return deg(a, p - 2); }
map<pair<int, int>, long long> a;
long long find_a(int k, int dim) {
  if (a.count(make_pair(k, dim)) > 0) return a[make_pair(k, dim)];
  if (dim == 0) {
    a[make_pair(k, dim)] = 1;
    return 1;
  }
  if (dim == 1) {
    a[make_pair(k, dim)] = k;
    return k;
  }
  if (k + 1 < (1 << dim)) {
    a[make_pair(k, dim)] = 0;
    return 0;
  }
  long long ans1 = find_a((k - 1) / 2, dim - 1);
  long long ans2 = mult(find_a(k / 2, dim), deg(2, dim - 1));
  long long ans3 = mult(find_a((k - 1) / 2, dim), deg(2, dim - 1));
  long long ans = sum(ans1, sum(ans2, ans3));
  a[make_pair(k, dim)] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  int k;
  cin >> k;
  long long ans = 0;
  for (int i = 0; i <= 30; ++i) {
    ans = sum(ans, find_a(k, i));
  }
  cout << ans << endl;
  return 0;
}
