#include <bits/stdc++.h>
using namespace std;
long long smax;
long long v[200005], sp[200005];
long long n, sol = 1, lg, pos = 1, sum1, sum2, lg1, lg2, ind;
long long cmp(long long sum, long long lg, long long _sum, long long _lg);
void caut_bin(long long mx, long long ind);
void calcsum2(long long lg, long long poz);
void calcsum1(long long lg, long long poz);
int main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  sort(v + 1, v + n + 1);
  for (long long i = 1; i <= n; ++i) {
    sp[i] = sp[i - 1] + v[i];
  }
  if (n == 2) {
    cout << 2 << '\n' << v[1] << " " << v[2];
    return 0;
  }
  if (n == 1) {
    cout << 1 << '\n' << v[1];
    return 0;
  }
  for (long long i = 1; i <= n; ++i) caut_bin(min(i - 1, n - i), i);
  cout << sol * 2 + 1 << '\n';
  for (long long i = 1; i <= sol; ++i) {
    cout << v[pos - i] << " ";
  }
  cout << v[pos] << " ";
  for (long long i = 1; i <= sol; ++i) {
    cout << v[n - i + 1] << " ";
  }
  return 0;
}
void caut_bin(long long mx, long long ind) {
  long long i = 0, p = 0;
  for (i = 1; i <= mx; i <<= 1)
    ;
  while (i) {
    if (p + i <= mx) {
      calcsum1(p + i, ind);
      if (p + i < mx) calcsum2(p + i + 1, ind);
      if (p + i == mx && cmp(sum1, 2 * lg1 + 1, sum2, 2 * lg2 + 1) == -1) {
        p += i;
      }
    }
    i >>= 1;
  }
  if (p + 1 <= mx) {
    calcsum1(p + 1, ind);
    sum1 -= (2 * lg1 + 1) * v[ind];
    if (cmp(sum1, 2 * lg1 + 1, smax, 2 * sol + 1) == 1) {
      smax = sum1;
      pos = ind;
      sol = lg1;
    }
  }
}
long long cmp(long long sum, long long lg, long long _sum, long long _lg) {
  long long res = sum * _lg - _sum * lg;
  if (res == 0) return 0;
  return res > 0 ? 1 : -1;
}
void calcsum1(long long lg, long long poz) {
  lg1 = lg;
  sum1 = sp[poz] - sp[poz - lg - 1] + sp[n] - sp[n - lg];
}
void calcsum2(long long lg, long long poz) {
  lg2 = lg;
  sum2 = sp[poz] - sp[poz - lg - 1] + sp[n] - sp[n - lg];
}
