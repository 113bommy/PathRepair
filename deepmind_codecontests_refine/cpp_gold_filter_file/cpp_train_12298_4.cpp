#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n, P1, P2, P3, T1, T2;
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
  unsigned int b, e;
  cin >> b >> e;
  unsigned int total = (e - b) * P1;
  for (int i = 1; i < n; i++) {
    cin >> b;
    if ((b - e) >= T1) {
      total += T1 * P1;
      if ((b - e) >= T1 + T2) {
        total += T2 * P2;
        total += (b - e - T1 - T2) * P3;
      } else {
        total += (b - e - T1) * P2;
      }
    } else {
      total += (b - e) * P1;
    }
    cin >> e;
    total += (e - b) * P1;
  }
  cout << total << endl;
  return 0;
}
