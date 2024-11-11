#include <bits/stdc++.h>
using namespace std;
int main() {
  string t, s;
  cin >> t;
  cin >> s;
  int a[10] = {0}, q[10] = {0};
  int temp;
  for (auto i = 0; i < t.size(); i++) {
    temp = t[i] - '0';
    if (temp == 2 || temp == 5) {
      a[2]++;
    } else if (temp == 6 || temp == 9) {
      a[6]++;
    } else {
      a[temp]++;
    }
  }
  for (auto i = 0; i < s.size(); i++) {
    temp = s[i] - '0';
    if (temp == 2 || temp == 5) {
      q[2]++;
    } else if (temp == 6 || temp == 9) {
      q[6]++;
    } else {
      q[temp]++;
    }
  }
  int m = INFINITY;
  for (int i = 0; i < 10; i++) {
    if (a[i] != 0 && q[i] == 0) {
      cout << 0;
      return 0;
    } else if (a[i] != 0 && q[i] != 0) {
      temp = q[i] / a[i];
      if (m > temp) {
        m = temp;
      }
    }
  }
  cout << m;
  return 0;
}
