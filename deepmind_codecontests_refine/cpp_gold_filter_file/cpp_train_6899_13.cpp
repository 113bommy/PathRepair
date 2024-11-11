#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(0);
  string s;
  cin >> s;
  int len = s.length();
  cout << "3\nR" << ' ' << len - 1 << "\n";
  cout << "L" << ' ' << len << "\n";
  cout << "L 2"
       << "\n";
}
