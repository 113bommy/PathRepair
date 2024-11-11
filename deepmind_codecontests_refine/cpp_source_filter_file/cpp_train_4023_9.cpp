#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  int cnt = 0;
  int candy = (1 << 26) - 1;
  int total = candy;
  string st;
  char type;
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    cin >> type >> st;
    int now = 0;
    if (ok) {
      if (type != '.' && i + 1 != n) cnt++;
      continue;
    }
    for (char c : st) now |= 1 << (c - 'a');
    if (type == '.') candy &= total ^ now;
    if (type == '!') candy &= now;
    if (__builtin_popcountll(candy) < 2) {
      ok = true;
      {
        cerr << "i"
             << " = " << i << '\n';
      };
    }
  }
  cout << cnt;
}
