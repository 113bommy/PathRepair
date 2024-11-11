#include <bits/stdc++.h>
using namespace std;
int a[100000 + 10];
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum % n) {
      int avg = sum / n;
      long long ans = 0, l = 0, r = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] > avg + 1)
          r = r + a[i] - avg;
        else if (a[i] < avg)
          l = l + avg - a[i];
        ans = ans + min(abs(avg - a[i]), abs(avg + 1 - a[i]));
      }
      ans = ans + abs(r - l);
      cout << ans / 2 << endl;
    } else {
      int avg = sum / n;
      long long ans = 0;
      for (int i = 0; i < n; i++) {
        ans = ans + abs(avg - a[i]);
      }
      cout << ans / 2 << endl;
    }
  }
  return 0;
}
