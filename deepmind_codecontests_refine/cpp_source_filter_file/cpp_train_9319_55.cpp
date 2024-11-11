#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, s1 = 0, s2 = 0, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    s1 |= a;
  }
  for (i = 0; i < n; i++) {
    cin >> b;
    s2 |= a;
  }
  cout << s1 + s2;
  return 0;
}
