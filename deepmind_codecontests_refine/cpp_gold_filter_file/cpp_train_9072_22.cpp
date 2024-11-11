#include <bits/stdc++.h>
using namespace std;
void print(long long* a, long long n) {
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
}
int32_t main() {
  long long n;
  cin >> n;
  cout << n / 2 + 1 << endl;
  for (long long i = 0; i < n / 2 + 1; i++) {
    cout << 1 << " " << i + 1 << '\n';
  }
  for (long long i = n / 2 + 1, j = 1; i < n; i++, j++) {
    cout << j + 1 << " " << n / 2 + 1 << '\n';
  }
  return 0;
}
