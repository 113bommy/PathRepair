#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using llu = long long unsigned int;
const int N = 1e5 + 5;
int main() {
  string s1;
  cin >> s1;
  string s[5];
  cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
  for (int i = 0; i < 5; i++) {
    if (s1[0] == s[i][0]) {
      cout << "YES" << endl;
      return 0;
    } else if (s1[1] == s[i][1]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
