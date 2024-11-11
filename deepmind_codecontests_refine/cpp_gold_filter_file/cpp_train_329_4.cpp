#include <bits/stdc++.h>
using namespace std;
signed long long N, P, W, D;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> P >> W >> D;
  signed long long a = P / W;
  for (i = 0; i < (200000); i++)
    if (a - i >= 0) {
      signed long long X = a - i;
      signed long long P2 = P - X * W;
      if (X >= 0 && P2 % D == 0) {
        signed long long Y = P2 / D;
        if (Y >= 0 && X + Y <= N) {
          cout << X << " " << Y << " " << (N - X - Y) << endl;
          return;
        }
      }
    }
  cout << -1 << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
