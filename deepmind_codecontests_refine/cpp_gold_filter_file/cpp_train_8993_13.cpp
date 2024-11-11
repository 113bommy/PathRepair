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
void Get(long long &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int N;
int A[10005];
void Init() {
  Get(N);
  for (int i = 1; i <= N; i++) Get(A[i]);
  A[N + 1] = N + 1;
}
int L[5];
int R[5];
void DFS(int Depth) {
  bool OK = 1;
  for (int i = 1; i <= N; i++)
    if (A[i] != i) {
      OK = 0;
      break;
    }
  if (OK == 1) {
    printf("%d\n", Depth - 1);
    for (int i = Depth - 1; i >= 1; i--) printf("%d %d\n", L[i], R[i]);
    exit(0);
  }
  if (Depth > 3) return;
  int P[5];
  P[1] = N + 1;
  P[2] = 0;
  P[3] = N + 1;
  P[4] = 0;
  for (int i = 1; i <= N; i++)
    if (A[i] != i) {
      if (P[1] > i) P[1] = i;
      if (P[2] < i) P[2] = i;
      if (A[P[3]] > A[i]) P[3] = i;
      if (A[P[4]] < A[i]) P[4] = i;
    }
  for (int i = 1, X, Y; i <= 4; i++) {
    X = P[i], Y = A[X];
    if (X == Y) continue;
    if (X > Y) std::swap(X, Y);
    L[Depth] = X;
    R[Depth] = Y;
    reverse(A + X, A + Y + 1);
    DFS(Depth + 1);
    reverse(A + X, A + Y + 1);
  }
}
void Work() {
  bool OK = 1;
  for (int i = 1; i <= N; i++)
    if (A[i] != i) {
      OK = 0;
      break;
    }
  if (OK) {
    puts("0");
    exit(0);
  }
  int Cnt = 0;
  for (int i = 2; i <= N; i++)
    if (std::abs(A[i] - A[i - 1]) != 1) Cnt++;
  for (int X = 1; X <= N; X++)
    for (int Y = X + 1; Y <= N; Y++) {
      if (X > 1) {
        Cnt -= (std::abs(A[X] - A[X - 1]) != 1);
        Cnt += (std::abs(A[Y] - A[X - 1]) != 1);
      }
      if (Y < N) {
        Cnt -= (std::abs(A[Y] - A[Y + 1]) != 1);
        Cnt += (std::abs(A[X] - A[Y + 1]) != 1);
      }
      L[1] = X;
      R[1] = Y;
      if (Cnt <= 4) {
        reverse(A + X, A + Y + 1);
        DFS(2);
        reverse(A + X, A + Y + 1);
      }
      if (X > 1) {
        Cnt += (std::abs(A[X] - A[X - 1]) != 1);
        Cnt -= (std::abs(A[Y] - A[X - 1]) != 1);
      }
      if (Y < N) {
        Cnt += (std::abs(A[Y] - A[Y + 1]) != 1);
        Cnt -= (std::abs(A[X] - A[Y + 1]) != 1);
      }
    }
}
void Debug() {
  N = 1000;
  for (int i = 1; i <= N; i++) A[i] = i;
  reverse(A + 267, A + 541);
  reverse(A + 580, A + 748);
}
void Debug2() {
  reverse(A + 22, A + 98);
  reverse(A + 27, A + 75);
  reverse(A + 47, A + 69);
  for (int i = 1; i <= N; i++) fprintf(stderr, "%d ", A[i]);
  fprintf(stderr, "\n");
}
int main() {
  Init();
  Work();
  return 0;
}
