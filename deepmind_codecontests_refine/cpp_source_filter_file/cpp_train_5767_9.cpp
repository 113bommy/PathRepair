#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  string s;
  cin >> s;
  int count1 = 0, count2 = 0;
  if (ex - sx < 0 && ey - sy < 0) {
    int i = 0;
    while (i < t && (count1 < abs(ex - sx) || count2 < abs(ey - sy))) {
      if (s[i] == 'W') {
        count1++;
        i++;
      } else if (s[i] == 'S') {
        count2++;
        i++;
      } else
        i++;
    }
    if (i == t) {
      if (count1 >= abs(ex - sx) && count2 >= abs(ey - sy))
        cout << t << endl;
      else
        cout << -1 << endl;
    } else
      cout << i << endl;
  } else if (ex - sx < 0 && ey - sy > 0) {
    int i = 0;
    while (i < t && (count1 < abs(ex - sx) || count2 < abs(ey - sy))) {
      if (s[i] == 'W') {
        count1++;
        i++;
      } else if (s[i] == 'N') {
        count2++;
        i++;
      } else
        i++;
    }
    if (i == t) {
      if (count1 >= abs(ex - sx) && count2 >= abs(ey - sy))
        cout << t << endl;
      else
        cout << -1 << endl;
    } else
      cout << i << endl;
  } else if (ex - sx > 0 && ey - sy < 0) {
    int i = 0;
    while (i < t && (count1 < abs(ex - sx) || count2 < abs(ey - sy))) {
      if (s[i] == 'E') {
        count1++;
        i++;
      } else if (s[i] == 'S') {
        count2++;
        i++;
      } else
        i++;
    }
    if (i == t) {
      if (count1 >= abs(ex - sx) && count2 >= abs(ey - sy))
        cout << t << endl;
      else
        cout << -1 << endl;
    } else
      cout << i << endl;
  } else if (ex - sx > 0 && ey - sy > 0) {
    int i = 0;
    while (i < t && (count1 < abs(ex - sx) || count2 < abs(ey - sy))) {
      if (s[i] == 'E') {
        count1++;
        i++;
      } else if (s[i] == 'N') {
        count2++;
        i++;
      } else
        i++;
    }
    if (i == t) {
      if (count1 >= abs(ex - sx) && count2 >= abs(ey - sy))
        cout << t << endl;
      else
        cout << -1 << endl;
    } else
      cout << i << endl;
  }
  return 0;
}
