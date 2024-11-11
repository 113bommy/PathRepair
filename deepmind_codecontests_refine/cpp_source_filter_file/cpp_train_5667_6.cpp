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
double dpdp[2001][2001];
int visr[2001], visc[2001];
double dodo(signed long long x, signed long long y) {
  if (x > y) swap(x, y);
  if (dpdp[x][y] >= 0) return dpdp[x][y];
  if (x == 0 && y == 0) return 0;
  if (x == 0) {
    dpdp[x][y] = dodo(x, y - 1) + N / (double)y;
  } else {
    dpdp[x][y] = N * (signed long long)N + x * (N - y) * dodo(x - 1, y) +
                 (N - x) * y * dodo(x, y - 1) + x * y * dodo(x - 1, y - 1);
    dpdp[x][y] /= (double)(N * (x + y) - x * (signed long long)y);
  }
  return dpdp[x][y];
}
void solve() {
  int f, i, j, k, l, x, y;
  cin >> N >> M;
  for (i = 0; i < M; i++) {
    cin >> x >> y;
    visr[x - 1] = 1;
    visc[y - 1] = 1;
  }
  for (x = 0; x < N; x++)
    for (y = 0; y < N; y++) dpdp[x][y] = -1;
  (void)printf("%.12lf\n", dodo(N - count(visr, visr + N, 1),
                                N - count(visc, visc + N, 1)));
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
