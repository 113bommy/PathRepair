#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, k;
  cin >> b >> k;
  int a[k];
  int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    if (i < k - 1) {
      sum += a[i] * b;
    } else {
      sum += a[i];
    }
  }
  if (sum % 2 == 0) {
    cout << "even";
  } else {
    cout << "odd";
  }
}
