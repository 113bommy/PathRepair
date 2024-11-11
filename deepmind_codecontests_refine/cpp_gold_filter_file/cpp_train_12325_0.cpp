#include <bits/stdc++.h>
int N, M, k, MAX = 0;
int A[5001];
int hash[1000001], B[1000001];
void init();
void doit();
void DO(int);
int check(int);
int main() {
  init();
  doit();
  return 0;
}
void init() {
  int i;
  scanf("%d%d", &N, &k);
  for (i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    MAX = ((MAX > A[i]) ? MAX : A[i]);
  }
}
void doit() {
  int i, j;
  for (i = 1; i < N + 1; i++)
    for (j = 1; j < i; j++) hash[(int)fabs(A[i] - A[j])]++;
  for (i = N - k; i < MAX + 2; i++)
    if (check(i)) {
      printf("%d\n", i);
      return;
    }
  printf("-1\n");
}
int check(int m) {
  int i, tmp = m, times = 0;
  while (tmp <= MAX) {
    times += hash[tmp];
    tmp += m;
  }
  if (times > (k + 1) * k / 2) return 0;
  times = 0;
  for (i = 1; i < N + 1; i++) {
    tmp = A[i] % m;
    if (B[tmp] == m)
      times++;
    else
      B[tmp] = m;
    if (times > k) return 0;
  }
  return 1;
}
