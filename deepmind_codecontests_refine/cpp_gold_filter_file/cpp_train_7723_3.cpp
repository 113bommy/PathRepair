#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n[1000], a[1000][10];
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n[i];
    for (int j = 0; j < n[i]; j++) {
      cin >> a[j][i];
    }
  }
  int count{0};
  for (int i = 0; i < k; i++) {
    for (int k = n[i]; k > 0; k--) {
      for (int j = 0; j < n[i]; j++) {
        if (a[j][i] >= k) count++;
      }
      if (count >= k) {
        cout << k << endl;
        count = 0;
        break;
      }
      count = 0;
    }
  }
}
