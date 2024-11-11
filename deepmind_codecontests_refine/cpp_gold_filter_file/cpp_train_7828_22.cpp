#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, x;
  int mas[101] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mas[x]++;
  }
  for (int i = 0; i < 101; i++) ans = ans + mas[i] / 2;
  if (ans < 2) {
    cout << 0 << endl;
    return 0;
  }
  if (ans % 2 == 0) {
    cout << ans / 2 << endl;
    return 0;
  }
  cout << (ans - 1) / 2;
  return 0;
}
