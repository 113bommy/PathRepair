#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 1, m[101], a, i = 1, j = 0;
  cin >> n;
  for (int i = 0; i <= 100; i++) m[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a < 0 && j >= 2) {
      j = 1;
      k++;
      m[k]++;
    } else {
      m[k]++;
      if (a < 0) j++;
    }
  }
  cout << k << endl;
  for (int i = 1; i <= k; i++) cout << m[i];
  return 0;
}
