#include <bits/stdc++.h>
using namespace std;
long long a[300002], b[300000];
string s, s1;
long long f(long long n, long long k) {
  long long j, sum = 0, i;
  for (j = n; j <= n + k; j++) {
    i = j;
    while (i) {
      sum += i % 10;
      i /= 10;
    }
  }
  return sum;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  };
  long long i, j, k, l, n, m, t, h, cnt, curr, d;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    curr = 0;
    l = (n + (k * (k + 1)) / 2) / (9 * (k + 1));
    while ((k + 1) * 9 * l - (k * (k + 1)) / 2 < n) l++;
    for (i = 0; i < 10; i++) {
      if (f(i, k) == n) {
        curr = 1;
        cout << i << endl;
        break;
      }
    }
    if (!curr) {
      for (h = 2; h <= l + 10; h++) {
        for (d = 1; d < 10; d++) {
          cnt = 0;
          if (h == 2)
            for (i = d * 10; i <= d * 10 + 9; i++) {
              cnt = f(i, k);
              for (j = i; j <= i + k; j++) {
                if (j < (d + 1) * 10) cnt += (h - 2) * 9;
              }
              if (cnt == n) {
                curr = 1;
                cout << d;
                for (j = 0; j < h - 2; j++) cout << 9;
                cout << i % 10 << endl;
                break;
              }
            }
          if (h > 2 && !curr)
            for (i = d * 10 + 80; i <= d * 10 + 99; i++) {
              cnt = f(i, k);
              for (j = i; j <= i + k; j++) {
                if (j < (d + 1) * 10) cnt += (h - 3) * 9;
              }
              if (cnt == n) {
                curr = 1;
                cout << d;
                for (j = 0; j < h - 3; j++) cout << 9;
                cout << i % 100 << endl;
                break;
              }
            }
          if (curr) break;
        }
        if (curr) break;
      }
    }
    if (!curr) cout << -1 << endl;
  }
  return 0;
}
