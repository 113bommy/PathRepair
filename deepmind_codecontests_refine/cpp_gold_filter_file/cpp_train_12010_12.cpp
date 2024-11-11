#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, scan = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < n - scan - 1; i++)
      if (a[i] > a[i + 1]) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    scan++;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[0] != a[i + 1]) {
      cout << a[i + 1] << endl;
      exit(0);
    }
  }
  cout << "NO" << endl;
  return 0;
}
