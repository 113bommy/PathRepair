#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i, j;
  long long sum = 0;
  int m = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    m = max(a[i], m);
  }
  for (i = m; i <= 250; i++) {
    if (n * i - sum > sum) {
      cout << i << endl;
      break;
    }
  }
}
