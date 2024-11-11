#include <bits/stdc++.h>
using namespace std;
int x, y, st, ans, p;
char s[27][27];
bool flag;
void tot(int r) {
  int cnt = 0;
  int pp = 0;
  for (int i = 0; i <= y; i++) {
    if (s[r][i] == '0') {
      cnt++;
    } else {
      if (cnt > 0) {
        pp = 1 + cnt;
        pp *= 2;
        ans = max(ans, pp);
        cnt = 0;
      }
    }
  }
  return;
}
void nan(int r) {
  int cnt = 0;
  int pp = 0;
  for (int i = 0; i <= x; i++) {
    if (s[i][r] == '0') {
      cnt++;
    } else {
      if (cnt > 0) {
        pp = 1 + cnt;
        pp *= 2;
        ans = max(ans, pp);
        cnt = 0;
      }
    }
  }
  return;
}
int main() {
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < x; i++) {
    flag = false;
    for (int j = 0; j < y; j++) {
      if (s[i][j] == '1') {
        flag = true;
        if (i - st > 0) {
          p = y + (i - st);
          p *= 2;
          st = i + 1;
          ans = max(ans, p);
        } else {
          st = i + 1;
        }
        tot(i);
      }
    }
    if (!flag) {
      p = y + (i - st + 1);
      p *= 2;
      ans = max(ans, p);
    }
  }
  st = 0;
  flag = false;
  for (int i = 0; i < y; i++) {
    flag = false;
    for (int j = 0; j < x; j++) {
      if (s[j][i] == '1') {
        flag = true;
        if (i - st > 0) {
          p = x + (i - st);
          p *= 2;
          st = i + 1;
          ans = max(ans, p);
        } else {
          st = i + 1;
        }
        nan(i);
      }
    }
    if (!flag) {
      p = x + (i - st + 1);
      p *= 2;
      ans = max(ans, p);
    }
  }
  cout << ans << endl;
}
