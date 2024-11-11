#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, string> mp;
  mp[0] = "zero";
  mp[1] = "one";
  mp[2] = "two";
  mp[3] = "three";
  mp[4] = "four";
  mp[5] = "five";
  mp[6] = "six";
  mp[7] = "seven";
  mp[8] = "eight";
  mp[9] = "nine";
  mp[10] = "ten";
  mp[11] = "eleven";
  mp[12] = "twelve";
  mp[13] = "thirteen";
  mp[14] = "fourteen";
  mp[15] = "fithteen";
  mp[16] = "sixteen";
  mp[17] = "seventeen";
  mp[18] = "eighteen";
  mp[19] = "nineteen";
  mp[20] = "twenty";
  mp[30] = "thirty";
  mp[40] = "forty";
  mp[50] = "fifty";
  mp[60] = "sixty";
  mp[70] = "seventy";
  mp[80] = "eighty";
  mp[90] = "ninety";
  int n;
  cin >> n;
  if (n < 20 || n % 10 == 0)
    cout << mp[n] << endl;
  else
    cout << mp[(n / 10) * 10] << "-" << mp[n % 10] << endl;
  return 0;
}
