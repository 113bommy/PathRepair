#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long a[n];
  long long count = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i] <= 0) {
      sum += a[i];
      count++;
    }
    if (count == m) {
      break;
    }
  }
  cout << sum;
  return 0;
}
