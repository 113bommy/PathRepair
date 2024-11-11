#include <bits/stdc++.h>
using namespace std;
void func() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long int z = 0;
  long long int p[n];
  for (long long int i = 0; i < n; i += 2) {
    p[i] = a[z++];
  }
  for (long long int i = 1; i < n; i += 2) {
    p[i] = a[z++];
  }
  for (long long int i = 0; i < n; i++) {
    cout << p[i] << ' ';
  }
  cout << '\n';
}
int32_t main() {
  func();
  return 0;
}
