#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, p, need, t;
  cin >> p >> s >> need;
  t = s;
  while (t >= need) {
    int i = (t / 50) % 475;
    for (int j = 0; j < 25; j++) {
      i = (i * 96 + 42) % 475;
      if (i + 26 == p) {
        cout << "0";
        return 0;
      }
    }
    t -= 50;
  }
  t = s;
  while (1) {
    int i = (t / 50) % 475;
    for (int j = 0; j < 25; j++) {
      i = (i * 96 + 42) % 475;
      if (i + 26 == p) {
        cout << ((t - s) % 100 == 0 ? (t - s) / 100 : (t - s) / 100 + 1);
        return 0;
      }
    }
    t += 50;
  }
}
