#include <bits/stdc++.h>
using namespace std;
bool paltime(int a, int b) {
  vector<int> x, y;
  y.push_back(a / 10);
  y.push_back(a % 10);
  x.push_back(b / 10);
  x.push_back(b % 10);
  if (x[0] == y[1] && x[1] == y[0]) return 1;
  return 0;
}
int main() {
  vector<int> minute;
  int hour;
  string s;
  cin >> s;
  hour = ((s[0] - '0') * 10) + (s[1] - '0');
  minute.push_back(s[3] - '0');
  minute.push_back(s[4] - '0');
  for (int j = minute[0] * 10 + minute[1] + 1; j < 60; j++) {
    if (paltime(hour, j)) {
      if (hour / 10 == 0) cout << "0";
      cout << hour;
      cout << ":";
      if (j / 10 == 0) cout << "0";
      cout << j;
      return 0;
    }
  }
  for (int i = hour + 1; i < 24; i++) {
    for (int j = 0; j < 60; j++) {
      if (paltime(i, j)) {
        if (i / 10 == 0) cout << "0";
        cout << i;
        cout << ":";
        if (j / 10 == 0) cout << "0";
        cout << j;
        return 0;
      }
    }
  }
  cout << "00:00";
  return 0;
}
