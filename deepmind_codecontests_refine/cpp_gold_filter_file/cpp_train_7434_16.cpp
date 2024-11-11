#include <bits/stdc++.h>
using namespace std;
int main() {
  int temp;
  int arr[10000];
  int n, d, sum = 0, p;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  cin >> p;
  if (p - n == 0) {
    cout << sum << endl;
  } else if (p - n > 0)
    cout << sum - (p - n) * d << endl;
  else if (p - n < 0) {
    sum = 0;
    for (int i = 2; i < p + 2; i++) {
      sum += arr[i];
    }
    cout << sum << endl;
  }
  return 0;
}
