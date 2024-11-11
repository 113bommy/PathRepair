#include <bits/stdc++.h>
using namespace std;
void op() {
  string s, p = "", l = "";
  cin >> s;
  int u = 1;
  ;
  for (int i = s.size() - 1; i >= 0; i -= u) {
    if (s[i] != s[i - 1]) {
      p += s[i];
      u = 1;
    } else
      u = 2;
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < p.size(); i++) {
    int j;
    for (j = 0; j < i; j++) {
      if (p[i] == p[j]) break;
    }
    if (i == j) l += p[i];
  }
  sort(l.begin(), l.end());
  cout << l;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    op();
    cout << "\n";
  }
}
