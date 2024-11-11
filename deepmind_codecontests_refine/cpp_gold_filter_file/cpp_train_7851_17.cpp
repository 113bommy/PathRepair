#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
signed long long GETi() {
  signed long long i;
  scanf("%lld", &i);
  return i;
}
int N, M;
const int NN = 100500;
const int D = 105;
signed long long A[NN];
signed long long C[D + NN + 1][D + 1];
signed long long V[D + NN + 1][D + 1];
signed long long mo = 1000000007;
void solve() {
  int f, i, j, r, k, l, x, y;
  cin >> N >> M;
  for (i = 0; i < N; i++) cin >> A[i];
  C[0][0] = 1;
  for (i = 1; i <= D + NN; i++) {
    C[i][0] = 1;
    for (j = 1; j <= D; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
  }
  while (M--) {
    cin >> l >> r >> k;
    l--;
    V[D - k + l][D - k]++;
    for (i = D - k; i <= D; i++)
      V[i + r][i] += mo - C[r - l - 1 + i - (D - k)][i - (D - k)],
          V[i + r][i] %= mo;
  }
  for (i = 1; i <= D + NN; i++) {
    V[i][j] = ((V[i][j] + V[i - 1][j]) % mo + mo) % mo;
    for (j = 1; j <= D; j++)
      V[i][j] = ((V[i][j] + V[i - 1][j] + V[i - 1][j - 1]) % mo + mo) % mo;
  }
  for (i = 0; i < N; i++) (void)printf("%lld ", (V[D + i][D] + A[i]) % mo);
  (void)printf("\n");
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
