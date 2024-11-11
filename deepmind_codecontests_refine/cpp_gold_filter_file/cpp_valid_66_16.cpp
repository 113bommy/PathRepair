#include <bits/stdc++.h>
using namespace std;
int sum(int n) {}
int main() {
  int t;
  cin >> t;
  int v[100000];
  while (t--) {
    int k, j = 1;
    cin >> k;
    for (int i = 1; i < 2 * k; i++) {
      if (i % 3 == 0) {
        continue;
      }
      if (i % 10 == 3) {
        continue;
      }
      v[j] = i;
      j++;
    }
    cout << v[k] << "\n";
  }
  return 0;
}
