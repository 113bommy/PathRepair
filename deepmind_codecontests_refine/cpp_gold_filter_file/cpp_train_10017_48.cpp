#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, p = 0, q;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n; i++) {
    if ((arr[i] % 2) != 0) p++;
    if ((p % 2) != 0)
      q = p;
    else
      q = n - p;
  }
  cout << q;
  return 0;
}
