#include <bits/stdc++.h>
using namespace std;
int c[100];
string s;
int main() {
  cin >> c[4] >> c[7] >> c[47] >> c[74];
  if (max(c[47], c[74]) > max(c[4], c[7]) || abs(c[47] - c[74]) > 1) {
    cout << "-1" << endl;
    return 0;
  }
  if (c[74] > c[47]) {
    while (c[74]--) {
      s += "74";
      c[4]--;
      c[7]--;
    }
  } else if (c[74] < c[47]) {
    while (c[47]--) {
      s += "47";
      c[4]--;
      c[7]--;
    }
  } else {
    if (c[4] >= c[7]) {
      while (c[47]--) {
        s += "47";
        c[4]--;
        c[7]--;
      }
      s += "4";
      c[4]--;
    } else {
      while (c[74]--) {
        s += "74";
        c[4]--;
        c[7]--;
      }
      s += "7";
      c[7]--;
    }
  }
  if (c[4] < 0 || c[7] < 0) {
    cout << "-1" << endl;
    return 0;
  }
  int last7 = -1, last4 = -1;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '7')
      last7 = i;
    else
      last4 = i;
  if (last4 == -1 && c[4] > 0) {
    cout << "-1" << endl;
    return 0;
  }
  if (last7 == -1 && c[7] > 0) {
    cout << "-1" << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    cout << s[i];
    if (s[i] == '4')
      while (0 < c[4]--) cout << s[i];
    else if (i == last7)
      while (0 < c[7]--) cout << s[i];
  }
  cout << endl;
  return 0;
}
