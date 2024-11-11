#include <bits/stdc++.h>
using namespace std;
int a[3000], b[3000], n, sum;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (b[a[i]] == 0)
      continue;
    else {
      sum = 1;
      for (int j = a[i] + 1; j <= n; j++) {
        sum += b[j];
      }
      cout << sum << ' ';
    }
  }
  return 0;
}
