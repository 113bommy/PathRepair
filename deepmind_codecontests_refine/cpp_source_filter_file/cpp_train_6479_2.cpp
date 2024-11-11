#include <bits/stdc++.h>
using namespace std;
int table[105][55][2];
string s;
int calc(int moves, int changed, int dir) {
  if (moves == 0) {
    if (changed == 0 && dir == 1) {
      return 0;
    }
    return -100000;
  }
  if (table[moves][changed][dir] == -100000) {
    int &ans = table[moves][changed][dir];
    if (changed > 0) {
      if (s[moves - 1] == 'T') {
        ans = max(ans, 1 - 2 * (dir == 0) + calc(moves - 1, changed - 1, dir));
      } else {
        ans = max(ans, calc(moves - 1, changed - 1, 1 - dir));
      }
    }
    if (s[moves - 1] == 'T') {
      ans = max(ans, calc(moves - 1, changed, 1 - dir));
    } else {
      ans = max(ans, 1 - 2 * (dir == 0) + calc(moves - 1, changed, dir));
    }
  }
  return table[moves][changed][dir];
}
int calc2(int moves, int changed, int dir) {
  if (moves == 0) {
    if (changed == 0 && dir == 1) {
      return 0;
    }
    return 100000;
  }
  if (table[moves][changed][dir] == 100000) {
    int &ans = table[moves][changed][dir];
    if (changed > 0) {
      if (s[moves - 1] == 'T') {
        ans =
            min(ans, -1 + 2 * (dir == 1) + calc2(moves - 1, changed - 1, dir));
      } else {
        ans = min(ans, calc2(moves - 1, changed - 1, 1 - dir));
      }
    }
    if (s[moves - 1] == 'T') {
      ans = min(ans, calc2(moves - 1, changed, 1 - dir));
    } else {
      ans = min(ans, -1 + 2 * (dir == 1) + calc2(moves - 1, changed, dir));
    }
  }
  return table[moves][changed][dir];
}
int main() {
  while (cin >> s) {
    int changes;
    cin >> changes;
    int ans = 0;
    for (int i = 0; i <= s.length(); i++) {
      for (int j = 0; j <= changes; j++) {
        for (int d = 0; d < 2; d++) {
          table[i][j][d] = -100000;
        }
      }
    }
    ans = max(ans, calc(s.length(), changes, 0));
    ans = max(ans, calc(s.length(), changes, 1));
    for (int i = 0; i <= s.length(); i++) {
      for (int j = 0; j <= changes; j++) {
        for (int d = 0; d < 2; d++) {
          table[i][j][d] = 100000;
        }
      }
    }
    ans = max(ans, -calc2(s.length(), changes, 0));
    ans = max(ans, -calc2(s.length(), changes, 1));
    cout << ans << endl;
  }
  return 0;
}
