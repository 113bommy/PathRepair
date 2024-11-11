#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, m, i;
  cin >> n >> s;
  m = (-1 + sqrt(1.0 + 8 * n)) / 2;
  cout << s[0];
  for (i = 1; i <= m; i++) cout << s[i * (i + 1) / 2];
}
