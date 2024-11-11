#include <bits/stdc++.h>
using namespace std;
int a, ta;
int b, tb;
string s;
int str_to_int(string &s) {
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    res *= 10;
    res += s[i] - '0';
  }
  return res;
}
int my_max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int my_min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int main() {
  cin >> a >> ta >> b >> tb;
  cin >> s;
  string h = s.substr(0, 2);
  string m = s.substr(3, 2);
  int hh = str_to_int(h);
  int mm = str_to_int(m);
  int minute = 60 * hh + mm;
  int start = my_max(minute - tb, 300);
  int end = my_min(minute + ta, 1439);
  int count = 0;
  for (int i = start; i <= end; i++) {
    if ((i - 300) % b == 0) {
      count++;
    }
  }
  if (minute - tb >= 300) {
    if ((minute - tb) % b == 0) {
      count--;
    }
  }
  if ((minute + ta - 300) % b == 0) {
    count--;
  }
  cout << count << endl;
  return 0;
}
