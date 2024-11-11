#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, neg = 0, count = 0, k = 0, i;
  cin >> n;
  long long int a[n], b[n], c = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    if (a[i] < 0) neg++;
    count++;
    if (neg == 3 && i < n - 1) {
      b[k++] = count - 1;
      neg = 1;
      count = 1;
      c++;
    } else if (i == n - 1 && neg < 3) {
      b[k++] = count;
      c++;
    } else if (neg == 3 && i == n - 1) {
      b[k++] = 1;
      b[k++] = count - 1;
      c++;
    }
  }
  cout << c << "\n";
  for (i = 0; i < k; i++) cout << b[i] << " ";
  return 0;
}
