#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ns = "";
  int x = 1, y = 0;
  while (x < n) {
    while (x < n && s[x] == s[y]) x++;
    if (x != n) {
      ns += s[y];
      ns += s[x];
      y = x + 1;
      x += 2;
    }
  }
  cout << n - ns.size() << endl << ns << endl;
  return 0;
}
