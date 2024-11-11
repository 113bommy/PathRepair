#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string x;
  cin >> x;
  for (char j = 'a'; j != 'z' + 1; ++j) {
    for (int i = 0; i < n && k > 0; ++i) {
      if (j == x[i]) {
        x[i] = '!';
        k--;
      }
    }
    if (k <= 0) break;
  }
  for (int i = 0; i < n; ++i) {
    if (x[i] != '!') cout << x[i];
  }
  return 0;
}
