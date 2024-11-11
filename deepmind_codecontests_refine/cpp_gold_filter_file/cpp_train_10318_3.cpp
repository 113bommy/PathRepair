#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], count[100];
  bool flag = true;
  for (int i = 0; i < 100; i++) count[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    count[a[i] - 1]++;
  }
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 100; i++) {
    if (count[i] == 1)
      sum1++;
    else if (count[i] > 2)
      sum2++;
  }
  if (sum1 % 2 == 0 || sum2 > 0) {
    cout << "YES" << endl;
    int j = 0, lim = sum1 / 2;
    if (sum1 % 2 == 0) {
      for (int i = 0; i < n; i++) {
        if (count[a[i] - 1] == 1 && j < lim) {
          cout << "B";
          j++;
        } else
          cout << "A";
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (count[a[i] - 1] == 1 && j < lim) {
          cout << "B";
          j++;
        } else if (count[a[i] - 1] > 2 && flag) {
          cout << "B";
          flag = false;
        } else
          cout << "A";
      }
    }
  } else
    cout << "NO";
  return 0;
}
