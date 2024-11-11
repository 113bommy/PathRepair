#include <bits/stdc++.h>
using namespace std;
char str[500005];
int main() {
  cin >> str;
  int len = strlen(str);
  int md_l = 0, md_r = 0;
  int pos_l = 0, pos_r = len - 1;
  int vl = 0;
  for (int i = 0; i < len; i++) {
    if (md_l == 0) {
      if (str[i] == '[') {
        md_l++;
      }
    } else if (md_l == 1) {
      if (str[i] == ':') {
        md_l++;
        pos_l = i + 1;
        break;
      }
    }
  }
  for (int i = len - 1; i >= 0; i--) {
    if (md_r == 0) {
      if (str[i] == ']') {
        md_r++;
      }
    } else if (md_r == 1) {
      if (str[i] == ':') {
        md_r++;
        pos_r = i - 1;
        break;
      }
    }
  }
  if (pos_l > pos_r + 1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = pos_l; i <= pos_r; i++) {
    if (str[i] == '|') {
      vl++;
    }
  }
  if (md_l == 2 && md_r == 2) {
    cout << vl + 4 << endl;
  } else {
    cout << -1 << endl;
  }
}
