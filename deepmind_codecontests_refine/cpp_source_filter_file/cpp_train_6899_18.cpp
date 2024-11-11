#include <bits/stdc++.h>
const long long inf = 1e18;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    string str;
    cin >> str;
    string s = str;
    reverse((s).begin(), (s).end());
    if (s == str)
      cout << 0 << "\n";
    else {
      cout << 3 << "\n";
      cout << "R " << str.length() - 1 << "\n";
      cout << "L " << str.length() - 1 << "\n";
      cout << "L " << 2 << "\n";
    }
  }
}
