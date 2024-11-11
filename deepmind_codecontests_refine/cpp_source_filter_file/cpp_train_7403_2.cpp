#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int T, N, M, K;
char s[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &N, &M, &K);
    scanf("%s", (s + 1));
    vector<int> cnt(26, 0);
    for (int i = 1; i <= K; ++i) ++cnt[s[i] - 'A'];
    vector<int> DP(K + 1);
    DP[0] = 1;
    for (int i = 0; i <= 25; ++i) {
      if (!cnt[i]) continue;
      for (int j = K; j >= cnt[i]; --j) {
        DP[j] |= DP[j - cnt[i]];
      }
    }
    int ok = 0;
    for (int i = N; i <= K; ++i) {
      if (DP[i] && K - i >= M) {
        ok = 1;
      }
    }
    if (ok) {
      printf("0\n");
    } else {
      int ret = N * M;
      for (int i = 0; i <= 25; ++i) {
        if (!cnt[i]) continue;
        for (int j = 1; j <= K; ++j) DP[j] = 0;
        for (int ni = 0; ni <= 25; ++ni) {
          if (ni == i) continue;
          if (!cnt[ni]) continue;
          for (int j = K; j >= cnt[ni]; --j) {
            DP[j] |= DP[j - cnt[ni]];
          }
        }
        int sz = K - cnt[i];
        for (int j = N - cnt[i]; j <= N - 1; ++j) {
          if (DP[j]) {
            int dr = N - j;
            int dc = M - (sz - j);
            if (dc <= 0) continue;
            ret = min(ret, dr * dc);
            if (0) cout << dr << " " << dc << endl;
          }
        }
      }
      printf("%d\n", ret);
    }
  }
}
