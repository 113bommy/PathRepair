#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, f;
  int l1, l2, a, b;
  cin >> s >> f;
  l1 = s.size() - 1;
  a = l1 + 1;
  l2 = f.size() - 1;
  b = l2 + 1;
  int n = 0;
  while ((s[l1] == f[l2]) && (l1 > 0) && (l2 > 0)) {
    n++;
    l1--;
    l2--;
  }
  cout << ((a + b) - (2 * n));
}
