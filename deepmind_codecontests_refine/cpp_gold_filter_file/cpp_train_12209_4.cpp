#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, T;
    cin >> n >> T;
    long long int a[n + 1], i, count = 0, count1 = 0, num;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    num = floor(T / 2);
    if (T % 2) {
      for (i = 0; i < n; i++) {
        if (a[i] <= num)
          a[i] = 0;
        else
          a[i] = 1;
      }
    } else {
      for (i = 0; i < n; i++) {
        if (a[i] == num) count++;
      }
      for (i = 0; i < n; i++) {
        if (a[i] < num)
          a[i] = 0;
        else if (a[i] == num && count1 < count / 2) {
          count1++;
          a[i] = 0;
        } else
          a[i] = 1;
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
