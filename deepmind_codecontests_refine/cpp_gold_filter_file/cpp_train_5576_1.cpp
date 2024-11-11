#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  string s;
  cin >> s;
  int decimalPoint = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      decimalPoint = i;
      break;
    }
  }
  if (decimalPoint == -1) {
  } else {
    int left = -1;
    int right = -1;
    bool reset = true;
    for (int i = decimalPoint + 1; i < n; ++i) {
      if (s[i] < '4') {
        reset = true;
        left = -1;
      } else if (s[i] == '4') {
        if (reset) {
          left = i;
          reset = false;
        } else {
        }
      } else {
        right = i;
        break;
      }
    }
    if (right == -1) {
    } else {
      if (left == -1) {
        if (right == decimalPoint + 1) {
          int checkPos = decimalPoint - 1;
          while (checkPos >= 0) {
            if (s[checkPos] == '9') {
              s[checkPos] = '0';
              checkPos--;
            } else {
              s[checkPos]++;
              break;
            }
          }
          s = s.substr(0, decimalPoint);
          if (checkPos < 0) {
            s = "1" + s;
          }
        } else {
          s[right - 1]++;
          s = s.substr(0, right);
        }
      } else {
        if (t < right - left + 1) {
          s[right - t] = '5';
          s = s.substr(0, right - t + 1);
        } else {
          if (left == decimalPoint + 1) {
            int checkPos = decimalPoint - 1;
            while (checkPos >= 0) {
              if (s[checkPos] == '9') {
                s[checkPos] = '0';
                checkPos--;
              } else {
                s[checkPos]++;
                break;
              }
            }
            s = s.substr(0, decimalPoint);
            if (checkPos < 0) {
              s = "1" + s;
            }
          } else {
            s[left - 1]++;
            s = s.substr(0, left);
          }
        }
      }
    }
  }
  cout << s;
  return 0;
}
