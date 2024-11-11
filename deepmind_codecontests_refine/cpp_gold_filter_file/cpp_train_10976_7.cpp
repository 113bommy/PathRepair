#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[2001], i;
  cin >> n >> k;
  i = 0;
  int y = n;
  while (n--) {
    cin >> a[i];
    i++;
  }
  sort(a, a + y);
  int ctr = 0;
  for (i = 0; i <= y - 3; i += 3) {
    if ((a[i] <= 5 - k) && (a[i + 1] <= 5 - k) && (a[i + 2] <= 5 - k)) ctr++;
  }
  cout << ctr << "\n";
  return 0;
}
