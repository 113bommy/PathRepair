#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int max = a[0];
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      l = i + 1;
    }
  }
  cout << l << " ";
  sort(a, a + n);
  cout << a[n - 2];
  return 0;
}
