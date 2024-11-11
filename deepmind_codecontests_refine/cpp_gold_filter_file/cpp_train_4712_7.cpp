#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int n, x, l = 0, i = 0;
    cin >> n >> x;
    long int a[n], j = n - 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while (1) {
      int sum = 1;
      for (j; j >= 0; j--) {
        if ((sum * a[j]) >= x) {
          l++;
          j--;
          break;
        }
        sum++;
      }
      if (j < 0) break;
    }
    cout << l << endl;
  }
}
