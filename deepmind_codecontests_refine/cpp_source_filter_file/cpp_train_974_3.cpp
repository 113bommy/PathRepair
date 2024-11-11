#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
int GETi() {
  int i;
  scanf("%d", &i);
  return i;
}
template <class T>
T sqr(T val) {
  return val * val;
}
int N;
int A[100001];
void solve() {
  int f, r, i, j, k, l;
  N = GETi();
  for (i = 0; i < N; i++) A[i] = GETi() - 1;
  j = 0;
  for (i = N - 2; i >= 0; i++) {
    if (A[i - 1] < A[i])
      j++;
    else
      break;
  }
  printf("%d\n", N - 1 - j);
  return;
}
int main(int argc, char** argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  solve();
  return 0;
}
