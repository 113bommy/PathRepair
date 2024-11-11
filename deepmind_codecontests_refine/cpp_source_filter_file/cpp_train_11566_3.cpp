#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1000], i, j = 0, b[1000], s = 0, q, max;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      s++;
      b[j] = i;
      j++;
    }
  }
  cout << s << endl;
  max = b[0];
  for (j = 0; j < s; j++) {
    if (b[j] > max) max = b[j];
  }
  for (j = 0; j < s - 1; j++) {
    q = b[j + 1] - b[j];
    cout << q << " ";
  }
  cout << n - max + 1;
  return 0;
}
