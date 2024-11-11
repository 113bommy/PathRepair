#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int a[102], b[102];
int main() {
  int N, M, K, i, j, sum, fg, tp, ct;
  scanf("%d %d", &N, &M);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  sum = 0;
  for (i = 0; i < M; i++) {
    scanf("%d", &b[i]);
    sum += b[i];
  }
  tp = N - sum;
  for (i = 0; i <= tp; i++) {
    ct = i + sum;
    for (j = i; j < ct; j++) {
      m[a[j]]++;
    }
    fg = 1;
    for (j = 0; j < M; j++) {
      if (b[j] != m[j + 1]) {
        fg = 0;
        break;
      }
    }
    if (fg) {
      printf("YES");
      return 0;
    }
    for (j = i; j < ct; j++) {
      m[a[j]] = 0;
    }
  }
  printf("NO");
  return 0;
}
