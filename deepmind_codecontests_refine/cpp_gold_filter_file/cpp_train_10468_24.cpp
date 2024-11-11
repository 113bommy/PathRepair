#include <bits/stdc++.h>
using namespace std;
int main() {
  string cd;
  cin >> cd;
  if ((cd[0] == 'a' || cd[0] == 'h') && (cd[1] < '8' && cd[1] > '1'))
    cout << "5";
  else if ((cd[0] == 'a' || cd[0] == 'h') && (cd[1] == '8' || cd[1] == '1'))
    cout << "3";
  else if ((cd[0] < 'h' && cd[0] > 'a') && (cd[1] == '8' || cd[1] == '1'))
    cout << "5";
  else
    cout << "8";
}
