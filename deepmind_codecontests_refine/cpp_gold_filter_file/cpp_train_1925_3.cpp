#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long count = 0;
  cin >> n;
  long long a[300], b[300], base[300];
  for (long long i = 0; i < (long long)n; i++) cin >> a[i];
  for (long long i = 0; i < (long long)n; i++) cin >> base[i];
  for (int stage = 0; stage != 2; stage++) {
    for (long long i = 0; i < (long long)n; i++) b[i] = base[i];
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        int pos = -1;
        for (int j = i; j < n; j++) {
          if (a[i] == b[j]) pos = j;
        }
        for (int j = pos; j != i; j--) {
          swap(b[j], b[j - 1]);
          count++;
          if (stage == 1) {
            cout << j << " " << (1 + j) << endl;
          }
        }
      }
    }
    if (stage == 0) cout << count << endl;
  }
  return 0;
}
