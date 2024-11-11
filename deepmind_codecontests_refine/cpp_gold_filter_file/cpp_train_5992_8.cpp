#include <bits/stdc++.h>
using namespace std;
int arr[20002];
int main() {
  long long a, b, c, m, n, p = 0, q, r, i, j, k, t;
  vector<int> v;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    p += arr[i];
  }
  if (n == 2) {
    cout << "1 2" << endl;
    return 0;
  }
  k = p * 2 / n;
  for (j = 1; j <= n / 2; j++) {
    for (c = 1; c <= n; c++) {
      if (arr[c] != 0) {
        b = arr[c];
        t = k - b;
        for (i = c + 1; i <= n; i++) {
          if (t == arr[i]) break;
        }
        cout << c << " " << i << endl;
        arr[c] = 0;
        arr[i] = 0;
      }
    }
  }
  return 0;
}
