#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p, q, r, s;
  cin >> p >> q >> r >> s;
  if (!p && !r && !s)
    cout << "1\n";
  else {
    if (p == s && p)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
