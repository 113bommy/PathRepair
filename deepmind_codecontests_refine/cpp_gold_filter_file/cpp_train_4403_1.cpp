#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, flag, count, num1, num2;
  cin >> t;
  while (t--) {
    cin >> n;
    flag = 0;
    count = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (flag == 0 && arr[i] == 1) {
        num1 = i;
        flag = 1;
      }
      if (arr[i] == 1) count++;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (flag == 1 && arr[i] == 1) {
        flag = 0;
        num2 = i;
      }
    }
    cout << (num2 - num1 - 1 - count + 2);
    if (t >= 1) cout << '\n';
  }
}
