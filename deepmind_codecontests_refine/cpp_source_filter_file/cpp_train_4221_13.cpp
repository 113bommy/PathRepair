#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> i;
  j = 0;
  while (i) {
    if (i % 10 == 1) j++;
    i /= 10;
  }
  cout << j << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
