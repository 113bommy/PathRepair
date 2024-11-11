#include <bits/stdc++.h>
using namespace std;
string str;
int a[13];
int main(void) {
  int n;
  int cnt = 1, pos;
  int flag = -1;
  cin >> n;
  cin >> str;
  for (int i = 1; i <= 9; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (str[i] - '0' < a[str[i] - '0']) {
      pos = i;
      flag = 1;
      int j;
      for (j = i + 1; j < n; j++) {
        if (str[j] - '0' <= a[str[j] - '0']) {
          cnt++;
        } else {
          break;
        }
      }
    }
    if (flag == 1) break;
  }
  if (flag == 1) {
    int k;
    for (k = 0; k < pos; k++) {
      cout << str[k];
    }
    for (; k < pos + cnt; k++) {
      cout << a[str[k] - '0'];
    }
    for (; k < n; k++) {
      cout << str[k];
    }
    cout << endl;
  } else
    cout << str << endl;
  return 0;
}
