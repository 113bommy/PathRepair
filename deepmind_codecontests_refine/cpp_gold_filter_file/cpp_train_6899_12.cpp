#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1, n;
  string s;
  cin >> s;
  n = s.size();
  cout << 3 << "\n";
  cout << "L " << n - 1 << "\n";
  n += n - 2;
  cout << "R " << s.size() - 1 << "\n";
  n += 1 + s.size();
  cout << "R " << 3 + 2 * (s.size() - 2) << "\n";
}
