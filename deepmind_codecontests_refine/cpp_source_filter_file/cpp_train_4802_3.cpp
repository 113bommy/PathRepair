#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100100], sum, f[100100];
bool flag;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n / 2; i++) cin >> a[i * 2];
  long long start = 1;
  sum = 0;
  flag = true;
  for (int i = 1; i <= n / 2; i++) {
    do {
      int d = 1;
      int c = 200000;
      while (d <= c) {
        long long mid = (d + c) / 2;
        if (mid * (start + mid - 1) > a[i * 2])
          c = mid - 1;
        else
          d = mid + 1;
      }
      if (c * (start + c - 1) == a[i * 2]) {
        long long temp = (start - 1) / 2;
        a[i * 2 - 1] = temp * temp - sum;
        temp = start + 2 * (c - 1);
        temp = (temp - 1) / 2;
        temp = temp + 1;
        sum = temp * temp;
        start = start + 2 * (c - 1) + 4;
        break;
      } else {
        start = start + 2;
        if (start > a[i * 2]) {
          flag = false;
          break;
        }
      }
    } while (true);
  }
  if (!flag)
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
  }
  return 0;
}
