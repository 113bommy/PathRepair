#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ma = INT_MIN;
  long long int x;
  for (int i = 0; i < n - 1; i++) {
    x = a[i];
    ma = max(x, ma);
    for (int j = i + 1; j < n; j++) {
      x ^= a[j];
      ma = max(ma, x);
    }
  }
  cout << ma << "\n";
}
