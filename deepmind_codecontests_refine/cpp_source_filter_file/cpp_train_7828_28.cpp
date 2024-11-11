#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, x;
  int mas[100] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mas[x]++;
  }
  for (int i = 0; i < 100; i++) ans = ans + mas[i] / 2;
  if (ans < 4) {
    cout << 0 << endl;
    return 0;
  }
  if (ans % 2 == 0) {
    cout << ans / 2 << endl;
    return 0;
  }
  cout << ans / 2 - 1;
  return 0;
}
