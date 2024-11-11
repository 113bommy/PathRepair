#include <bits/stdc++.h>
using namespace std;
void moveleft() { cout << "LEFT" << endl; }
void moveright() { cout << "RIGHT" << endl; }
void print(char ch) {
  cout << "PRINT"
       << " " << ch << endl;
}
void solve() {
  int n;
  int p;
  cin >> n >> p;
  string s;
  cin >> s;
  if (p <= n - p) {
    if (p != 1) {
      moveleft();
      p--;
    }
    while (p <= n) {
      print(s[p - 1]);
      if (p == n) break;
      moveright();
      p++;
    }
  } else {
    while (p != n) {
      moveright();
      p++;
    }
    while (p >= 1) {
      print(s[p - 1]);
      if (p == 1) break;
      moveleft();
      p--;
    }
  }
}
int main() {
  int t;
  t = 1;
  while (t) {
    solve();
    t--;
  }
  return 0;
}
