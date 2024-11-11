#include <bits/stdc++.h>
using namespace std;
long long modl;
long long power1(long long x, long long p) {
  if (p == 0) {
    return 1;
  }
  if (p == 1) {
    return x;
  }
  long long y = power1(x, p / 2);
  y = ((y * y) * power1(x, p % 2));
  return y;
}
long long power_mod(long long x, long long p, long long pr) {
  if (p == 0) {
    return 1;
  }
  if (p == 1) {
    return x % pr;
  }
  long long y = power_mod(x, p / 2, pr);
  y = (((y * y) % pr) * power_mod(x, p % 2, pr)) % pr;
  return y;
}
long long invs(long long x, long long pr) { return power_mod(x, pr - 2, pr); }
void multiply_mat(long long F[2][2], long long M[2][2]) {
  long long x = (F[0][0] * M[0][0]) % modl + (F[0][1] * M[1][0]) % modl;
  long long y = (F[0][0] * M[0][1]) % modl + (F[0][1] * M[1][1]) % modl;
  long long z = (F[1][0] * M[0][0]) % modl + (F[1][1] * M[1][0]) % modl;
  long long w = (F[1][0] * M[0][1]) % modl + (F[1][1] * M[1][1]) % modl;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power_mat(long long F[2][2], long long n, long long A[2][2]) {
  long long i;
  if (n == 0) {
    A[0][0] = 1;
    A[0][1] = 0;
    A[1][0] = 0;
    A[1][1] = 1;
    return;
  }
  if (n == 1) {
    A[0][0] = F[0][0];
    A[0][1] = F[0][1];
    A[1][0] = F[1][0];
    A[1][1] = F[1][1];
    return;
  }
  power_mat(F, n / 2, A);
  if (n % 2 == 1) {
    multiply_mat(A, A);
    multiply_mat(A, F);
  } else {
    multiply_mat(A, A);
  }
}
long long abs1(long long x) {
  if (x < 0) {
    return -1 * x;
  }
  return x;
}
long long calcmin(long long cntr[], long long n) {
  long long i;
  long long sum = 0, sum2 = 0;
  for (i = 1; i <= 200; ++i) {
    sum = sum + i * cntr[i];
  }
  for (i = 200; i >= 1; --i) {
    if (n <= cntr[i]) {
      sum2 = sum2 + i * n;
      break;
    } else {
      sum2 = sum2 + i * cntr[i];
      n = n - cntr[i];
    }
  }
  return sum - sum2;
}
int main() {
  long long t;
  t = 1;
  long long n, m, i, j, k, sum0 = 0;
  k = 0;
  while (t-- > 0) {
    cin >> n;
    vector<long long> len, en;
    vector<pair<long long, long long> > srt;
    for (i = 1; i <= n; ++i) {
      cin >> j;
      len.push_back(j);
    }
    for (i = 1; i <= n; ++i) {
      cin >> j;
      en.push_back(j);
      sum0 = sum0 + j;
      pair<long long, long long> foo;
      foo = make_pair(len[i - 1], en[i - 1]);
      srt.push_back(foo);
    }
    sort(srt.begin(), srt.end());
    long long cntr[201];
    long long cntr2[201];
    long long min1 = 1e9, sum1 = 0;
    fill(cntr, cntr + 201, 0);
    fill(cntr2, cntr2 + 201, 0);
    for (i = 1; i <= n; ++i) {
      long long l = srt[i - 1].first;
      long long e = srt[i - 1].second;
      if (i == 1) {
        k = l;
        j = 0;
      }
      if (l == k) {
        ++j;
        ++cntr2[e];
        sum1 = sum1 + e;
      } else {
        long long bj = calcmin(cntr, j - 1) + sum0 - sum1;
        min1 = min(bj, min1);
        for (m = 1; m <= 200; ++m) {
          cntr[m] = cntr2[m] + cntr[m];
          cntr2[m] = 0;
        }
        k = l;
        j = 1;
        ++cntr2[e];
        sum1 = sum1 + e;
      }
    }
    long long bj = calcmin(cntr, j - 1);
    min1 = min(bj, min1);
    cout << min1;
  }
  return 0;
}
