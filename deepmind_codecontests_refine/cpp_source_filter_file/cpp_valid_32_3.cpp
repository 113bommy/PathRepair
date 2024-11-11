#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int mult(int a, int b) { return ((long long int)a * b) % 998244353; }
int modPow(int b, int e) {
  int r = 1;
  while (e > 0) {
    if (e & 1) r = mult(r, b);
    e >>= 1;
    b = mult(b, b);
  }
  return r;
}
int inv(int b) { return modPow(b, 998244353 - 2); }
int mbase, base;
int root, w[1 << 19];
int revb[1 << 19];
int setBase(int nbase) {
  int i, j;
  mbase = 1;
  while (!(998244353 & (1LL << mbase))) mbase++;
  root = 2;
  while ((modPow(root, 1LL << mbase) != 1) ||
         (modPow(root, 1LL << (mbase - 1)) == 1))
    root++;
  base = nbase;
  for (i = 0; i < (1 << base); i++)
    revb[i] = (revb[i >> 1] >> 1) | ((i & 1) << (base - 1));
  w[0] = 0, w[1] = 1;
  for (i = 1; i < nbase; i++) {
    int z = modPow(root, 1LL << (mbase - i - 1));
    for (j = (1 << (i - 1)); j < (1 << i); j++)
      w[j << 1] = w[j], w[(j << 1) | 1] = mult(w[j], z);
  }
  return 0;
}
int FFT(int *a, int n) {
  int i, j, k, l = 0;
  while ((1 << l) < n) l++;
  int s = base - l;
  for (i = 0; i < n; i++) {
    if (i < (revb[i] >> s)) swap(a[i], a[revb[i] >> s]);
  }
  for (k = 1; k < n; k <<= 1) {
    for (i = 0; i < n; i += (k << 1)) {
      for (j = 0; j < k; j++) {
        int z = mult(a[i + j + k], w[j + k]);
        a[i + j + k] = a[i + j] - z, a[i + j] += z;
        if (a[i + j + k] < 0) a[i + j + k] += 998244353;
        if (a[i + j] >= 998244353) a[i + j] -= 998244353;
      }
    }
  }
  for (i = 0; i < n; i++) a[i] %= 998244353;
  return 0;
}
int FFT(vector<int> &a) { return FFT(a.data(), a.size()); }
vector<int> res(const vector<int> &A, int n) {
  vector<int> B = A;
  B.resize(n);
  return B;
}
vector<int> mult(const vector<int> &A, const vector<int> &B) {
  if ((long long int)A.size() * B.size() <= 10000) {
    int i, j;
    vector<int> C(A.size() + B.size() - 1, 0);
    const int *a = A.data(), *b = B.data();
    int *c = C.data();
    for (i = 0; i < A.size(); i++) {
      for (j = 0; j < B.size(); j++) {
        c[i + j] += mult(a[i], b[j]);
        if (c[i + j] >= 998244353) c[i + j] -= 998244353;
      }
    }
    return C;
  }
  int i, n = 1, s = A.size() + B.size() - 1;
  while (n < s) n <<= 1;
  vector<int> A2 = res(A, n), B2 = res(B, n);
  FFT(A2), FFT(B2);
  int x = inv(n);
  for (i = 0; i < n; i++) A2[i] = mult(mult(A2[i], B2[i]), x);
  reverse(A2.begin() + 1, A2.end()), FFT(A2);
  return res(A2, s);
}
vector<int> add(vector<int> a, vector<int> b) {
  int i;
  if (a.size() < b.size()) swap(a, b);
  for (i = 0; i < b.size(); i++) {
    a[i] += b[i];
    if (a[i] >= 998244353) a[i] -= 998244353;
  }
  return a;
}
int a[100000], b[100000];
int inv2[1000000], fact[1000000];
set<pair<int, int> > S;
vector<int> v;
struct info {
  vector<int> p[2][2];
};
info seen0[100005], seen1[100005];
info getAns(int s, int e) {
  if (s == e) {
    int i, j;
    info f;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        f.p[i][j] = vector<int>(3, 0);
        if (i == j) f.p[i][j][i] = 1;
      }
    }
    return f;
  } else if (s == e - 1) {
    int i, j;
    info f;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        f.p[i][j] = vector<int>(3, 0);
        f.p[i][j][i + j] = (v[s + 1] && (i == 0) && (j == 0)) ? inv2[1] : 1;
      }
    }
    return f;
  }
  int i, j, k;
  int mid = (s + e) / 2;
  int z = 0, o = 0;
  for (i = s + 1; i < e; i++) {
    if (v[i] == 0)
      z = 1;
    else
      o = 1;
  }
  if (!z) {
    if (!seen1[e - s].p[0][0].empty()) return seen1[e - s];
  } else if (!o) {
    if (!seen0[e - s].p[0][0].empty()) return seen0[e - s];
  }
  info L = getAns(s, mid), R = getAns(mid, e), f;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++) {
        vector<int> P = mult(L.p[i][k], R.p[k][j]);
        if (k) P.erase(P.begin());
        f.p[i][j] = add(f.p[i][j], P);
      }
    }
  }
  if (!z)
    seen1[e - s] = f;
  else if (!o)
    seen0[e - s] = f;
  return f;
}
int pow2[1000000];
int main() {
  int i;
  int n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]), S.insert(make_pair(a[i], -i));
  setBase(19);
  int j, k;
  fact[0] = pow2[0] = inv2[0] = 1;
  for (i = 1; i < 1000000; i++) {
    fact[i] = ((long long int)i * fact[i - 1]) % 998244353;
    pow2[i] = (2 * pow2[i - 1]) % 998244353;
    inv2[i] = ((long long int)((998244353 + 1) / 2) * inv2[i - 1]) % 998244353;
  }
  while (!S.empty()) {
    pair<int, int> u = *S.rbegin();
    for (i = -u.second; i < -u.second + u.first; i++) {
      if ((i >= n) || (a[i] != u.first) || !S.count(make_pair(a[i], -i))) {
        printf("0\n");
        return 0;
      } else {
        S.erase(make_pair(a[i], -i));
        if (i > -u.second) b[i - 1] = 1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (!b[i]) v.push_back(a[i] == 1);
  }
  if (v.size() == 1) {
    if (n == 1)
      printf("1\n");
    else
      printf("2\n");
    return 0;
  }
  info f = getAns(0, (int)v.size() - 2);
  long long int ans = 0;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < f.p[i][j].size(); k++) {
        if (v[0] && (i == 0))
          f.p[i][j][k] = ((long long int)f.p[i][j][k] * inv2[1]) % 998244353;
        if (v.back() && (j == 0))
          f.p[i][j][k] = ((long long int)f.p[i][j][k] * inv2[1]) % 998244353;
        if (v.size() >= k) {
          if (k & 1)
            ans -= (((long long int)f.p[i][j][k] * fact[v.size() - k]) %
                    998244353) *
                   pow2[v.size() - k];
          else
            ans += (((long long int)f.p[i][j][k] * fact[v.size() - k]) %
                    998244353) *
                   pow2[v.size() - k];
          ans %= 998244353;
        }
      }
    }
  }
  ans %= 998244353;
  if (ans < 0) ans += 998244353;
  printf("%I64d\n", ans);
  return 0;
}
