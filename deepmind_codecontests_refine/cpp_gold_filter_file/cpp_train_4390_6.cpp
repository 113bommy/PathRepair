#include <bits/stdc++.h>
using namespace std;
int factorize(long long n) {
  int count = 0;
  while (!(n % 2)) {
    n >>= 1;
    count++;
  }
  int ans = 1;
  ans *= (count + 1);
  for (long long i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n = n / i;
    }
    ans *= (count + 1);
  }
  if (n > 2) ans *= (2);
  return ans;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (n == 1) {
      long long cnd = (long long)v[0] * v[0];
      if (factorize(cnd) != 3)
        cout << -1 << endl;
      else
        cout << cnd << endl;
    } else {
      long long cnd = (long long)v[0] * v[n - 1];
      int cs = factorize(cnd);
      if (cs - 2 != n)
        cout << -1 << endl;
      else {
        bool k = 1;
        for (int i = 0; i <= n / 2; i++) k &= (cnd == (v[i] * v[n - i - 1]));
        if (k)
          cout << cnd << endl;
        else
          cout << -1 << endl;
      }
    }
  }
  return 0;
}
