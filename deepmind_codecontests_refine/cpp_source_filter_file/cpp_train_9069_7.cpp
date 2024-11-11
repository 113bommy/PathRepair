#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, k, l, n = 0, m = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      n++;
      cout << 1 << " " << n << endl;
      n = n % 4;
    }
    if (s[i] == '1') {
      m += 2;
      cout << 3 << " " << m << endl;
      m %= 4;
    }
  }
  return 0;
}
