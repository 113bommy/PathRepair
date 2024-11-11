#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int l = 1;
  bool v[n];
  v[n - 1] = 1;
  for (int i = 0; i < n; i++) {
    v[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (n - 1 - j > l) {
        cout << j + 1 << " ";
      } else if (n - 1 - j <= l && v[j] == 0 && l != 1) {
        cout << n - (n - 1 - j) % (l / 2) << " ";
        v[j] = 1;
      } else {
        cout << n << " ";
        v[j] = 1;
      }
    }
    l *= 2;
    cout << "\n";
  }
  return 0;
}
