#include <bits/stdc++.h>
using namespace std;
int a[10000] = {0}, b[10000] = {0}, n, k, dem = 0;
int main() {
  cin >> n >> k;
  for (int i = (1), _b = (n); i <= _b; i++) {
    cin >> a[i];
    b[a[i]] = i;
  }
  for (int i = (1), _b = (k); i <= _b; i++) {
    dem = 1;
    cout << a[i];
    for (int j = (1), _b = (n * k); j <= _b; j++)
      if (b[j] == 0) {
        dem++;
        cout << " " << j;
        b[j] = i;
        if (dem == n) break;
      }
    cout << endl;
  }
  return 0;
}
