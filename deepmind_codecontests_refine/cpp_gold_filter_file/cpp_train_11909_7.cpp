#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  if (n % 2 == 0)
    printf("-1\n");
  else {
    for (k = 0; k < n; k++) printf("%d ", ((n / 2 + 1 - k) + n) % n);
    cout << endl;
    for (k = 0; k < n; k++) printf("%d ", ((n / 2 + 2 * k) + n) % n);
    cout << endl;
    for (k = 0; k < n; k++) printf("%d ", k);
  }
  cout << endl;
}
