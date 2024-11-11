#include <bits/stdc++.h>
using namespace std;
int N, R, C;
string W[1000010];
int L[1000010];
int dp[1000010][25];
char tmp[5000010];
int main() {
  while (3 == scanf("%d%d%d", &N, &R, &C)) {
    for (int i = 0; i < (int)(N); i++) {
      scanf("%s", tmp);
      W[i] = tmp;
      L[i] = W[i].length();
    }
    int j = 0, s = 0;
    for (int i = 0; i < (int)(N); i++) {
      if (j < i) {
        j = i;
        s = 0;
      }
      while (j < N && (s + L[j]) <= C) {
        s += L[j] + 1;
        ++j;
      }
      dp[i][0] = j;
      if (j > i) s -= (L[i] + 1);
    }
    dp[N][0] = N;
    for (int k = 1; (1 << k) <= R; ++k) {
      for (int i = 0; i < (int)(N + 1); i++) dp[i][k] = dp[dp[i][k - 1]][k - 1];
    }
    int ans_i = 0, ans_k = 0;
    for (int i = 0; i < (int)(N); i++) {
      int j = i;
      for (int k = 1; (1 << k) <= R; ++k)
        if (R & (1 << k)) j = dp[j][k];
      int k = j - i;
      if (k > ans_k) {
        ans_k = k;
        ans_i = i;
      }
    }
    int r = 0, c = 0;
    for (int i = ans_i; i < N; ++i) {
      if (c + L[i] > C) {
        puts("");
        if (L[i] > C) goto done;
        ++r;
        if (r >= R) goto done;
        printf("%s", W[i].c_str());
        c = L[i] + 1;
      } else {
        if (c == 0) {
          printf("%s", W[i].c_str());
          c += L[i] + 1;
        } else {
          printf(" %s", W[i].c_str());
          c += L[i] + 1;
        }
      }
    }
    puts("");
  done:;
  }
  return 0;
}
