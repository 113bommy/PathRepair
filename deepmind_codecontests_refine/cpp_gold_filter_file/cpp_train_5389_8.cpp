#include <bits/stdc++.h>
using namespace std;
string str;
void cal(char c1, char c2, int &res) {
  int x1 = -1, x2 = -1;
  int n = str.size();
  for (int i = n - 1; i >= 0; i -= 1) {
    if (str[i] == c1)
      x1 = max(x1, i);
    else if (str[i] == c2)
      x2 = max(x2, i);
  }
  if (x1 != -1 && x2 != -1 && x1 != x2) {
    if (x1 < x2) {
      int add = 0;
      if (x1 == 0) {
        int k = x1 + 1;
        while (k < n) {
          if (k == x2 || str[k] == '0')
            k += 1;
          else
            break;
        }
        if (k < n || n == 2) {
          if (k < x2)
            k -= 1;
          else
            k -= 2;
          add = k;
        }
      }
      res = min(res, (n - x2 - 1) + (n - x1 - 1 - 1) + add);
    } else {
      int add = 0;
      if (x2 == 0) {
        int k = x2 + 1;
        while (k < n) {
          if (k == x1 || str[k] == '0')
            k += 1;
          else
            break;
        }
        if (k < n || n == 2) {
          if (k < x1)
            k -= 1;
          else
            k -= 2;
          add = k;
        }
      }
      res = min(res, (n - x2 - 1) + (n - x1 - 1 - 1 + 1) + add);
    }
  }
}
int main() {
  cin >> str;
  int res = 1e9;
  cal('2', '5', res);
  cal('5', '0', res);
  cal('7', '5', res);
  int n = str.size();
  for (int i = n - 1; i >= 0; i -= 1) {
    if (str[i] == '0') {
      for (int j = i - 1; j >= 0; j -= 1) {
        if (str[j] == '0') {
          res = min(res, n - i - 1 + n - j - 1 - 1);
        }
      }
    }
  }
  if (res == 1e9)
    cout << -1;
  else
    cout << res << endl;
}
