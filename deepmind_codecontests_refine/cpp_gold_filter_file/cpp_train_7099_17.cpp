#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int temp, cnt, i, n, j;
    cin >> n;
    int arr[n], arr1[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (i = 0; i < n; i++) {
      temp = 300;
      cnt = 0;
      j = i;
      while (temp != i) {
        cnt++;
        temp = arr[j] - 1;
        j = temp;
      }
      arr1[i] = cnt;
    }
    for (i = 0; i < n; i++) {
      if (i + 1 == n) {
        cout << arr1[i] << endl;
      } else {
        cout << arr1[i] << endl;
      }
    }
    t--;
  }
}
