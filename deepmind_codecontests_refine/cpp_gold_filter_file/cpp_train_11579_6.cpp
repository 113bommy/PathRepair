#include <bits/stdc++.h>
using namespace std;
int ask(string s) {
  cout << s << endl;
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
    if (x < y)
      c = 'a';
    else
      x = y;
  }
}
