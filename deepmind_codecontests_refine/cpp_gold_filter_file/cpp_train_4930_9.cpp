#include <bits/stdc++.h>
void Get(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int A[1000005];
int N;
int Q[1000005];
int L, R;
int Left[1000005];
int Right[1000005];
void Init() {
  Get(N);
  for (int i = 1; i <= N; i++) Get(A[i]);
  Q[L = R = 1] = 0;
  for (int i = 1; i <= N; i++) {
    for (; L <= R && A[Q[R]] > A[i];) R--;
    Left[i] = i - Q[R];
    Q[++R] = i;
  }
  Q[L = R = 1] = N + 1;
  for (int i = N; i >= 1; i--) {
    for (; L <= R && A[Q[R]] >= A[i];) R--;
    Right[i] = Q[R] - i;
    Q[++R] = i;
  }
  for (int i = 1; i <= N; i++)
    if (Left[i] > Right[i]) std::swap(Left[i], Right[i]);
}
double S[1000005];
void Calc(int L, int R, int k) {
  S[1] += k;
  S[L + 1] -= k;
  S[R + 1] -= k;
  S[L + R + 1] += k;
}
double Ans[1000005];
int M;
void Work() {
  for (int i = 1; i <= N; i++) Calc(Left[i], Right[i], A[i]);
  for (int i = 1; i <= N; i++) S[i] += S[i - 1];
  for (int i = 1; i <= N; i++) {
    S[i] += S[i - 1];
    Ans[i] = S[i] / ((double)(N - i + 1));
  }
  Get(M);
  for (int k = 1, X; k <= M; k++) {
    Get(X);
    double Ans0 = Ans[X];
    printf("%.13lf\n", Ans0);
  }
}
int main() {
  Init();
  Work();
  return 0;
}
