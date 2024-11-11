#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[15], sum = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
  }
  if (n == 1) {
    cout << -1;
    return 0;
  }
  if (n == 2 && a[0] == a[1]) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < n - 1; i++) {
    sum += a[i];
  }
  if (sum == a[n - 1]) {
    cout << 2 << endl;
    cout << n - 1 << " " << n;
    return 0;
  }
  cout << 1 << endl;
  cout << 1;
}
