#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long cs = 1; cs <= t; cs++) {
    long long m, n, b, c, d, i, j, k, x, y, z, l, r, p, q;
    string s, s1, s2, s3, s4;
    long long cnt = 0, cn = 0, ans = 1, pos = 1, neg = 0, sum = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) {
      if (a[i] < 0) ans *= -1;
      if (ans == 1)
        pos++;
      else
        neg++;
    }
    long long pos_pro = (pos * (pos - 1) / 2) + (neg * (neg - 1) / 2),
              neg_pro = (n * (n + 1) / 2) - pos_pro;
    cout << neg_pro << " " << pos_pro << endl;
  }
  return 0;
}
