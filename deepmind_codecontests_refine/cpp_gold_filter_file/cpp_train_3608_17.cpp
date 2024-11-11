#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[200005], n, i, sum = 0, cum = 0, index;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  if (sum % 2) {
    for (i = 1; i <= n; i++) {
      cum += a[i];
      if (cum >= ((sum / 2) + 1)) {
        index = i;
        break;
      }
    }
    cout << index << endl;
  } else {
    for (i = 1; i <= n; i++) {
      cum += a[i];
      if (cum >= (sum / 2)) {
        index = i;
        break;
      }
    }
    cout << index << endl;
  }
  return 0;
}
