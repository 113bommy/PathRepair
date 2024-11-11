#include <bits/stdc++.h>
using namespace std;
const int m[3] = {1004535809, 998244353, 104857601};
int qpow(int x, int k, int P) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1LL * ret * x % P;
    k >>= 1;
    x = 1LL * x * x % P;
  }
  return ret;
}
struct _NTT {
  int wn[25], P;
  void init(int _P) {
    P = _P;
    for (int i = 1; i <= 21; ++i) {
      int t = 1 << i;
      wn[i] = qpow(3, (P - 1) / t, P);
    }
  }
  void change(int *y, int len) {
    for (int i = 1, j = len / 2; i < len - 1; ++i) {
      if (i < j) swap(y[i], y[j]);
      int k = len / 2;
      while (j >= k) {
        j -= k;
        k /= 2;
      }
      j += k;
    }
  }
  void NTT(int *y, int len, int on) {
    change(y, len);
    int id = 0;
    for (int h = 2; h <= len; h <<= 1) {
      ++id;
      for (int j = 0; j < len; j += h) {
        int w = 1;
        for (int k = j; k < j + h / 2; ++k) {
          int u = y[k];
          int t = 1LL * y[k + h / 2] * w % P;
          y[k] = u + t;
          if (y[k] >= P) y[k] -= P;
          y[k + h / 2] = u - t + P;
          if (y[k + h / 2] >= P) y[k + h / 2] -= P;
          w = 1LL * w * wn[id] % P;
        }
      }
    }
    if (on == -1) {
      for (int i = 1; i < len / 2; ++i) swap(y[i], y[len - i]);
      int inv = qpow(len, P - 2, P);
      for (int i = 0; i < len; ++i) y[i] = 1LL * y[i] * inv % P;
    }
  }
  void mul(int A[], int B[], int len) {
    NTT(A, len, 1);
    NTT(B, len, 1);
    for (int i = 0; i < len; ++i) A[i] = 1LL * A[i] * B[i] % P;
    NTT(A, len, -1);
  }
} ntt[3];
int tmp[(1000000 + 10)][3], t1[(1000000 + 10)], t2[(1000000 + 10)];
int r[3][3];
int CRT(int a[]) {
  int x[3];
  for (int i = 0; i < 3; ++i) {
    x[i] = a[i];
    for (int j = 0; j < i; ++j) {
      int t = (x[i] - x[j]) % m[i];
      if (t < 0) t += m[i];
      x[i] = 1LL * t * r[j][i] % m[i];
    }
  }
  int mul = 1, ret = x[0] % 1000000007;
  for (int i = 1; i < 3; ++i) {
    mul = 1LL * mul * m[i - 1] % 1000000007;
    ret += 1LL * x[i] * mul % 1000000007;
    if (ret >= 1000000007) ret -= 1000000007;
  }
  return ret;
}
void mul(int A[], int B[], int len) {
  for (int id = 0; id < 3; ++id) {
    for (int i = 0; i < len; ++i) {
      t1[i] = A[i];
      t2[i] = B[i];
    }
    ntt[id].mul(t1, t2, len);
    for (int i = 0; i < len; ++i) tmp[i][id] = t1[i];
  }
  for (int i = 0; i < len; ++i) {
    A[i] = CRT(tmp[i]);
  }
}
void init() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < i; ++j) {
      r[j][i] = qpow(m[j], m[i] - 2, m[i]);
    }
  }
  for (int i = 0; i < 3; ++i) {
    ntt[i].init(m[i]);
  }
}
int ff[(1000000 + 10)], nff[(1000000 + 10)];
int dp[(1000000 + 10)];
int ans[(1000000 + 10)];
int pow2[(1000000 + 10)];
int ta[(1000000 + 10)], tb[(1000000 + 10)];
void mymul(int *A, int *B, int k, int lb) {
  int tlen = 1;
  while (tlen < (k + 1) * 2) tlen <<= 1;
  for (int i = 0; i <= tlen; ++i) ta[i] = tb[i] = 0;
  for (int i = 0; i <= k; ++i)
    ta[i] = 1LL * A[i] * nff[i] % 1000000007 * qpow(2, i * lb, 1000000007) %
            1000000007;
  for (int i = 0; i <= k; ++i) tb[i] = 1LL * B[i] * nff[i] % 1000000007;
  mul(ta, tb, tlen);
  for (int i = 0; i <= k; ++i) A[i] = 1LL * ta[i] * ff[i] % 1000000007;
}
int main() {
  long long nn;
  int n, k;
  scanf("%I64d%d", &nn, &k);
  if (nn > k) {
    puts("0");
    return 0;
  }
  n = nn;
  ff[0] = nff[0] = 1;
  for (int i = 1; i <= k * 30; ++i)
    ff[i] = 1LL * ff[i - 1] * i % 1000000007,
    nff[i] = qpow(ff[i], 1000000007 - 2, 1000000007);
  pow2[0] = 1;
  for (int i = 1; i <= k * 30; ++i)
    pow2[i] = 1LL * pow2[i - 1] * 2 % 1000000007;
  for (int i = 1; i <= k; ++i) dp[i] = 1;
  init();
  int len = 1;
  ans[0] = 1;
  for (int z = n; z; z >>= 1) {
    if (z & 1) {
      mymul(ans, dp, k, len);
    }
    mymul(dp, dp, k, len);
    len += len;
  }
  int res = 0;
  for (int i = 0; i <= k; ++i)
    res = (res + 1LL * ans[i] * ff[k] % 1000000007 * nff[i] % 1000000007 *
                     nff[k - i] % 1000000007) %
          1000000007;
  printf("%d\n", res);
}
