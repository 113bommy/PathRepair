#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = 1;
    int mini = 10005;
    int mina, minb, minc;
    for (int i = 1; i <= 20000; i++) {
      for (int j = 1; i * j <= 20000; j++) {
        for (int k = 1; i * j * k <= 20000; k++) {
          sum = i + i * j + i * j * k;
          if (mini > abs(i - a) + abs(i * j - b) + abs(i * j * k - c)) {
            mini = abs(i - a) + abs(i * j - b) + abs(i * j * k - c);
            mina = i;
            minb = i * j;
            minc = i * j * k;
          }
        }
      }
    }
    cout << mini << endl;
    cout << mina << " " << minb << " " << minc << endl;
  }
}
