#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<char> v;
  char ch;
  int i = 0;
  while (i < 5) {
    cin >> ch;
    v.push_back(ch);
    i++;
  }
  int min, count = 0;
  cin >> min;
  while (min >= 60) {
    count++;
    min = min - 60;
  }
  int hours = 10 * (v[0] - 48) + (v[1] - 48);
  hours = hours + count;
  min = min + 10 * (v[3] - 48) + (v[4] - 48);
  if (min >= 60) {
    min = min % 60;
    hours = hours + 1;
  }
  while (hours >= 24) {
    hours = hours - 24;
  }
  if (hours <= 9) {
    cout << "0" << hours << ":";
  } else {
    cout << hours << ":";
  }
  if (min <= 9) {
    cout << "0" << min;
  } else {
    cout << min;
  }
  return 0;
}
