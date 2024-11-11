#include <bits/stdc++.h>
using namespace std;
enum month {
  January,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};
int main() {
  string s;
  cin >> s;
  int t;
  cin >> t;
  int temp;
  const char *arr[12] = {"January",   "February", "March",    "April",
                         "May",       "June",     "July",     "August",
                         "September", "October",  "November", "December"};
  for (int i = 0; i < 12; i++) {
    if (arr[i] == s) {
      temp = i;
      break;
    }
  }
  int res = (temp + t) % 12;
  cout << arr[res];
  return 0;
}
