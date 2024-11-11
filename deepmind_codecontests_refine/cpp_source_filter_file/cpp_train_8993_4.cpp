#include <bits/stdc++.h>
using namespace std;
int n, L[1010], A[31], B[31], C[31], Ans[4][2], t = 0;
bool check() {
  for (int i = 1; i <= t; i++)
    if ((!B[i] && C[i] != 1) || A[i] < A[i - 1]) return 0;
  return 1;
}
void rev(int x, int y) {
  reverse(A + x, A + y + 1);
  reverse(B + x, B + y + 1);
  reverse(C + x, C + y + 1);
  for (int i = x; i <= y; i++) B[i] = 1 - B[i];
}
void Search(int x) {
  if (check()) {
    printf("%d\n", x - 1);
    for (int i = 1; i < x; i++) printf("%d %d\n", Ans[i][0], Ans[i][1]);
    exit(0);
  }
  if (x == 4) return;
  int S[31];
  S[0] = 0;
  for (int i = 1; i <= t; i++) S[i] = S[i - 1] + C[i];
  for (int i = 1; i <= t; i++)
    for (int j = i + 1; j <= t; j++) {
      Ans[x][0] = S[i - 1] + 1, Ans[x][1] = S[j];
      rev(i, j);
      Search(x + 1);
      rev(i, j);
    }
}
int main() {
  scanf("%d", &n), L[n + 1] = -1;
  for (int i = 1; i <= n; i++) scanf("%d", &L[i]);
  for (int lst = 1, i = 1; i <= n; i++)
    if (abs(L[i] - L[i + 1]) != 1) {
      int tmp = (L[i] - 1 == L[i - 1]);
      A[++t] = L[lst], B[t] = tmp, C[t] = 1;
      if (i > lst) A[++t] = L[lst + 1], B[t] = tmp, C[t] = 1;
      if (i > lst + 1) A[++t] = L[lst + 2], B[t] = tmp, C[t] = i - lst - 1;
      lst = i + 1;
    }
  Search(1);
}
