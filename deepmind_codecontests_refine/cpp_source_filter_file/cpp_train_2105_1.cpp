#include <bits/stdc++.h>
using namespace std;
int N;
string S;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cout << N << S;
  cout << (N + 1) << endl;
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
