#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n;
  n = s.length();
  int p = 0, q = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      cout << 1 << "  " << (p % 4 + 1) << "\n";
      p++;
    } else {
      cout << 3 << "  " << (2 * (q % 2) + 1) << "\n";
      q++;
    }
  }
  return 0;
}
