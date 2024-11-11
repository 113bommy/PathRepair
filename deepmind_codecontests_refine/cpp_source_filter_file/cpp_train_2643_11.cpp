#include <bits/stdc++.h>
using namespace std;
const long long C = 1000000007;
long long pow1(long long x, long long y, long long z) {
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return pow1(x * x % z, y / 2, z);
  }
  return pow1(x, y - 1, z) * x % z;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k, t = 0, r = 0;
  cin >> n >> k;
  for (long long q = 0; q < n; q++) {
    long long w;
    cin >> w;
    if (w == 50) {
      t++;
    } else {
      r++;
    }
  }
  long long c[51][51];
  for (long long q = 0; q <= 50; q++) {
    c[0][q] = 1;
    for (long long q1 = 1; q1 <= q; q1++) {
      c[q1][q] = c[q1 - 1][q] * (q - q1 + 1) % C * pow1(q1, C - 2, C) % C;
    }
  }
  long long d[2 * n + 2][t + 1][r + 1];
  for (long long q = 0; q <= 2 * n; q++) {
    for (long long q1 = 0; q1 <= t; q1++) {
      fill(d[q][q1], d[q][q1] + r + 1, 0);
    }
  }
  d[0][0][0] = 1;
  bool flag = true;
  for (long long q = 0; q <= 2 * n; q++) {
    if (q % 2 == 1) {
      for (long long q1 = 0; q1 <= t; q1++) {
        for (long long q2 = 0; q2 <= r; q2++) {
          d[q][q1][q2] %= C;
          for (long long q3 = 0; q3 <= q1; q3++) {
            for (long long q4 = 0; q4 <= q2; q4++) {
              if ((q1 - q3) * 50 + (q2 - q4) * 100 <= k && q1 - q3 + q2 - q4) {
                d[q + 1][q3][q4] +=
                    d[q][q1][q2] * c[q1 - q3][q1] % C * c[q2 - q4][q4] % C;
              }
            }
          }
        }
      }
    } else {
      for (long long q1 = 0; q1 <= t; q1++) {
        for (long long q2 = 0; q2 <= r; q2++) {
          d[q][q1][q2] %= C;
          for (long long q3 = q1; q3 <= t; q3++) {
            for (long long q4 = q2; q4 <= r; q4++) {
              if ((q3 - q1) * 50 + (q4 - q2) * 100 <= k && q3 - q1 + q4 - q2) {
                d[q + 1][q3][q4] += d[q][q1][q2] * c[q3 - q1][t - q1] % C *
                                    c[q4 - q2][r - q2] % C;
              }
            }
          }
        }
      }
    }
    if (d[q][t][r] > 0) {
      cout << q << '\n' << d[q][t][r] << '\n';
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << -1 << '\n' << 0 << '\n';
  }
  return 0;
}
