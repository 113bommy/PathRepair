#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4], sum = 0, flag = 0;
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (a[i] + a[j] == sum - (a[i] + a[j])) {
        flag = 1;
        break;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    if (a[i] = sum - a[i]) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
