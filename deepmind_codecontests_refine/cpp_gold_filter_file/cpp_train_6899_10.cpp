#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  int len = s.length();
  cout << 3 << '\n';
  cout << "L " << len - 1 << '\n';
  cout << "R " << len - 1 << '\n';
  cout << "R " << 2 * len - 1 << '\n';
  return 0;
}
