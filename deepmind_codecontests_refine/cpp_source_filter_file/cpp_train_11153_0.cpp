#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j = 0, r, ctr = 0, ans;
  cin >> n;
  string s, s7;
  cin >> s;
  string s1 = "RGB";
  string s2 = "GBR";
  string s3 = "BGR";
  string s4 = "GRB";
  string s5 = "RBG";
  string s6 = "BRG";
  j = 0;
  for (i = 0; i < n; i++) {
    if (s1[j] != s[i]) {
      ctr++;
    }
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  ans = ctr;
  ctr = 0;
  s7 = s1;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s2[j] != s[i]) {
      ctr++;
    }
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  if (ans > ctr) {
    ans = ctr;
    s7 = s2;
  }
  ctr = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s3[j] != s[i]) {
      ctr++;
    }
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  if (ans > ctr) {
    ans = ctr;
    s7 = s3;
  }
  ctr = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s4[j] != s[i]) {
      ctr++;
    }
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  if (ans > ctr) {
    ans = ctr;
    s7 = s4;
  }
  ctr = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s5[j] != s[i]) {
      ctr++;
    }
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  if (ans > ctr) {
    ans = ctr;
    s7 = s5;
  }
  ctr = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s6[j] != s[i]) {
      ctr++;
    }
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  if (ans > ctr) {
    ans = ctr;
    s7 = s6;
  }
  j = 0;
  for (i = 0; i < n - 3; i++) {
    s7.push_back(s7[j]);
    j++;
    if (j == 3) {
      j = 0;
    }
  }
  if (n < 3) {
    if (n == 1) {
      cout << "0" << endl;
      cout << s;
    } else if (n == 2) {
      if (s[i] == s[i + 1]) {
        if (s[i] == 'R') {
          s[i] = 'G';
        } else if (s[i] == 'G') {
          s[i] = 'B';
        } else if (s[i] == 'B') {
          s[i] = 'R';
        }
        cout << "1" << endl;
        cout << s;
      } else {
        cout << "0" << endl;
        cout << s;
      }
    }
  } else {
    cout << ans << endl;
  }
  cout << s7;
  return 0;
}
