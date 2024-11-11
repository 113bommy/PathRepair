#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mp;
  mp['0'] = 2;
  mp['1'] = 7;
  mp['2'] = 2;
  mp['3'] = 3;
  mp['4'] = 3;
  mp['5'] = 5;
  mp['6'] = 2;
  mp['7'] = 5;
  mp['8'] = 1;
  mp['9'] = 2;
  char x, y;
  scanf("%ch", &x);
  scanf("%ch", &y);
  int res = mp[x] * mp[y];
  printf("%d\n", res);
  return 0;
}
