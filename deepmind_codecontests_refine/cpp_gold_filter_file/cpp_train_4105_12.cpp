#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, max = -1, max1 = 0, pos, a[1001];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) {
      max1 = max;
      max = a[i];
      pos = i + 1;
    }
  }
  sort(a, a + n);
  cout << pos << " " << a[n - 2] << endl;
}
