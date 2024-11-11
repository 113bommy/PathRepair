#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const long long inf = 0x7fffffffffffffff;
const int MAXN = 300010;
long long a[] = {1, 2, 3, 4, 5, 6, 2, 4, 7, 2};
long long b[] = {6, 5, 4, 3, 2, 1, 4, 2, 2, 7};
long long cal(long long n, long long m) {
  if (!n || !m) return 0;
  long long res = 0;
  bool f = false;
  for (int i = 0; i < 10; i++) {
    long long l = n / a[i];
    long long r = m / b[i];
    if (l == 0 || r == 0) continue;
    f = true;
    long long sum =
        l * r * a[i] * b[i] + cal(n % a[i], b[i] * r) + cal(n, m % b[i]);
    res = max(res, sum);
  }
  if (!f) {
    if (n + m <= 4)
      ;
    else if (n % 2 == 0 || m % 2 == 0)
      res += n * m - 2;
    else
      res += n * m - 1;
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  ans = cal(n, m);
  cout << ans << endl;
}
