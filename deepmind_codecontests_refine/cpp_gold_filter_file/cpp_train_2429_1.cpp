#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  bool flag = false;
  cin >> s;
  stringstream ss(s);
  char arr[2 * n];
  int min0 = 10;
  int max0 = 0;
  int min1 = 10;
  int max1 = 0;
  for (int i = 0; i < 2 * n; i++) {
    arr[i] = s.at(i);
    if (i < n) {
      if (min0 > (int)arr[i] - 48) {
        min0 = (int)arr[i] - 48;
      }
      if (max0 < (int)arr[i] - 48) {
        max0 = (int)arr[i] - 48;
      }
    } else {
      if (min1 > (int)arr[i] - 48) {
        min1 = (int)arr[i] - 48;
      }
      if (max1 < (int)arr[i] - 48) {
        max1 = (int)arr[i] - 48;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((int)arr[i] - 48 > (int)arr[j] - 48) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      if ((int)arr[i + n] - 48 > (int)arr[j + n] - 48) {
        char temp = arr[i + n];
        arr[i + n] = arr[j + n];
        arr[j + n] = temp;
      }
    }
  }
  if (min0 < min1) {
    for (int i = 0; i < n; i++) {
      if (int(arr[i]) >= int(arr[i + n])) {
        flag = true;
        break;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (int(arr[i]) <= int(arr[i + n])) {
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
