#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int ans[MAXN][MAXN];
int N, D, K;
int main(void) {
  scanf("%d%d%d", &N, &K, &D);
  if (N > 1 && K == 1) {
    printf("-1\n");
    return 0;
  }
  int rep = 1;
  bool possible = false;
  for (int i = 0; i < D; ++i) {
    int curr = 0;
    int pos = 0;
    bool ok = true;
    while (pos < N) {
      for (int j = 0; pos < N && j < rep; ++j) {
        ans[i][pos++] = curr + 1;
      }
      ++curr;
      if (curr == K) {
        if (pos < N) ok = false;
        curr = 0;
      }
    }
    if (rep >= N || rep * K >= N) ok = true;
    possible |= ok;
    if (rep >= N || rep * K >= N)
      rep = N;
    else
      rep *= K;
  }
  if (!possible) {
    printf("-1\n");
  } else {
    for (int i = 0; i < D; ++i) {
      for (int j = 0; j < N; ++j) printf("%d%c", ans[i][j], " \n"[j + 1 == N]);
    }
  }
  return 0;
}
