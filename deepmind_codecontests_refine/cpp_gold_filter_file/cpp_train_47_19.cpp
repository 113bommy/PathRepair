#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x[100001], h[100001];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
  }
  x[n] = 1e+9 * 2 + 1;
  int a = 0, b = -1e+9 * 2 + 1;
  for (int i = 0; i < n; i++) {
    if (b < x[i] - h[i]) {
      a++;
      b = x[i];
    } else if (x[i] + h[i] < x[i + 1]) {
      a++;
      b = x[i] + h[i];
    } else {
      b = x[i];
    }
  }
  cout << a << endl;
  return 0;
}
