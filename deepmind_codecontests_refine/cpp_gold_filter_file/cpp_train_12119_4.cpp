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
  int f, r, i, j, k, l, x, y, tx, ty;
  cin >> N;
  for (i = 0; i < N; i++) cin >> A[i];
  j = 0;
  for (i = 0; i < N; i++)
    if (A[i] == i) j++;
  for (i = 0; i < N; i++)
    if (A[i] != i && A[A[i]] == i) return (void)printf("%d\n", j + 2);
  for (i = 0; i < N; i++)
    if (A[i] != i) return (void)printf("%d\n", j + 1);
  return (void)printf("%d\n", j);
}
int main(int argc, char** argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  solve();
  return 0;
}
