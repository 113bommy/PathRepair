#include <bits/stdc++.h>
using namespace std;
int arr[6][6];
int r, c;
void clr() {
  int i, j;
  for (i = 1; i < 5; i++) {
    if (arr[i][0] == 4) {
      for (j = 0; j < 5; j++) {
        arr[i][j] = 0;
        arr[0][j]--;
      }
    }
  }
  for (j = 1; j < 5; j++) {
    if (arr[0][j] == 4) {
      for (i = 0; i < 5; i++) {
        arr[i][j] = 0;
        arr[i][0]--;
      }
    }
  }
  arr[0][0] = 0;
  return;
}
void chkver() {
  int i, j;
  for (j = 1; j < 5; j++) {
    for (i = 1; i < 4; i++) {
      if (arr[i][j] == 0 and arr[i + 1][j] == 0) {
        arr[i][j] = 1, arr[i + 1][j] = 1;
        r = i, c = j;
        arr[i][0]++, arr[0][j]++;
        arr[i + 1][0]++, arr[0][j]++;
        return;
      }
    }
  }
}
void chkhor() {
  int i, j;
  for (i = 1; i < 5; i++) {
    for (j = 1; j < 4; j++) {
      if (arr[i][j] == 0 and arr[i][j + 1] == 0) {
        arr[i][j] = 1, arr[i][j + 1] = 1;
        r = i, c = j;
        arr[i][0]++, arr[0][j]++;
        arr[i][0]++, arr[0][j + 1]++;
        return;
      }
    }
  }
}
int main() {
  string s;
  cin >> s;
  int len = s.length(), i, j, k;
  for (i = 0; i < len; i++) {
    if (s[i] == '0') {
      chkver();
      cout << r << " " << c << endl;
    } else {
      chkhor();
      cout << r << " " << c << endl;
    }
    clr();
  }
  return 0;
}
