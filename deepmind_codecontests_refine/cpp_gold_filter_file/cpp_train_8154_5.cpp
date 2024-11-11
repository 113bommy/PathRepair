#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, INFTY = 1e10;
int a[30], b[30], k[30], p[30], Rp[30];
int t[30];
int N, U, R;
long long res;
long long calc() {
  long long v = 0;
  for (int i = 0; i < N; i++) v += (long long)a[i] * k[i];
  return v;
}
void f(int step, bool op1) {
  if (step == U) {
    res = max(res, calc());
    return;
  }
  if ((U - step + 1) % 2) res = max(res, calc());
  if (op1) {
    for (int i = 0; i < N; i++) a[i] ^= b[i];
    f(step + 1, false);
    for (int i = 0; i < N; i++) a[i] ^= b[i];
  }
  for (int i = 0; i < N; i++) t[i] = a[p[i]] + R;
  for (int i = 0; i < N; i++) a[i] = t[i];
  f(step + 1, true);
  for (int i = 0; i < N; i++) t[i] = a[Rp[i]] - R;
  for (int i = 0; i < N; i++) a[i] = t[i];
  return;
}
int main() {
  cin >> N >> U >> R;
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  for (int i = 0; i < N; i++) scanf("%d", &b[i]);
  for (int i = 0; i < N; i++) scanf("%d", &k[i]);
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
    --p[i];
    Rp[p[i]] = i;
  }
  res = -1000000000000;
  f(0, true);
  cout << res << endl;
  return 0;
}
