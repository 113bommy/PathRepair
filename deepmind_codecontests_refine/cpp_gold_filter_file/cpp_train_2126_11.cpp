#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int M = N + 7;
const int MOD = 1e9 + 7;
const long long INF = 1e16 + 17;
const int K = 5;
void ex() {
  printf("-1\n");
  exit(0);
}
int a[M];
int l[M], r[M], len[M];
int an[M];
bool dp[M][K + 3];
pair<int, int> par[M][K + 3];
bool cmp(int i, int j) { return l[i] < l[j]; }
void fillLR(int tl, int tr, int cnt, int st) {
  if (tl > tr) return;
  int d = tr - tl + 1;
  int cur = d / cnt;
  for (int i = st; i < st + cnt; ++i) {
    int x = cur + (d % cnt > i - st);
    while (x-- && tl <= tr) an[tl++] = i;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    l[a[i]] = l[a[i]] ? l[a[i]] : i;
    r[a[i]] = i;
  }
  vector<int> ord;
  for (int i = 1; i <= N; ++i) {
    if (l[i]) {
      len[i] = r[i] - l[i] + 1;
      ord.push_back(i);
    }
    if (len[i] > 5) ex();
  }
  l[0] = -4;
  r[0] = 0;
  len[0] = K;
  ord.push_back(0);
  sort(ord.begin(), ord.end(), cmp);
  for (int t = 1; t < (int)ord.size(); ++t) {
    if (l[ord[t]] <= r[ord[t - 1]]) ex();
  }
  dp[0][0] = true;
  int m = (int)ord.size() - 1;
  for (int t = 1; t <= m; ++t) {
    int i = ord[t];
    int j = ord[t - 1];
    for (int rr = 0; rr + len[j] <= K; ++rr) {
      if (!dp[t - 1][rr]) continue;
      for (int tr = 0; tr + len[i] <= K; ++tr) {
        for (int tl = 0; tl + tr + len[i] <= K; ++tl) {
          if (tr + tl + len[i] < 2) continue;
          int dist = (l[i] - tl) - (r[j] + rr) - 1;
          int cnt = i - j - 1;
          if (cnt * 2 <= dist && dist <= cnt * 5) {
            dp[t][tr] = true;
            par[t][tr] = make_pair(tl, rr);
          }
        }
      }
    }
  }
  int ans = 0, k = 0;
  for (int tr = 0; tr + len[ord[m]] <= K && r[ord[m]] + tr <= n; ++tr) {
    if (dp[m][tr]) {
      int len = n - r[ord[m]] - tr;
      if (len != 1) {
        fillLR(r[ord[m]] + tr + 1, n, len / 2, ord[m] + 1);
        k = tr;
        ans = ord[m] + len / 2;
        break;
      }
    }
  }
  if (!ans) ex();
  while (m) {
    int cnt = ord[m] - ord[m - 1] - 1;
    pair<int, int> cur = par[m][k];
    fillLR(l[ord[m]] - cur.first, r[ord[m]] + k, 1, ord[m]);
    fillLR(r[ord[m - 1]] + cur.second + 1, l[ord[m]] - cur.first - 1, cnt,
           ord[m - 1] + 1);
    m--;
    k = cur.second;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) printf("%d ", an[i]);
  printf("\n");
  return 0;
}
