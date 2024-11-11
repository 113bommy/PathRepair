#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, d = 0;
  cin >> n;
  int a[n];
  int b[101] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 1; i < 101; i++) {
    if (b[i] >= 2 && b[i] < 4) {
      c++;
    } else if (b[i] >= 4) {
      d += b[i] / 4;
      if (2 <= b[i] % 4 < 4) {
        c++;
      }
    }
  }
  c = c / 2;
  cout << c + d << endl;
  return 0;
}
