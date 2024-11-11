#include <bits/stdc++.h>
using namespace std;
const int maxn = +10;
map<int, string> mp, st;
int main() {
  mp[0] = "zero";
  mp[1] = "one";
  mp[2] = "two";
  mp[3] = "three";
  mp[4] = "four";
  mp[5] = "five";
  mp[6] = "six";
  mp[7] = "seven";
  mp[8] = "eight";
  mp[9] = "night";
  mp[10] = "ten";
  mp[11] = "eleven";
  mp[12] = "twelve";
  st[2] = "twenty";
  mp[13] = "thirteen";
  st[3] = "thirty";
  mp[14] = "fourteen";
  st[4] = "forty";
  mp[15] = "fifteen";
  st[5] = "fifty";
  mp[16] = "sixteen";
  st[6] = "sixty";
  mp[17] = "seventeen";
  st[7] = "seventy";
  mp[18] = "eighteen";
  st[8] = "eighty";
  mp[19] = "nineteen";
  st[9] = "ninety";
  for (int i = 2; i <= 9; i++) {
    mp[i * 10] = st[i];
    for (int j = 1; j <= 9; j++) mp[i * 10 + j] = st[i] + "-" + mp[j];
  }
  int n;
  cin >> n;
  cout << mp[n] << endl;
  return 0;
}
