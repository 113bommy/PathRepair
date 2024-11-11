#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0;
  int r = n - 1;
  while (l < n - 1 && a[l] < a[l + 1]) l++;
  while (r > 0 && a[r] < a[r - 1]) r--;
  for (int i = l + 1; i <= r; i++) {
    if (a[l] != a[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
