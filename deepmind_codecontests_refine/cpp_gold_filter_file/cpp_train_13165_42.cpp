#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926535897932384626433832795;
int arr[101];
void fun() {
  arr['0'] = 2;
  arr['1'] = 7;
  arr['2'] = 2;
  arr['3'] = 3;
  arr['4'] = 3;
  arr['5'] = 4;
  arr['6'] = 2;
  arr['7'] = 5;
  arr['8'] = 1;
  arr['9'] = 2;
}
int main() {
  string s;
  cin >> s;
  int ans = 0;
  fun();
  cout << arr[s[0]] * arr[s[1]];
  return 0;
}
