#include <bits/stdc++.h>
const int mod = 1000000007;
int a[1000010];
int f[1 << 17], xo[1 << 17], oo[1 << 17], ao[1 << 17], da[1 << 17], db[1 << 17];
int sg[1 << 17];
const int N = 1 << 17;
const long long M = 742744451;
void cx(int *d, int inv = 0) {
  for (int l = 1; 2 * l <= N; l <<= 1) {
    for (int i = 0; i < N; i += 2 * l) {
      for (int j = 0; j < l; j++) {
        int &u = d[i + j], &v = d[i + j + l];
        int nu = u + v;
        if (nu >= mod) {
          nu -= mod;
        }
        int nv = u - v;
        if (nv < 0) {
          nv += mod;
        }
        u = nu;
        v = nv;
      }
    }
  }
  if (inv) {
    for (int i = 0; i < N; i++) {
      d[i] = d[i] * M % mod;
    }
  }
}
void ca(int *d) {
  for (int l = 1; 2 * l <= N; l <<= 1) {
    for (int i = 0; i < N; i += 2 * l) {
      for (int j = 0; j < l; j++) {
        int &u = d[i + j], &v = d[i + j + l];
        int nu = v;
        int nv = u + v;
        if (nv >= mod) {
          nv -= mod;
        }
        u = nu;
        v = nv;
      }
    }
  }
}
void cainv(int *d) {
  for (int l = 1; 2 * l <= N; l <<= 1) {
    for (int i = 0; i < N; i += 2 * l) {
      for (int j = 0; j < l; j++) {
        int &u = d[i + j], &v = d[i + j + l];
        int nu = -u + v;
        if (nu < 0) nu += mod;
        int nv = u;
        u = nu;
        v = nv;
      }
    }
  }
}
void cr(int *d) {
  for (int l = 1; 2 * l <= N; l <<= 1) {
    for (int i = 0; i < N; i += 2 * l) {
      for (int j = 0; j < l; j++) {
        int &u = d[i + j], &v = d[i + j + l];
        int nu = u + v;
        int nv = v;
        if (nu >= mod) {
          nv += mod;
        }
        u = nu;
        v = nv;
      }
    }
  }
}
void crinv(int *d) {
  for (int l = 1; 2 * l <= N; l <<= 1) {
    for (int i = 0; i < N; i += 2 * l) {
      for (int j = 0; j < l; j++) {
        int &u = d[i + j], &v = d[i + j + l];
        int nu = v;
        int nv = u + v;
        if (nv < 0) {
          nv += mod;
        }
        u = nu;
        v = nv;
      }
    }
  }
}
void add(int &v, int x) {
  v += x;
  if (v >= mod) v -= mod;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sg[a[i]]++;
  }
  f[1] = 1;
  for (int i = 2; i < 1 << 17; i++) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] >= mod) f[i] -= mod;
  }
  for (int i = 0; i < 1 << 17; i++) {
    xo[i] = sg[i];
  }
  cx(xo);
  for (int i = 0; i < 1 << 17; i++) {
    xo[i] = (long long)xo[i] * xo[i] % mod;
  }
  cx(xo, 1);
  for (int i = 0; i < 1 << 17; i++) {
    xo[i] = (long long)xo[i] * f[i] % mod;
  }
  for (int i = 0; i < 1 << 17; i++) {
    oo[i] = (long long)sg[i] * f[i] % mod;
  }
  ca(xo);
  ca(oo);
  for (int i = 0; i < 1 << 17; i++) {
    oo[i] = (long long)oo[i] * xo[i] % mod;
  }
  cainv(oo);
  for (int i = 0; i < 1 << 17; i++) {
    for (int j = i;; j = i & (j - 1)) {
      ao[i] += (long long)sg[j] * sg[i ^ j] % mod;
      if (ao[i] >= mod) {
        ao[i] -= mod;
      }
      if (!j) break;
    }
  }
  for (int i = 0; i < 1 << 17; i++) {
    ao[i] = (long long)ao[i] * f[i] % mod;
  }
  int ans = 0;
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 1 << 17; j++) {
      da[j] = 0;
    }
    for (int j = 0; j < 1 << 17; j++) {
      if (j >> i & 1) {
        add(da[j ^ (1 << i)], oo[j]);
      }
    }
    for (int j = 0; j < 1 << 17; j++) {
      db[j] = 0;
    }
    for (int j = 0; j < 1 << 17; j++) {
      if (j >> i & 1) {
        add(db[j ^ (1 << i)], ao[j]);
      }
    }
    ca(da);
    ca(db);
    for (int j = 0; j < 1 << 17; j++) {
      da[j] = (long long)da[j] * db[j] % mod;
    }
    cainv(da);
    ans += da[0];
    if (ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
  return 0;
}
