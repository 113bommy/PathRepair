#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n / 2; i += 2) {
    swap(a[i], a[n - i + 1]);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
