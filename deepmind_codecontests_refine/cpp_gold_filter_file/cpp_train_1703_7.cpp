#include <bits/stdc++.h>
using namespace std;
char toLetter(int n) { return 'A' + n; }
int main() {
  int n, k;
  int sum;
  char str[500005];
  cin >> n >> k;
  getchar();
  gets(str);
  sum = 0;
  if (k > 2) {
    for (int i = 1; i < n; ++i) {
      if (str[i] == str[i - 1]) {
        ++sum;
        int j = 0;
        while (j < k) {
          if (str[i - 1] != toLetter(j) && str[i + 1] != toLetter(j)) {
            str[i] = toLetter(j);
            break;
          }
          ++j;
        }
      }
    }
    cout << sum << endl << str;
    return 0;
  }
  int flag = 0;
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] != toLetter(flag)) {
      ++sum1;
    }
    flag = 1 - flag;
  }
  flag = 1;
  for (int i = 0; i < n; ++i) {
    if (str[i] != toLetter(flag)) {
      ++sum2;
    }
    flag = 1 - flag;
  }
  if (sum1 < sum2) {
    flag = 0;
    cout << sum1 << endl;
    for (int i = 0; i < n; ++i) {
      cout << toLetter(flag);
      flag = 1 - flag;
    }
  } else {
    flag = 1;
    cout << sum2 << endl;
    for (int i = 0; i < n; ++i) {
      cout << toLetter(flag);
      flag = 1 - flag;
    }
  }
  return 0;
}
