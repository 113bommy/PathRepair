#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const int MAXN = 1 << 18;
int curr[26];
int L[MAXN][26];
int R[MAXN][26];
int suf_maks[MAXN];
char A[MAXN];
char B[MAXN];
int bad[MAXN];
int dp[MAXN];
vector<char> S[MAXN];
vector<char> D[MAXN];
multiset<char> alive;
int main(void) {
  scanf("%s", A);
  scanf("%s", B);
  int n, m;
  n = strlen(A);
  m = strlen(B);
  for (int i = 0; i < 26; ++i) curr[i] = inf;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) R[i][j] = curr[j];
    curr[A[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; ++i) curr[i] = -inf;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) L[i][j] = curr[j];
    if (i < n) curr[A[i] - 'a'] = i;
  }
  int pr = L[n][B[m - 1] - 'a'];
  int c = 1;
  while (m - c - 1 >= 0 && pr >= 0) {
    dp[pr] = c;
    pr = L[pr][B[m - c - 1] - 'a'];
    ++c;
  }
  if (pr >= 0) dp[pr] = c;
  for (int i = n - 1; i >= 0; --i) dp[i] = max(dp[i + 1], dp[i]);
  int pos = -1;
  for (int i = 0; i < 26; ++i) curr[i] = inf;
  for (int i = n - 1; i >= 0; --i) curr[A[i] - 'a'] = i;
  c = 0;
  while (c < m && pos < n) {
    int nxt;
    if (pos >= 0)
      nxt = R[pos][B[c] - 'a'];
    else
      nxt = curr[B[c] - 'a'];
    int lo, mi, hi;
    lo = 0;
    hi = n;
    while (lo < hi) {
      int mi = (lo + hi) >> 1;
      if (dp[mi] >= m - c - 1)
        lo = mi + 1;
      else
        hi = mi;
    }
    if (nxt <= lo - 1) {
      S[nxt].push_back(B[c]);
      D[lo - 1].push_back(B[c]);
    }
    pos = nxt;
    ++c;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < S[i].size(); ++j) alive.insert(S[i][j]);
    if (alive.find(A[i]) == alive.end()) {
      puts("No");
      return 0;
    }
    for (int j = 0; j < D[i].size(); ++j) alive.erase(alive.find(D[i][j]));
  }
  puts("Yes");
  return 0;
}
