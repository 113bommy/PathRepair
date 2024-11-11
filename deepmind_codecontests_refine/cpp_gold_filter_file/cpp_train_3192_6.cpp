#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int flag = 0, flag2 = 0;
  char a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] == '?' || a[n - 1] == '?') {
    flag = 1;
  }
  for (int i = 1; i < n; i++) {
    if (i != (n - 1)) {
      if (a[i - 1] == a[i + 1] && a[i] == '?') {
        flag = 1;
      }
    }
    if (a[i - 1] == '?' && a[i] == '?') {
      flag = 1;
    }
    if (a[i - 1] == a[i] && a[i - 1] != '?' && a[i] != '?') {
      flag2 = 1;
    }
  }
  if (flag == 1 && flag2 != 1) {
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
    return 0;
  }
}
