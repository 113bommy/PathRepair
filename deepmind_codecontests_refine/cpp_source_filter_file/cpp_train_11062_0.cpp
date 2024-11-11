#include <bits/stdc++.h>
using namespace std;
long long int a[200007];
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, j, k, l, n, count = 0, flag = 0, count1 = 0, count2 = 0,
                                 count3 = 0;
    bool flag1 = 0;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = n - 1; i >= 1; i--) {
      if (a[i] < a[i - 1])
        count++;
      else if (a[i] == a[i - 1])
        count3++;
      else if (a[i] > a[i - 1])
        count1++;
    }
    if (count == n - 1 || count1 == n - 1 || count1 + count3 == n - 1 ||
        count3 + count == n - 1)
      cout << 0 << "\n";
    else {
      if (a[n - 1] <= a[n - 2]) {
        for (i = n - 1; i >= 1; i--) {
          if (flag == 0) {
            if (a[i] <= a[i - 1]) count2++;
          }
          if (a[i] > a[i - 1]) flag = 1;
          if (flag == 1 && a[i] >= a[i - 1]) count2++;
          if (flag == 1 && a[i] < a[i - 1]) break;
        }
        cout << n - count2 - 1 << "\n";
      } else {
        for (i = n - 1; i >= 1; i--) {
          if (a[i] > a[i - 1])
            count2++;
          else
            break;
        }
        cout << n - 1 - count2 << "\n";
      }
    }
  }
}
