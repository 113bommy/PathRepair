#include <bits/stdc++.h>
using namespace std;
int n, a[100009], w1, w2;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 100)
      w1++;
    else
      w2++;
  }
  w2 %= 2;
  if (w2 && w1 < 2) {
    cout << "NO";
    return 0;
  }
  if (w2) w2 = 0, w1 -= 2;
  if (w1 % 2)
    cout << "NO";
  else
    cout << "YES";
}
