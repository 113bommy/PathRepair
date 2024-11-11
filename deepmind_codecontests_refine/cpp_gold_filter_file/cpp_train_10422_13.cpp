#include <bits/stdc++.h>
using namespace std;
int a[100099], b[100099];
int main() {
  long long sum, n;
  cin >> n;
  sum = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    sum += a[i] > b[i] ? a[i] : b[i];
  }
  cout << sum << endl;
  return 0;
}
