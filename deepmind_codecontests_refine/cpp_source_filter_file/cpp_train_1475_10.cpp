#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ct1 = 0, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n - 1);
  for (i = 0; i < n; i++) {
    if (a[i] >= ct1 + 1) ct1++;
  }
  cout << ct1;
  return 0;
}
