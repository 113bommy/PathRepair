#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int N, SA[MAXN], lcp[MAXN];
char S[MAXN];
int cnt[MAXN], a[2][MAXN];
void SuffixArray() {
  int i, j, k;
  int m = 255;
  int *x = a[0], *y = a[1];
  for (i = 1; i <= N; i++) cnt[x[i] = S[i]]++;
  for (i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (i = N; i; i--) SA[cnt[x[i]]--] = i;
  int bit = 1;
  for (int len = 1, p = 1; p < N; len <<= 1, m = p) {
    for (p = 0, i = N - len; ++i <= N;) y[++p] = i;
    for (i = 1; i <= N; i++)
      if (SA[i] > len) y[++p] = SA[i] - len;
    for (i = 0; i <= m; i++) cnt[i] = 0;
    for (i = 1; i <= N; i++) cnt[x[y[i]]]++;
    for (i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (i = N; i; i--) SA[cnt[x[y[i]]]--] = y[i];
    x = a[bit];
    y = a[bit ^ 1];
    bit ^= 1;
    p = 1;
    x[SA[1]] = 1;
    for (i = 1; i < N; i++)
      x[SA[i + 1]] = SA[i] + len <= N && SA[i + 1] + len <= N &&
                             y[SA[i]] == y[SA[i + 1]] &&
                             y[SA[i] + len] == y[SA[i + 1] + len]
                         ? p
                         : ++p;
  }
}
int mrank[MAXN];
void LCP() {
  int i, j, k = 0;
  for (i = 1; i <= N; i++) mrank[SA[i]] = i;
  for (i = 1; i <= N; lcp[mrank[i++]] = k)
    for (k ? k-- : 0, j = SA[mrank[i] - 1]; S[i + k] == S[j + k]; k++)
      ;
}
int pre[MAXN];
int maxInd[MAXN];
vector<int> ind[MAXN * 2];
void solve() {
  scanf("%d %s ", &N, S + 1);
  int n = N;
  SuffixArray();
  LCP();
  ind[MAXN].push_back(0);
  for (int i = 1; i <= N; ++i) {
    pre[i] = pre[i - 1] + (S[i] == '(' ? 1 : -1);
    ind[pre[i] + MAXN].push_back(i);
  }
  map<int, int> H;
  for (int i = N; i; --i) {
    if (H.count(pre[i - 1] - 1)) {
      maxInd[i] = H[pre[i - 1] - 1];
    } else {
      maxInd[i] = N + 1;
    }
    H[pre[i]] = i;
  }
  long long ret = 0;
  for (int i = 1; i <= N; ++i) {
    int x = pre[SA[i] - 1] + MAXN;
    int maxi = max(maxInd[SA[i]], SA[i] + lcp[i]);
    int g = lower_bound(ind[x].begin(), ind[x].end(), maxi) -
            lower_bound(ind[x].begin(), ind[x].end(), SA[i] + lcp[i]);
    if (S[SA[i]] != '(') break;
    ret += g;
  }
  printf("%lld\n", ret);
}
int main() {
  solve();
  return 0;
}
