#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x = n / 2;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << "1 1\n";
    cout << -arr[0] << "\n";
    cout << "1 1\n 0\n";
    cout << "1 1\n 0\n";
    return 0;
  }
  cout << 1 << " " << n - 1 << "\n";
  for (long long i = 0; i < n - 1; i++) {
    cout << 1LL * arr[i] * (n - 1) << " ";
    arr[i] = arr[i] + (1LL * arr[i] * (n - 1));
  }
  cout << "\n";
  cout << n << " " << n << "\n";
  cout << n - arr[n - 1] << "\n";
  arr[n - 1] = 0;
  cout << "1 " << n << "\n";
  for (int i = 0; i < n; i++) {
    cout << -arr[i] << " ";
  }
}
