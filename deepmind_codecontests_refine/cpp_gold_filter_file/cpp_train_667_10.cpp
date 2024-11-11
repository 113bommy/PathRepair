#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cout << *i << " ";
  cout << endl;
}
int N;
double V;
double A[22], B[22];
int main() {
  scanf("%d %lf", &N, &V);
  for (int(i) = (0); (i) < (N); (i)++) scanf("%lf", A + i);
  for (int(i) = (0); (i) < (N); (i)++) scanf("%lf", B + i);
  double tot = 1e100, sA = 0;
  for (int(i) = (0); (i) < (N); (i)++) tot = min(B[i] / A[i], tot), sA += A[i];
  tot *= sA;
  printf("%lf\n", min(V, tot));
  return 0;
}
