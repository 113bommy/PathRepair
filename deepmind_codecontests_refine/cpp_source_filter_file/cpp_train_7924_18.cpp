#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2E9;
const long long LINF = (long long)9E18;
const long double PI = acos(-1.0);
const long double EPS = 1E-11;
int pl, pr, vl, vr, k;
int A[1000000], N, L_;
long long Tu, Mau;
void try_(int i, int val) {
  if (i == L_ + 1) {
    N++;
    A[N] = val;
    return;
  }
  try_(i + 1, val * 10 + 4);
  try_(i + 1, val * 10 + 7);
}
long long Len(int a, int b, int x, int y) {
  if (b < x || y < a) return 0;
  return min(b, y) - max(a, x) + 1;
}
void call_1() {
  for (int i = (1); i <= (N); ++i)
    if (A[i] > pr) {
      if (i - k >= 1)
        Tu +=
            Len(A[i - k - 1] + 1, A[i - k], vl, vr) * (long long)(pr - pl + 1);
      break;
    }
  for (int i = (N); i >= (1); --i)
    if (A[i] < pl) {
      if (i + k <= N)
        Tu +=
            Len(A[i + k], A[i + k + 1] - 1, vl, vr) * (long long)(pr - pl + 1);
      break;
    }
}
void call_2() {
  for (int i = (1); i <= (N - k + 1); ++i)
    Tu += Len(pl, pr, A[i - 1] + 1, A[i]) *
          Len(A[i + k - 1], A[i + k] - 1, vl, vr);
  for (int i = (k); i <= (N); ++i) {
    Tu += Len(pl, pr, A[i], A[i + 1] - 1) *
          Len(vl, vr, A[i - k] + 1, A[i - k + 1]);
    if (k == 1 && vl <= A[i] && A[i] <= vr && pl <= A[i] && A[i] <= pr) Tu--;
  }
}
int main() {
  cin >> pl >> pr >> vl >> vr >> k;
  for (int i = (1); i <= (9); ++i) {
    L_ = i;
    try_(1, 0);
  }
  Tu = 0;
  A[0] = 0;
  A[N + 1] = 1000000001;
  int ok = -1;
  for (int i = (1); i <= (N); ++i)
    if (pl <= A[i] && A[i] <= pr) {
      ok = 1;
      break;
    }
  if (ok == -1)
    call_1();
  else
    call_2();
  Mau = (long long)(pr - pl + 1) * (long long)(vr - vl + 1);
  printf("%.9lf", (double)Tu / Mau);
}
