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
int C, D, N, M, K;
void solve() {
  int f, i, j, k, l, x, y;
  cin >> C >> D >> N >> M >> K;
  int mi = 100000;
  for (x = 0; x < 10001; x++)
    for (y = 0; y < 10001; y++)
      if (x * N + y + K >= N * M) mi = min(mi, x + y * D);
  cout << mi << endl;
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
