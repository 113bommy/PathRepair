#include <bits/stdc++.h>
using namespace std;
bool cmp(int i, int j) { return i < j; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int *pole = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> pole[i];
      sum += pole[i];
    }
    int i = 0;
    int j = n - 1;
    int nasielsom = 0;
    if (sum % k == 0) {
      for (; i < n; i++) {
        if (pole[i] % k != 0) {
          nasielsom++;
          break;
        }
      }
      for (; j > 0; j--) {
        if (pole[j] % k != 0) {
          nasielsom++;
          break;
        }
      }
      if (nasielsom == 0) {
        cout << -1 << endl;
      } else {
        cout << n - min(i + 1, (n + 1) - j) << endl;
      }
    } else {
      cout << n << endl;
    }
  }
  return 0;
}
