#include <bits/stdc++.h>
using namespace std;
int ask(string x) {
  cout << x << endl;
  int k;
  cin >> k;
  if (!k) exit(0);
  return k;
}
int main() {
  int x, y, n = ask("a") + 1;
  string s(n, 'a');
  x = n == 301 ? n : ask(s);
  x == n&& ask(string(n - 1, 'b'));
  for (char& c : s) {
    c = 'b';
    y = ask(s);
    if (y > x)
      c = 'a';
    else
      y = x;
  }
}
