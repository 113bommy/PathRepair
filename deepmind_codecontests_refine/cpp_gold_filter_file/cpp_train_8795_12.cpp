#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int i, n, j = 0, k, l;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n);
  while (a[0] <= a[n - 1]) {
    j++;
    a[n - 1]--;
    a[0]++;
    sort(a + 1, a + n);
  }
  cout << j << endl;
  return 0;
}
