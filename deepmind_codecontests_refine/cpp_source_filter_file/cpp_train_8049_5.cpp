#include <bits/stdc++.h>
using namespace std;
int a[20001] = {}, xmax = -20000001, n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n / 2 + 1; i++) {
    if (n % i == 0) {
      for (int j = 0; j < i; j++) {
        int sum = 0;
        for (int k = j; k < n; k += i) {
          sum += a[k];
        }
        if (sum > xmax) xmax = sum;
      }
    }
  }
  cout << xmax << endl;
  return 0;
}
