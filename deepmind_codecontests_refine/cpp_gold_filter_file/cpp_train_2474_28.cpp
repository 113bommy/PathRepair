#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n % 2 != 0) {
    cout << a[(n / 2)];
  } else {
    if (a[(n / 2) - 1] < a[(n / 2)]) {
      cout << a[(n / 2) - 1];
    } else {
      cout << a[(n / 2)];
    }
  }
  return 0;
}
