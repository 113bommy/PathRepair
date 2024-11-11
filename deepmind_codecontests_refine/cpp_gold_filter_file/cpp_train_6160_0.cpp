#include <bits/stdc++.h>
using namespace std;
long long my_pow(long long x, long long e, int mod) {
  long long ans = 1;
  for (; e; e >>= 1) {
    if (e & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
  }
  return ans;
}
int mod;
long long W[31];
void reset(int k, int p, int root) {
  mod = p;
  W[k] = root;
  for (int i = k - 1; i >= 0; --i) W[i] = W[i + 1] * W[i + 1] % mod;
}
vector<long long> tmp;
void bad_fft(vector<long long>& a, int sp, int st) {
  long long wn = W[0];
  for (int i = sp; i < a.size(); i += st) {
    tmp[i] = 0;
    long long wj = my_pow(wn, (i - sp) / st, mod);
    long long w = 1;
    for (int j = sp; j < a.size(); j += st) {
      tmp[i] += w * a[j];
      tmp[i] %= mod;
      w = (w * wj) % mod;
    }
  }
  for (int i = sp; i < a.size(); i += st) a[i] = tmp[i];
}
void fft(vector<long long>& a, int sp = 0, int st = 1) {
  int N = a.size() / st;
  if (N & 1) {
    bad_fft(a, sp, st);
    return;
  }
  fft(a, sp, 2 * st);
  fft(a, sp + st, 2 * st);
  int n = __builtin_ctz(N);
  int mid = st * (N / 2);
  long long wn = W[n], w = 1;
  for (int i = 0; i < N / 2; ++i) {
    tmp[st * i + sp] = a[st * 2 * i + sp] + w * a[st * (2 * i + 1) + sp];
    tmp[st * i + sp + mid] = a[st * 2 * i + sp] - w * a[st * (2 * i + 1) + sp];
    w = (w * wn) % mod;
  }
  for (int i = sp; i < a.size(); i += st) a[i] = (tmp[i] % mod + mod) % mod;
}
int n, m;
string a, b;
vector<long long> A, B;
void reset_vec() {
  int n = mod - 1;
  A.resize(n);
  B.resize(n);
  tmp.resize(n);
  for (int i = 0; i < n; ++i)
    A[i] = (i >= ::n ? 0 : a[i] - 'a'), B[i] = (i >= ::n ? 0 : b[i] - 'a');
}
int solve() {
  reset_vec();
  fft(A);
  fft(B);
  int k = __builtin_ctz(mod - 1);
  for (int j = 1; j < mod - 1; ++j) {
    if (A[j] == B[j]) return my_pow(W[k], j, mod);
  }
  return -42;
}
const int mods[13] = {
    13313,   18433,  12289,   40961,   114689,   163841,    65537,
    1179649, 786433, 5767169, 7340033, 23068673, 104857601,
};
const int roots[13] = {
    3, 5, 11, 3, 3, 3, 3, 19, 10, 3, 3, 3, 3,
};
int main() {
  cin >> n >> m;
  cin >> a >> b;
  for (int i = 0; i < 13; ++i) {
    if (mods[i] < m) continue;
    reset(10 + i, mods[i], roots[i]);
    int x = solve();
    if (x == -42) continue;
    cout << mod << ' ' << x << '\n';
    return 0;
  }
  cout << -42 << '\n';
}
