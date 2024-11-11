#include <bits/stdc++.h>
using namespace std;
int N, M, K;
char n[1024], p[1024];
int ans[1024 * 1024];
int cmp(char c1, char c2) {
  if (c1 == 'R' and c2 == 'S') return 1;
  if (c1 == 'S' and c2 == 'R') return 0;
  if (c1 == 'R' and c2 == 'P') return 0;
  if (c1 == 'P' and c2 == 'R') return 1;
  if (c1 == 'S' and c2 == 'P') return 1;
  if (c1 == 'P' and c2 == 'S') return 0;
}
int main() {
  scanf("%d\n", &N);
  scanf("%s\n", n);
  scanf("%s\n", p);
  M = strlen(n);
  K = strlen(p);
  for (int i = 0; i < M + K; i++) {
    if (n[i % M] != p[i % K]) {
      if (cmp(n[i % M], p[i % K])) {
        ans[i] = 2;
      } else {
        ans[i] = 1;
      }
    }
  }
  int ans1 = 0, ans2 = 0;
  if (M + K < N) {
    for (int i = 0; i < M + K; i++)
      if (ans[i] == 1)
        ans1++;
      else if (ans[i] == 2)
        ans2++;
    int tmp = N / (M + K);
    ans1 *= tmp;
    ans2 *= tmp;
    N %= (M + K);
  }
  for (int i = 0; i < N; i++)
    if (ans[i] == 1)
      ans1++;
    else if (ans[i] == 2)
      ans2++;
  printf("%d %d\n", ans1, ans2);
}
