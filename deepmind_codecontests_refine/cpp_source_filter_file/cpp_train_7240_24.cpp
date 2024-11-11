#include <bits/stdc++.h>
using namespace std;
int z[5000005];
int main() {
  int n, a, x, y, flag;
  int z[100005], h[100005];
  cin >> n;
  x = y = flag = 1;
  for (a = 0; n > a; a++) {
    cin >> z[a];
  }
  h[n - 1] = z[n - 1];
  x += h[n - 1];
  for (a = n - 2; a >= 0; a--) {
    if (flag % 2 == 1) {
      h[a] = z[a] - x + y;
      y += h[a];
      flag++;
    } else {
      h[a] = z[a] + x - y;
      x += h[a];
      flag++;
    }
  }
  for (a = 0; n > a; a++) {
    cout << h[a] << " ";
  }
  cout << endl;
  return 0;
}
