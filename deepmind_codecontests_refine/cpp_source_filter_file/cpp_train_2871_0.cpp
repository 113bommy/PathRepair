#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < (n + 1) / 2; i += 2) {
    swap(a[i - 1], a[n - i]);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
