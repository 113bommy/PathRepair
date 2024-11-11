#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  cin >> n >> k;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int c = 0;
  i = 0, j = n / 2;
  while (i <= n / 2 && j < n) {
    if (a[j] - a[i] >= k) {
      c++;
      i++;
      j++;
    } else
      j++;
  }
  cout << c << endl;
}
