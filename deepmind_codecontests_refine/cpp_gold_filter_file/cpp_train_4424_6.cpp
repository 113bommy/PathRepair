#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
string str, test, cf = {"CODEFORCES"};
int main() {
  cin >> str;
  int l = str.length();
  for (int i = 0; i < l; i++) {
    for (int j = 0; j <= l; j++) {
      test = str.substr(0, i) + str.substr(j);
      if (test == cf) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
