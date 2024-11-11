#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b1, m, b2, s1 = 0, s2 = 0, i, a;
  cin >> n >> b1;
  for (i = 0; i < n; i++) {
    cin >> a;
    s1 = s1 + a * pow(b1, n - 1 - i);
  }
  cin >> m >> b2;
  for (i = 0; i < m; i++) {
    cin >> a;
    s2 = s2 + a * pow(b2, m - 1 - i);
  }
  if (s1 > s2)
    cout << ">";
  else if (s1 == s2)
    cout << "=";
  else
    cout << "<";
}
