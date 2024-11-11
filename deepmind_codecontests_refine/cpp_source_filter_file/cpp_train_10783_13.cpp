#include <bits/stdc++.h>
using namespace std;
signed long long N, M;
signed long long ok(signed long long ex) {
  signed long long tot = ex * (ex - 1) / 2 + (M + ex);
  return tot < N;
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  M = min(N, M);
  signed long long ret = M - 1;
  signed long long plus = 0;
  for (i = 31; i >= 0; i--)
    if (ok(plus + (1LL << i))) plus += 1LL << i;
  cout << ret + plus + 2 << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
