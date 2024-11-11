#include <bits/stdc++.h>
using namespace std;
const long long maxc = 1000 + 10, inf = 1e9 + 10, T1 = 123, M = 12345, z = 26;
long long n, c;
long long mat[T1][T1];
pair<char, long long> p[maxc];
long long zarib[T1][maxc], tmp[T1][T1], ans[T1][T1];
long long nxt[T1][z];
bool mark[z];
void mul(long long a[T1][T1], long long b[T1][T1]) {
  for (long long i = 0; i < T1; i++) {
    for (long long j = 0; j < T1; j++) {
      tmp[i][j] = 0;
      for (long long k = 0; k < T1; k++) {
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % M;
      }
    }
  }
  for (long long i = 0; i < T1; i++) {
    for (long long j = 0; j < T1; j++) {
      ans[i][j] = tmp[i][j];
    }
  }
}
void power(long long b) {
  if (b == 0) return;
  power(b >> 1);
  mul(ans, ans);
  if (b & 1) {
    mul(ans, mat);
  }
}
int32_t main() {
  scanf("%lld%lld", &n, &c);
  long long zr = 1;
  for (long long i = 0; i < c; i++) {
    scanf(" %c%lld", &p[i].first, &p[i].second);
    mark[p[i].first - 'A'] = 1;
    zr *= p[i].second;
  }
  for (long long i = 0; i < T1; i++) {
    long long mask = i;
    for (long long j = 0; j < c; j++) {
      zarib[i][j] = mask % p[j].second;
      mask /= p[j].second;
    }
  }
  for (long long ch = 0; ch < z; ch++) {
    for (long long i = 0; i < zr; i++) {
      long long mask = 0;
      for (long long j = c - 1; j >= 0; j--) {
        mask *= p[j].second;
        mask += (zarib[i][j] + (p[j].first == ch + 'A')) % p[j].second;
      }
      nxt[i][ch] = mask;
    }
  }
  for (long long i = 0; i < zr; i++) {
    ans[i][i] = 1;
    for (long long ch = 0; ch < z; ch++) {
      if (mark[ch]) {
        mat[i][nxt[i][ch]] = (mat[i][nxt[i][ch]] + 1) % M;
      }
    }
  }
  power(n);
  long long sum = 0;
  for (long long i = 0; i < zr; i++) {
    long long mn[z];
    fill(mn, mn + z, inf);
    for (long long j = 0; j < c; j++) {
      mn[p[j].first - 'A'] = min(mn[p[j].first - 'A'], zarib[i][j]);
    }
    bool ok = 1;
    for (long long ch = 0; ch < z; ch++) {
      if (mark[ch] == 1 && mn[ch] > 0) {
        ok = 0;
      }
    }
    if (ok) {
      sum = (sum + ans[0][i]);
    }
  }
  printf("%lld\n", sum);
}
