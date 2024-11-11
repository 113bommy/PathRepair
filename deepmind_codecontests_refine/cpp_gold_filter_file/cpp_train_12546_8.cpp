#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  long long sum = 0;
  scanf("%d", &x);
  long long a[x];
  for (int i = 0; i < x; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  if (x == 1) {
    if (a[0] % 2 == 0) {
      cout << sum;
      return 0;
    } else {
      printf("0");
      return 0;
    }
  }
  if (sum % 2 == 0) {
    cout << sum;
    return 0;
  }
  sort(a, a + x);
  for (int i = 0; i < x; i++) {
    if (a[i] % 2 != 0) {
      sum = sum - a[i];
      cout << sum;
      return 0;
    }
  }
}
