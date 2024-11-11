#include <bits/stdc++.h>
using namespace std;
int A[100005];
vector<pair<pair<int, int>, int>> que[100005];
const int DIV = 3162;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  int aa = a.first.first / DIV, bb = b.first.first / DIV;
  if (aa != bb) return aa < bb;
  return a.first.second < b.first.second;
}
long long power, ans[100005];
int freq[100005];
const long long MOD = 998244353;
const int MAXN = 100005;
long long fac[MAXN], invfac[MAXN];
long long inv[MAXN];
void add(int p) {
  int v = A[p];
  power = power * freq[v] % MOD;
  --freq[v];
}
void rem(int p) {
  int v = A[p];
  ++freq[v];
  power = power * inv[freq[v]] % MOD;
}
int tot[MAXN];
long long tt[MAXN];
long long modex(long long a, long long p, long long m = MOD) {
  if (!p) return 1;
  if (p & 1) return a * modex(a, p - 1, m) % m;
  long long v = modex(a, p >> 1, m);
  return v * v % m;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; ++i) fac[i] = (fac[i - 1] * i) % MOD;
  invfac[MAXN - 1] = modex(fac[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 0; --i)
    invfac[i] = (invfac[i + 1] * (i + 1)) % MOD;
  for (int i = 1; i < MAXN; ++i) inv[i] = invfac[i] * fac[i - 1] % MOD;
  int N, M, Q;
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    ++tot[A[i]];
  }
  for (int q = 0; q < Q; ++q) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    que[k].push_back({{l, r}, q});
  }
  for (int i = 0; i <= 100000; ++i) {
    auto &queries = que[i];
    if (queries.empty()) continue;
    sort(queries.begin(), queries.end(), cmp);
    tt[0] = 1;
    long long val = (long long)M * i % MOD;
    for (int j = 1; j <= 100000; ++j) {
      val = (val + 1) % MOD;
      freq[j] = i + tot[j];
      tt[j] = tt[j - 1] * val % MOD;
    }
    power = 1;
    int lef = 1, rig = 0;
    for (int q = 0; q < queries.size(); ++q) {
      int l = queries[q].first.first, r = queries[q].first.second;
      while (rig < r) add(++rig);
      while (rig > r) rem(rig--);
      while (lef < l) rem(lef++);
      while (lef > l) add(--lef);
      ans[queries[q].second] = power * tt[N - (r - l + 1)] % MOD;
    }
  }
  for (int q = 0; q < Q; ++q) printf("%lld\n", ans[q]);
}
