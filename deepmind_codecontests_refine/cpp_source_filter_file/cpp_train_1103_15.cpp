#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long int s = 0, n, k, ma = -1, c = 0;
  string nn;
  long long int a[10], b[10];
  for (int i = 0; i < 10; ++i) {
    a[i] = 0;
  }
  cin >> k >> nn;
  for (int i = 0; i < nn.size(); i++) {
    n = nn.at(i) - '0';
    s += n;
    a[n]++;
  }
  for (int i = 0, j = 9; i < 10; ++i, j--) {
    b[j] = a[i];
  }
  for (int i = 0; i < 10; ++i) {
    if (b[i] > 0) ma = i;
  }
  if (s >= k)
    cout << 0 << endl;
  else {
    s = k - s;
    while (s > 0) {
      s -= ma;
      c++;
      b[ma]--;
      if (b[ma] <= 0) {
        for (int i = ma; i >= 0; i--) {
          if (b[i] >= 0) {
            ma = i;
            break;
          }
        }
      }
    }
    cout << c << endl;
  }
  return 0;
}
