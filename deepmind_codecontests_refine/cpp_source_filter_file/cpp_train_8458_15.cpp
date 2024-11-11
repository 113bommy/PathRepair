#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    int count[n];
    for (int j = 0; j < n; j++) {
      count[j] = 0;
    }
    for (int i = 0; i < 2 * n; i++) {
      count[a[i]] = count[a[i]] + 1;
      if (count[a[i]] == 1) {
        cout << a[i] << " ";
      }
    }
    cout << endl;
  }
}
