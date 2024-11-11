#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x1 = 0, x2 = 0;
  string s;
  cin >> s;
  int piv = s.find('^', 0);
  for (int i = 0; i < piv; i++)
    if (s[i] != '=') {
      x1 += (s[i] - '0') * (piv - i);
    }
  for (int i = piv + 1; i < s.size(); i++)
    if (s[i] != '=') {
      x2 += (s[i] - '0') * (i - piv);
    }
  if (x1 == x2)
    cout << "balance";
  else if (x1 > x2)
    cout << "left";
  else if (x1 < x2)
    cout << "right";
  return 0;
}
