#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5;
int N, M, A[MX + 10];
bool oka(int x) {
  int last = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] < last) {
      if (last - A[i] > x) {
        return false;
      }
      last = last;
    } else {
      if ((A[i] + x) % M < A[i] && (A[i] + x) % M >= last) {
        last = last;
      } else {
        last = A[i];
      }
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  int lo = 0, hi = M - 1;
  while (lo < hi) {
    int m = (lo + hi) / 2;
    if (oka(m))
      hi = m;
    else
      lo = m + 1;
  }
  printf("%d\n", lo);
}
