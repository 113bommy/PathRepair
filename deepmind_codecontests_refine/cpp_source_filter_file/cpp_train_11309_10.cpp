#include <bits/stdc++.h>
using namespace std;
long long a, b, n, x, y;
int main() {
  cin >> n >> a >> b;
  bool moze = false;
  for (int i = 0; i < n / a; i++) {
    if ((n - i * a) % b == 0) {
      moze = true;
      x = i;
      y = (n - x * a) / b;
      break;
    }
  }
  if (moze) {
    cout << "YES" << endl;
    cout << x << ' ' << y << endl;
  } else
    cout << "NO" << endl;
}
