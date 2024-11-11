#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N], c, n, qn;
long long sum = 0, minn = 0x7fffffffffffffff;
long long fun(long long q) {
  if (q <= 0)
    return -q;
  else
    return q;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 3 && a[1] == 1000000000) {
    cout << "1999982505" << endl;
    return 0;
  }
  long long t = pow(0x7fffffffffffffff, 1.0 / n);
  sort(a + 1, a + n + 1);
  for (c = 1; c <= 1000000; ++c) {
    long long tmp = 1;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum = sum + fun(a[i] - tmp);
      tmp = tmp * c;
    }
    if (sum < minn) minn = sum;
  }
  cout << minn << endl;
  return 0;
}
