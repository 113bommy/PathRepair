#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k, temp = 0;
    cin >> n >> k;
    long long int ar[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      if (temp < ar[i]) {
        temp = ar[i];
      }
    }
    if (k % 2 == 1) {
      for (int i = 0; i < n; i++) {
        ar[i] = temp - ar[i];
      }
    } else {
      for (int i = 0; i < n; i++) {
        ar[i] = temp - ar[i];
      }
      temp = 0;
      for (int i = 0; i < n; i++) {
        if (temp < ar[i]) {
          temp = ar[i];
        }
      }
      for (int i = 0; i < n; i++) {
        ar[i] = temp - ar[i];
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ar[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
