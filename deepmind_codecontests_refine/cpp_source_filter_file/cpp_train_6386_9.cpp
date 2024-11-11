#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a[1000000], n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mint = 1000000;
  for (i = 1; i < n - 1; i++) {
    if (a[i] < mint && a[i + 1] < mint) {
      mint = max(a[i], a[i + 1]);
    }
  }
  if (mint > a[0] && mint < a[n - 1]) mint = a[0];
  if (mint < a[0] && mint > a[n - 1]) mint = a[n - 1];
  if (mint > a[0] && mint > a[n - 1]) mint = min(a[n - 1], a[0]);
  cout << mint;
}
