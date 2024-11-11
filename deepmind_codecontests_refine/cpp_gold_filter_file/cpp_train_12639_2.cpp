#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
char s[100005];
int cnt[30][100005];
long long pw[100005], hh[100005];
long long len[30];
bool gray[30][100005];
long long cost[100005], score[30][100005];
void init() {
  for (int(i) = 0; (i) < (int)(26); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) {
      cnt[i][j + 1] = cnt[i][j] + ((s[j] - 'a') == i);
    }
  pw[0] = 1;
  for (int(j) = 1; (j) <= (int)(n); (j)++) pw[j] = pw[j - 1] * 1000000007;
  for (int(i) = 0; (i) < (int)(n); (i)++)
    hh[i + 1] = hh[i] + pw[i] * (s[i] - 'a');
  len[0] = 1;
  for (int(i) = 1; (i) <= (int)(30); (i)++) len[i] = len[i - 1] * 2 + 1;
}
bool same(int p, int q, int len) {
  if (p > q) swap(p, q);
  if (q + len > n) return 0;
  long long x = (hh[p + len] - hh[p]) * pw[q - p];
  long long y = hh[q + len] - hh[q];
  return x == y;
}
long long cal() {
  for (int(i) = 0; (i) < (int)(16); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++)
      if (j + len[i] <= n) {
        if (i == 0) {
          gray[i][j] = 1;
        } else {
          int p = j, q = j + len[i - 1] + 1;
          if (!gray[i - 1][p] || !gray[i - 1][q] || !same(p, q, len[i - 1]))
            continue;
          int c = s[q - 1] - 'a';
          if (cnt[c][j + len[i]] - cnt[c][p] != 1) continue;
          gray[i][j] = 1;
        }
      }
  long long ans = 0;
  for (int(i) = 0; (i) < (int)(16); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++)
      if (gray[i][j]) {
        long long tmp = len[i] * len[i];
        ans += tmp;
        cost[j] += tmp;
        cost[j + len[i]] -= tmp;
      }
  for (int(i) = 0; (i) < (int)(n); (i)++) cost[i + 1] += cost[i];
  return ans;
}
int com(int p, int q) {
  int ans = 0;
  for (int i = 16; i >= 0; i--) {
    if (same(p, q, ans + (1 << i))) ans += (1 << i);
  }
  return ans;
}
void work(int level, int p) {
  if (level == 0) {
    for (int(i) = 0; (i) < (int)(26); (i)++) score[i][p]++;
    return;
  }
  if (p + len[level] > n) return;
  int d = len[level - 1];
  int q = p + d + 1;
  long long tmp = len[level] * len[level];
  if (gray[level - 1][p] && gray[level - 1][q] && same(p, q, d)) {
    for (int(j) = 0; (j) < (int)(26); (j)++)
      if (cnt[j][q - 1] - cnt[j][p] == 0) {
        score[j][q - 1] += tmp;
      }
  }
  int L = com(p, q);
  if (L >= d) return;
  int p2 = p + L, q2 = q + L;
  if (com(p2 + 1, q2 + 1) + L + 1 < d) return;
  int c = s[q - 1] - 'a';
  if (gray[level - 1][q] && cnt[c][q + d] - cnt[c][q - 1] == 1) {
    score[s[q2] - 'a'][p2] += tmp;
  }
  if (gray[level - 1][p] && cnt[c][q] - cnt[c][p] == 1) {
    score[s[p2] - 'a'][q2] += tmp;
  }
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  init();
  long long ans = cal();
  for (int(i) = 0; (i) < (int)(16); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) work(i, j);
  long long add = 0;
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(26); (j)++)
      if (s[i] - 'a' != j) {
        add = max(add, score[j][i] - cost[i]);
      }
  printf("%lld\n", ans + add);
  return 0;
}
