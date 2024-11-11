#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
const int MAXN = 2e5 + 100;
const int MAXM = 1e6 + 100;
bool prime[MAXM];
int dv[MAXM];
long long c[MAXN];
long long fact[MAXN];
long long MOD = 1e9 + 7;
int nd[MAXM];
int ans[MAXM];
int old[MAXM];
long long mpow(long long x, long long d) {
  if (d == 0) return 1;
  if (d % 2 == 0) {
    long long h = mpow(x, d / 2);
    return h * h % MOD;
  }
  return x * mpow(x, d - 1) % MOD;
}
long long inv(long long x) { return mpow(x, MOD - 2); }
vector<int> divs[MAXM];
void norm(int& a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
void norm(long long& a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
int main() {
  for (int i = 2; i < MAXM; ++i) {
    prime[i] = true;
  }
  for (int i = 2; i < MAXM; ++i) {
    if (!prime[i]) continue;
    for (int j = i + i; j < MAXM; j += i) {
      prime[j] = false;
      dv[j] = i;
    }
  }
  divs[1] = {1};
  for (int i = 2; i < MAXM; ++i) {
    if (prime[i]) {
      divs[i] = {i, 1};
      continue;
    }
    int d = dv[i];
    int p = i;
    int c = 0;
    while (p % d == 0) {
      p /= d;
      c++;
    }
    int pw = 1;
    for (int _ = int(0); _ < int(c + 1); ++_) {
      for (auto x : divs[p]) {
        divs[i].push_back(x * pw);
      }
      pw *= d;
    }
    sort(divs[i].begin(), divs[i].end());
    reverse(divs[i].begin(), divs[i].end());
  }
  int n, k, q;
  scanf("%d%d%d", &n, &k, &q);
  fact[0] = 1;
  for (int i = int(0); i < int(MAXN - 1); ++i) {
    fact[i + 1] = fact[i] * (i + 1) % MOD;
  }
  for (int i = int(0); i < int(MAXN - 1); ++i) {
    if (i < k)
      c[i] = 0;
    else {
      c[i] = fact[i] * inv(fact[i - k]) % MOD * inv(fact[k]) % MOD;
    }
  }
  for (int i = int(0); i < int(n); ++i) {
    int a;
    scanf("%d", &a);
    for (auto d : divs[a]) {
      nd[d]++;
    }
  }
  for (int i = int(0); i < int(MAXM); ++i) {
    ans[i] = c[nd[i]];
  }
  long long res = 0;
  for (int i = MAXM - 1; i >= 1; --i) {
    res += ((long long)ans[i]) * i;
    res %= MOD;
    for (auto d : divs[i]) {
      if (d == i) continue;
      ans[d] -= ans[i];
      if (ans[d] < 0) ans[d] += MOD;
    }
  }
  for (int i = int(0); i < int(q); ++i) {
    int C;
    scanf("%d", &C);
    for (auto d : divs[C]) {
      old[d] = ans[d];
    }
    for (auto d : divs[C]) {
      ans[d] += -c[nd[d]] + c[nd[d] + 1];
      norm(ans[d]);
      res += ((long long)(-old[d] + ans[d])) * d % MOD;
      norm(res);
      nd[d]++;
      for (auto d2 : divs[d]) {
        if (d2 == d) continue;
        ans[d2] += old[d] - ans[d];
        norm(ans[d2]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
