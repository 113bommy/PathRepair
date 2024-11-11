#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxi = 0, temp;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (maxi >= a[i])
      a[i] = maxi - a[i] + 1;
    else {
      maxi = a[i];
      a[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
