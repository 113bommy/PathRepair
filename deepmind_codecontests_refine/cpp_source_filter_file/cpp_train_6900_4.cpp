#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
const long long INF = 1000000007;
const long double cp = 2 * asin(1.0);
const long double eps = 1e-9;
const long long mod = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s, s1, s2, c2, c1;
  cin >> s;
  bool ok = false, f = false;
  if (s[0] == '-') ok = true, s.erase(s.begin() + 0);
  for (int(i) = 0; (i) < (s.size()); i++) {
    if (s[i] == '.')
      f = true;
    else if (!f)
      s1 += s[i];
    else
      s2 += s[i];
  }
  if (s2.size() == 0)
    c2 = "00";
  else if (s2.size() == 1)
    c2 = s2 + "0";
  else
    for (int(i) = 0; (i) < (2); i++) c2 += s2[i];
  int k = 1;
  for (int(i) = (s1.size() - 1); (i) >= (0); i--) {
    c1 = s1[i] + c1;
    if (k % 3 == 0) c1 = ',' + c1;
    k++;
  }
  if (ok) cout << "(";
  cout << '$';
  cout << c1 << '.' << c2;
  if (ok) cout << ')';
  return 0;
}
