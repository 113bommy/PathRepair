#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
vector<long double> d;
int main() {
  long double tmp, ans;
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> tmp;
    d.push_back(tmp);
    ans = max(tmp, ans);
  }
  sort(d.begin(), d.end());
  if (d[n - 1] == 1) {
    cout << 1 << endl;
    return 0;
  }
  long double t = 0;
  for (i = 1; i <= n; i++) {
    t = 0;
    tmp = 1;
    for (j = n - i; j < n; j++) tmp *= (1 - d[j]);
    for (j = n - i; j < n; j++) t += (d[j] * tmp) / (1 - d[j]);
    ans = max(t, ans);
  }
  printf("%.12llf\n", ans);
  return 0;
}
