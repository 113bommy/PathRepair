#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
const double EPS = 0.00000001;
const double PI = 3.14159265359;
int main() {
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = str.size() - 1; i >= 0; --i) {
    if (str[i] == '0') {
      cnt++;
    } else if (cnt) {
      cnt--;
    } else {
      str[i] = '1';
    }
  }
  cout << str;
  return 0;
}
