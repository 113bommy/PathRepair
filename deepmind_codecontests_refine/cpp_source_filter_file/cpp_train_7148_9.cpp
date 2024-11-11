#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  for (int i = 0; i < (((int)(s).size()) - 2); i++)
    if (s[i] + s[i + 1] + s[i + 2] == 'A' + 'B' + 'C') {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
}
