#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string second;
    cin >> second;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    for (int i = 0; i < second.size(); i++) {
      if (second[i] >= '0' && second[i] <= '9')
        flag3++;
      else if (second[i] >= 'a' && second[i] <= 'z')
        flag2++;
      else
        flag1++;
    }
    if (flag1 && flag2 && flag3)
      ;
    else if (!flag1) {
      if (flag2 && flag3) {
        if (flag2 >= 2) {
          for (int i = 0; i < second.size(); i++) {
            if (second[i] >= 'a' && second[i] <= 'z') {
              second[i] = 'A';
              break;
            }
          }
        } else {
          for (int i = 0; i < second.size(); i++) {
            if (second[i] >= '0' && second[i] <= '9') {
              second[i] = 'A';
              break;
            }
          }
        }
      } else {
        if (!flag2) {
          second[0] = 'a';
          second[1] = 'A';
        }
        if (!flag3) {
          second[0] = '1';
          second[1] = 'A';
        }
      }
    } else if (!flag2) {
      if (flag1 && flag3) {
        if (flag1 >= 2) {
          for (int i = 0; i < second.size(); i++) {
            if (second[i] >= 'A' && second[i] <= 'Z') {
              second[i] = 'a';
              break;
            }
          }
        } else {
          for (int i = 0; i < second.size(); i++) {
            if (second[i] >= '0' && second[i] <= '9') {
              second[i] = 'a';
              break;
            }
          }
        }
      } else {
        if (!flag1) {
          second[0] = 'a';
          second[1] = 'A';
        }
        if (!flag3) {
          second[0] = '1';
          second[1] = 'A';
        }
      }
    } else {
      if (flag1 && flag2) {
        if (flag1 >= 2) {
          for (int i = 0; i < second.size(); i++) {
            if (second[i] >= 'A' && second[i] <= 'Z') {
              second[i] = '0';
              break;
            }
          }
        } else {
          for (int i = 0; i < second.size(); i++) {
            if (second[i] >= 'a' && second[i] <= 'z') {
              second[i] = '0';
              break;
            }
          }
        }
      } else {
        if (!flag1) {
          second[0] = '0';
          second[1] = 'A';
        }
        if (!flag2) {
          second[0] = '1';
          second[1] = 'a';
        }
      }
    }
    cout << second << '\n';
  }
  return 0;
}
