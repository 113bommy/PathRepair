#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> A;
  A['0'] = 2;
  A['1'] = 7;
  A['2'] = 2;
  A['3'] = 3;
  A['4'] = 3;
  A['5'] = 4;
  A['6'] = 2;
  A['7'] = 5;
  A['8'] = 1;
  A['9'] = 2;
  string s;
  cin >> s;
  cout << A[s[1]] * A[s[0]] << endl;
}
