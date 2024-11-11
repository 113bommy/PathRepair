#include <bits/stdc++.h>
using namespace std;
int n, i, kol;
string s;
int main() {
  cin >> n;
  cin >> s;
  kol = 0;
  for (i = 0; i < n; i++) {
    if ((s[i] = '0' && i % 2 == 0) || (s[i] = '1' && i % 2 == 1)) kol++;
  }
  cout << min(kol, n - kol);
  return 0;
}
