#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[7];
  long long sum = 0;
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (n > sum) n = n % sum;
  if (n == 0) {
    int i;
    for (i = 6; i >= 0; i--) {
      if (a[i] != 0) break;
    }
    cout << i + 1;
  } else {
    int i;
    for (i = 0; i < 7; i++) {
      n -= a[i];
      if (n <= 0) {
        break;
      }
    }
    cout << i + 1;
  }
}
