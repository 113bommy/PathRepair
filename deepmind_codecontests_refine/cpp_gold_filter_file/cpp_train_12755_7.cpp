#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1007;
const int MOD = 998244353;
int n, k, a[NMAX];
int pow1(long long x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * x % MOD;
    x = (long long)x * x % MOD;
    k >>= 1;
  }
  return res;
}
vector<int> v, x;
void FFT(vector<int> &a, int Inv) {
  v.clear();
  v.resize(a.size());
  for (int i = 2; i <= a.size(); i <<= 1) {
    int num = a.size() / i;
    int root = pow1(3, (MOD - 1) / i);
    if (Inv) root = pow1(root, MOD - 2);
    for (int j = 0; j < num; j++) {
      for (int k = 0; k < i; k++) v[k] = a[j + k * num];
      int cur = 1;
      for (int k = 0; k < i / 2; k++) {
        int t1 = v[k * 2];
        int t2 = (long long)cur * v[k * 2 + 1] % MOD;
        a[j + k * num] = (t1 + t2) % MOD;
        a[j + k * num + a.size() / 2] = (t1 - t2 + MOD) % MOD;
        cur = (long long)cur * root % MOD;
      }
    }
  }
  if (Inv) {
    int go = pow1(a.size(), MOD - 2);
    for (int i = 0; i < a.size(); i++) a[i] = (long long)a[i] * go % MOD;
  }
}
vector<int> operator*(vector<int> a, vector<int> b) {
  int sz = 1;
  while (sz < max(a.size(), b.size())) sz <<= 1;
  sz <<= 1;
  a.resize(sz);
  b.resize(sz);
  FFT(a, 0);
  FFT(b, 0);
  for (int i = 0; i < sz; i++) a[i] = (long long)a[i] * b[i] % MOD;
  FFT(a, 1);
  return a;
}
vector<int> pow2(vector<int> x, int k) {
  vector<int> res;
  res.push_back(1);
  while (k) {
    for (int i = 0; i < x.size(); i++)
      if (x[i] > 1) x[i] = 1;
    for (int i = 0; i < res.size(); i++)
      if (res[i] > 1) res[i] = 1;
    if (k & 1) res = res * x;
    x = x * x;
    k >>= 1;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  x.resize(NMAX);
  while (n--) {
    int u;
    scanf("%d", &u);
    x[u] = 1;
  }
  vector<int> sol = pow2(x, k);
  for (int i = 1; i < sol.size(); i++)
    if (sol[i] > 0) printf("%d ", i);
  return 0;
}
