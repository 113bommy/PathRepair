#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans = a[0];
  for (int i = 1; i < n; i++) {
    a[i] += ans;
    if (a[i] > 0) {
      ans = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
