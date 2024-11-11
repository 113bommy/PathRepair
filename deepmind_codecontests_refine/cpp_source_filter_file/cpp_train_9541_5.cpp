#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 11;
const long long inf = 1e9 + 7;
string s;
int main() {
  cin >> s;
  string s2 = s;
  reverse(s2.begin(), s2.end());
  cout << s2;
  return 0;
}
