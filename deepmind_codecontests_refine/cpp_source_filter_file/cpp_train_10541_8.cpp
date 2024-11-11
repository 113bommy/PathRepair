#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxN = (int)5e2 + 10;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e18;
int dp[maxN][maxN];
int cost[maxN][maxN];
int p[maxN][maxN];
char s[maxN];
int n;
int k;
string transform(int l, int r) {
  string ret = "";
  for (int i = l; i <= r; ++i) {
    ret += s[min(i, r - l + i)];
  }
  return ret;
}
int main() {
  gets(s + 1);
  n = strlen(s + 1);
  scanf("%d", &k);
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      int pleft = l;
      int pright = r;
      int pmid = (l + r) / 2;
      while (pleft <= pmid) {
        if (s[pleft] != s[pright]) {
          cost[l][r]++;
        }
        pleft++;
        pright--;
      }
    }
  }
  fill(dp[0], dp[0] + maxN, INF);
  dp[0][0] = 0;
  for (int r = 1; r <= n; ++r) {
    fill(dp[r], dp[r] + maxN, INF);
    for (int j = 1; j <= min(r, k); ++j) {
      for (int l = r; l >= 1; --l) {
        int val = dp[l - 1][j - 1] + cost[l][r];
        if (val < dp[r][j]) {
          dp[r][j] = val;
          p[r][j] = l;
        }
      }
    }
  }
  int bestK = 1;
  for (int i = 2; i <= k; ++i) {
    if (dp[n][i] < dp[n][bestK]) {
      bestK = i;
    }
  }
  printf("%d\n", dp[n][bestK]);
  vector<string> answer;
  while (n > 0) {
    int l = p[n][bestK];
    answer.push_back(transform(l, n));
    n = l - 1;
    bestK--;
  }
  assert(bestK == 0);
  reverse(answer.begin(), answer.end());
  for (size_t i = 0; i < answer.size(); ++i) {
    printf("%s%c", answer[i].c_str(), "+\n"[i + 1 == answer.size()]);
  }
  return 0;
}
