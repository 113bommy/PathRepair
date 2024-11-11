#include <bits/stdc++.h>
using namespace std;
int n;
int a[503][503];
struct M {
  int n;
  long long a[201][201];
} I, W;
M mul(M A, M B) {
  int n = A.n;
  M C;
  C.n = A.n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      C.a[i][j] = 0;
      for (int k = 1; k <= n; k++)
        C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % 1000003;
    }
  return C;
}
long long c, w, h;
void solve() {
  cin >> c >> w >> h;
  I.n = w + 1;
  int n = I.n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) I.a[i][j] = 0;
  for (int i = 1; i <= n; i++) I.a[1][i] = 1;
  for (int i = 1; i <= n - 1; i++) I.a[i][i + 1] = h;
  W = I;
  c--;
  while (c) {
    if (c % 2) W = mul(W, I);
    I = mul(I, I);
    c /= 2;
  }
  long long ret = 0;
  for (int i = 1; i <= n; i++) ret = (ret + W.a[1][i]) % 1000003;
  cout << ret << endl;
}
int main() {
  solve();
  return 0;
}
