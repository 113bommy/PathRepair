#include <bits/stdc++.h>
using namespace std;
long n, i, k;
long a[200];
int main() {
  cin >> n >> k;
  cin >> a[1];
  for (i = 1; i <= n; i++) {
    cin >> a[2 * i];
    cin >> a[(2 * i) + 1];
    if (k > 0 && a[2 * i] > a[(2 * i) - 1] + 1 && a[2 * i] > a[(2 * i) + 1] + 1)
      a[2 * i]--, k--;
  }
  for (i = 1; i <= (2 * n) + 1; i++) cout << a[i] << " ";
  cout << endl;
}
