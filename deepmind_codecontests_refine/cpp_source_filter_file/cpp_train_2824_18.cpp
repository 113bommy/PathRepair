#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i;
  cin >> n >> k;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int max = 0, count = 0;
  for (i = 0; i < n - 1; i++) {
    count++;
    if (a[i] == a[i + 1]) {
      if (count > max) {
        max = count;
      }
      count = 0;
    }
  }
  if (max != 0)
    cout << max;
  else
    cout << count + 1;
  return 0;
}
