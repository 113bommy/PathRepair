#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int pow_mod(long long x, long long n, int M) {
  long long ans = 1;
  for (; n; n >>= 1) {
    if (n & 1) ans = ans * x % M;
    x = x * x % M;
  }
  return ans;
}
int inv[5] = {0, 1, 3, 2, 4};
int N, M;
int a[500][500], b[500][500];
void row_scale(int i, int x) {
  x = (x % 5 + 5) % 5;
  for (int j = 0; j < M; j++) a[i][j] = a[i][j] * x % 5;
  for (int j = 0; j < N; j++) b[i][j] = b[i][j] * x % 5;
}
void row_swap(int i1, int i2) {
  for (int j = 0; j < M; j++) swap(a[i1][j], a[i2][j]);
  for (int j = 0; j < N; j++) swap(b[i1][j], b[i2][j]);
}
void row_add(int i1, int i2, int x) {
  x = (x % 5 + 5) % 5;
  for (int j = 0; j < M; j++) a[i2][j] = (a[i2][j] + a[i1][j] * x) % 5;
  for (int j = 0; j < N; j++) b[i2][j] = (b[i2][j] + b[i1][j] * x) % 5;
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) a[j][i] = s[j] - 'a';
  }
  swap(N, M);
  for (int i = 0; i < N; i++) b[i][i] = 1;
  int k = 0;
  for (int j = 0; j < M; j++) {
    int i0;
    for (i0 = k; i0 < N && !a[i0][j]; i0++)
      ;
    if (i0 == N) continue;
    row_swap(k, i0);
    row_scale(k, inv[a[k][j]]);
    for (int i = 0; i < N; i++)
      if (i != k) row_add(k, i, -a[i][j]);
    k++;
  }
  int Q;
  cin >> Q;
  while (Q--) {
    string s;
    cin >> s;
    vector<int> x(N);
    for (int i = 0; i < N; i++) x[i] = s[i] - 'a';
    vector<int> bx(N);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) bx[i] += b[i][j] * x[j];
    for (int i = 0; i < N; i++) bx[i] %= 5;
    int i0 = -1;
    for (int i = 0; i < N; i++)
      if (bx[i]) i0 = i;
    if (i0 < k)
      printf("%d\n", pow_mod(5, M - k, MOD));
    else
      printf("%d\n", 0);
  }
}
