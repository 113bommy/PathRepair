#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  for (int i = 0; i < k; i++) {
    int tow_1, flo_1, tow_2, flo_2;
    cin >> tow_1 >> flo_1 >> tow_2 >> flo_2;
    long long time = 0;
    int flag = 0;
    if (tow_1 == tow_2) {
      time += abs(flo_1 - flo_2);
    } else {
      if (flo_1 >= a && flo_1 <= b) {
        time += abs(tow_2 - tow_1);
        time += abs(flo_1 - flo_2);
      } else if (flo_1 < a) {
        time += abs(a - flo_1);
        time += abs(tow_2 - tow_1);
        time += abs(a - flo_2);
      } else if (flo_1 > b) {
        time += abs(flo_1 - b);
        time += abs(tow_2 - tow_1);
        time += abs(b - flo_2);
      }
    }
    cout << time << endl;
  }
  return 0;
}
