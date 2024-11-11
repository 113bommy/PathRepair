#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long num = a[0] * a[n - 1];
    int l = 0, r = n - 1;
    bool flag = 1;
    for (long long i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        if (a[l] != i || a[r] != num / i) {
          flag = 0;
        } else {
          l++;
          r--;
        }
      }
    }
    if (l <= r) flag = 0;
    if (flag == 0) {
      cout << "-1" << endl;
    } else {
      cout << num << endl;
    }
  }
}
