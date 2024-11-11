#include <bits/stdc++.h>
using namespace std;
int rev(int k, int siz) {
  int sol = 0, log = log2(siz) - 1;
  while (k) {
    if (k & 1) sol += 1 << log;
    k >>= 1;
    log--;
  }
  return sol;
}
long long pow_mod(long long a, long long b) {
  long long ret = 1;
  a %= 7340033;
  for (; b > 0; b >>= 1) {
    if (b % 2) ret = (ret * a) % 7340033;
    a = (a * a) % 7340033;
  }
  return ret;
}
void FFT(vector<long long> &a, bool inverse) {
  int n = a.size();
  if (n == 1) return;
  for (int i = 0; i < n; i++)
    if (i < rev(i, n)) swap(a[i], a[rev(i, n)]);
  for (int len = 2; len <= n; len <<= 1) {
    long long wlen = inverse ? 4404020 : 5;
    for (int i = len; i < (1 << 20); i <<= 1) {
      wlen = (wlen * wlen) % 7340033;
    }
    for (int i = 0; i < n; i += len) {
      long long w = 1;
      for (int j = 0; j < len / 2; ++j) {
        long long u = a[i + j], v = (a[i + j + len / 2] * w) % 7340033;
        a[i + j] = (u + v) % 7340033;
        a[i + j + len / 2] = (u - v + 7340033) % 7340033;
        w = (w * wlen) % 7340033;
      }
    }
  }
  if (inverse) {
    long long revn = pow_mod(n, 7340033 - 2);
    for (int i = 0; i < n; ++i) a[i] = (a[i] * revn) % 7340033;
  }
}
vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
  vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  fa.resize(n), fb.resize(n);
  FFT(fa, false);
  FFT(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  FFT(fa, true);
  vector<long long> res(min(n, 1000));
  for (int i = 0; i < min(n, 1000); i++) res[i] = fa[i] % 7340033;
  return res;
}
vector<long long> dp[33];
int t, N, k;
vector<long long> solve(int n) {
  vector<long long> ret;
  if (n == 0) {
    ret.push_back(1);
    return ret;
  }
  ret = solve(n - 1);
  ret = multiply(ret, ret);
  ret = multiply(ret, ret);
  ret.insert(ret.begin(), 1);
  return dp[n] = ret;
}
int SHAZAM(int n) {
  int ans = 0;
  while (n != 1 && n % 2 > 0) {
    ans++;
    n /= 2;
  }
  return ans;
}
int main() {
  scanf("%d", &t);
  solve(32);
  while (t--) {
    scanf("%d %d", &N, &k);
    int idx = SHAZAM(N);
    printf("%lld\n", (k < dp[idx].size()) ? dp[idx][k] : 0);
  }
  return 0;
}
