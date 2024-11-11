#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sizes = 2 * n;
  long long int a[sizes];
  for (int i = 0; i < sizes; i++) {
    cin >> a[i];
  }
  long long int sum = 0;
  for (int i = n; i < sizes; i++) {
    sum += a[i];
  }
  long long int sumhalf = 0;
  for (int i = 0; i < n; i++) {
    sumhalf += a[i];
  }
  int flag = 0;
  if (sumhalf == sum) {
    for (int i = 0; i < n; i++) {
      long long int tochange = a[i];
      for (int j = n; j < sizes; j++) {
        if (a[j] != tochange) {
          long long int temp = a[j];
          a[j] = tochange;
          a[i] = temp;
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        break;
      }
    }
  }
  if (flag == 0 && sum == sumhalf) {
    cout << "-1";
  } else {
    for (int i = 0; i < sizes; i++) {
      cout << a[i] << " ";
    }
  }
  return 0;
}
