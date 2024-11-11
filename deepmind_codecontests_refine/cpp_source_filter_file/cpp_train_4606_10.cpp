#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a;
  cin >> a;
  bool was[6];
  for (bool& wa : was) {
    wa = false;
  }
  for (long long i = 0; i < 6 && a != 0; ++i) {
    if (a % 2 == 1) {
      switch (i) {
        case 0:
          was[4] = true;
          break;
        case 1:
          was[1] = true;
          break;
        case 2:
          was[3] = true;
          break;
        case 3:
          was[0] = true;
          break;
        case 4:
          was[2] = true;
          break;
        case 5:
          was[5] = true;
          break;
      }
    }
    a /= 2;
  }
  long long answer = 0;
  for (long long j = 1, i = 0; j < 64; j *= 2) {
    if (was[i]) answer += j;
    i++;
  }
  cout << answer;
}
