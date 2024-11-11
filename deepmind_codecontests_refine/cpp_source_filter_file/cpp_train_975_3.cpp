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
pair<int, int> A[1000005];
int N;
void Init() {
  Get(N);
  for (int i = 1; i <= N; i++) {
    Get(A[i].first);
    Get(A[i].second);
    A[i].first += 1000005;
    A[i].second += 1000005;
  }
}
double Floor(int X, int Y, int P) {
  double Y1 = A[X].second + (double)(P - A[X].first) *
                                (A[Y].second - A[X].second) /
                                (double)(A[Y].first - A[X].first);
  return floor(Y1 + (1e-8));
}
double Ceil(int X, int Y, int P) {
  double Y1 = A[X].second + (double)(P - A[X].first) *
                                (A[Y].second - A[X].second) /
                                (double)(A[Y].first - A[X].first);
  return ceil(Y1 - (1e-8));
}
long long F[10000005];
double Ans;
void Calc() {
  rotate(A + 1, min_element(A + 1, A + N + 1), A + N + 1);
  A[N + 1] = A[1];
  int Pos = max_element(A + 1, A + N + 1) - A;
  int P = A[1].first, Q = A[Pos].first;
  for (int i = P, k = 1; i <= Q; i++) {
    for (; A[k + 1].first < i;) k++;
    int Pos = Ceil(k, k + 1, i);
    F[i] = -Pos + 1;
  }
  long long Cnt = 0;
  long long SumX = 0;
  for (int i = Q, k = Pos; i >= P; i--) {
    for (; A[k + 1].first > i;) k++;
    int Pos = Floor(k, k + 1, i);
    F[i] += Pos;
    Cnt += F[i];
    SumX += (i - 1000005) * F[i];
  }
  for (int i = Q; i >= P; i--)
    Ans += F[i] * (i - 1000005) * (i - 1000005) / ((double)Cnt - 1);
  Ans -= SumX * SumX / ((double)(Cnt - 1) * Cnt);
}
void Work() {
  long long S = 0;
  A[N + 1] = A[1];
  for (int k = 1; k <= N + 1; k++)
    S += A[k].first * A[k + 1].second - A[k].second * A[k + 1].first;
  if (S < 0) reverse(A + 1, A + N + 1);
  Calc();
  for (int k = 1; k <= N; k++) std::swap(A[k].first, A[k].second);
  reverse(A + 1, A + N + 1);
  Calc();
}
void Output() { printf("%.15lf\n", (double)Ans); }
int main() {
  Init();
  Work();
  Output();
  return 0;
}
