#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
string Solve();
int main() {
  string s = Solve();
  return 0;
}
int NextInt() {
  int x;
  scanf("%d", &x);
  return x;
}
string NextLine() {
  string s;
  getline(cin, s);
  return s;
}
string NextWord() {
  string s;
  cin >> s;
  return s;
}
double NextDouble() {
  double x;
  cin >> x;
  return x;
}
string Solve() {
  string s[8];
  for (int i = (0); (i) < (int)(8); i++) {
    s[i] = NextLine();
  }
  for (int i = (0); (i) < (int)(8); i++)
    for (int j = (0); (j) < (int)(7); j++) {
      if (s[j] == s[j + 1]) {
        cout << "NO";
        return "lol";
      }
    }
  cout << "YES";
  return "end";
}
