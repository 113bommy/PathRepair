#include <bits/stdc++.h>
using namespace std;
const int MAX = 2005;
int N, M, K;
char row[MAX];
int ans[MAX];
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%s", row + 1);
    for (int j = 1; j <= M; j++) {
      if (row[j] == 'U') {
        ans[j] += (i > 2);
      }
      if (row[j] == 'R') {
        if (j + i - 1 <= M) ans[j + i - 1]++;
      }
      if (row[j] == 'L') {
        if (j - i + 1 > 0) ans[j - i + 1]++;
      }
    }
  }
  for (int i = 1; i <= M; i++) {
    if (i > 1) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
