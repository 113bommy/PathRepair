#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  long long int xx = 0;
  for (int i = a; i <= b; i++) {
    string s = to_string(i);
    for (long int j = 0; j < s.size(); j++) {
      if (s[j] == '0' || s[j] == '6' || s[j] == '9') xx = xx + 6;
      if (s[j] == '1') xx = xx + 2;
      if (s[j] == '2' || s[j] == '3' || s[j] == '5') xx = xx + 5;
      if (s[j] == '4') xx = xx + 4;
      if (s[j] == '7') xx = xx + 3;
      if (s[j] == '8') xx = xx + 7;
    }
  }
  cout << xx << endl;
  return 0;
}
