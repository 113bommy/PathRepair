#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, p[10];
char inp[10];
short dig[10][10], nthp[10];
bool mark[10];
int ou = 1000001;
void gen(int idx) {
  if (idx < k) {
    int i, j;
    for (i = 0; i < k; ++i) {
      if (!mark[i]) {
        nthp[idx] = i;
        mark[i] = true;
        gen(idx + 1);
        mark[i] = false;
      }
    }
  } else {
    int i, j, mini = 1000001, maxi = -1;
    for (i = 0; i < k; ++i) {
      for (j = 0; j < n; ++j) {
        p[j] = p[j] * 10 + dig[j][nthp[i]];
        if (i == k - 1) {
          mini = min(mini, p[j]);
          maxi = max(maxi, p[j]);
          p[j] = 0;
        }
      }
    }
    ou = min(ou, maxi - mini);
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; ++i) {
    scanf("%s", inp);
    for (j = 0; j < k; ++j) dig[i][j] = inp[j] - '0';
  }
  gen(0);
  printf("%d\n", ou);
  return 0;
}
