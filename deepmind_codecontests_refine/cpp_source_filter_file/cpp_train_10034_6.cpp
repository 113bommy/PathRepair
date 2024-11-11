#include <bits/stdc++.h>
using namespace std;
void Get(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int Ans[10005];
int Ans2[10005];
int A[1005];
int N;
char S[250005][105];
int AnsTop;
int Cnt[15];
void DFS2(int X, int Top) {
  if (X > Top - X + 1) {
    for (int i = 1; i <= N; i++)
      if (Cnt[i] == 0) return;
    int X[15];
    X[1] = X[2] = X[3] = X[4] = 0;
    for (int k = 1; k <= Top; k++) {
      if (Ans2[k] == 0 && X[Ans[k]] == 0 && Ans[k + 1] == Ans[k]) return;
      X[Ans[k]] = X[Ans[k]] * 10 + Ans2[k];
    }
    if (X[1] > 256) return;
    if (X[2] > 256) return;
    if (X[3] > 256) return;
    if (X[4] > 256) return;
    AnsTop++;
    sprintf(S[AnsTop], "%d.%d.%d.%d", X[1], X[2], X[3], X[4]);
    return;
  }
  for (int i = 1; i <= N; i++) {
    Cnt[i]++;
    Ans2[X] = Ans2[Top - X + 1] = A[i];
    DFS2(X + 1, Top);
    Cnt[i]--;
  }
}
void DFS(int X, int Top) {
  if (X > 4) {
    DFS2(1, Top);
    return;
  }
  Ans[Top + 1] = X;
  DFS(X + 1, Top + 1);
  Ans[Top + 2] = X;
  DFS(X + 1, Top + 2);
  Ans[Top + 3] = X;
  DFS(X + 1, Top + 3);
  Ans[Top + 1] = 0;
  Ans[Top + 2] = 0;
  Ans[Top + 3] = 0;
}
void Init() {
  Get(N);
  for (int i = 1; i <= N; i++) Get(A[i]);
}
void Output() {
  printf("%d\n", AnsTop);
  for (int i = 1; i <= AnsTop; i++) puts(S[i]);
}
int main() {
  Init();
  DFS(1, 0);
  Output();
  return 0;
}
