#include <bits/stdc++.h>
using namespace std;
int print(string s) {
  cout << s << endl;
  cout.flush();
  int x;
  cin >> x;
  if (x == 0) exit(0);
  return x;
}
int main() {
  int n = print("a") + 1;
  if (n == 300) print(string(300, 'b'));
  string s(n, 'a');
  int b = print(s);
  if (b == n) print(string(n - 1, 'b'));
  string t(n, 'a');
  int q = 0;
  for (int i = 0; i < n - 1; ++i) {
    s[i] = 'b';
    if (print(s) < b) {
      t[i] = 'b';
      ++q;
    }
    s[i] = 'a';
  }
  if (q < b) t[n - 1] = 'b';
  print(t);
}
