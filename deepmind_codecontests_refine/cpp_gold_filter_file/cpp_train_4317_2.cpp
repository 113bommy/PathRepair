#include <bits/stdc++.h>
using namespace std;
int n, i, a, b, j, x = 1, c, d[1000001];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    for (j = x; j <= x + a - 1; j++) {
      d[j] = i;
    }
    x = x + a;
  }
  cin >> b;
  for (i = 1; i <= b; i++) {
    cin >> a;
    cout << d[a] << endl;
  }
}
