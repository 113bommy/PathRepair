#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int mx = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) {
      mx++;
    } else if (a[i] > mx) {
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
