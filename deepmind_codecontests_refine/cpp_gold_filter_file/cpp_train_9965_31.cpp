#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<bool> lol(50001, false);
  long long ans = 0;
  if (n < 600) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n - i; j++) {
        for (int k = 0; k <= n - i - j; k++) {
          lol[4 * j + 9 * k + 49 * (n - i - j - k)] = true;
        }
      }
    }
    for (int i = 0; i < 50001; i++) {
      if (lol[i]) ans++;
    }
    cout << ans;
    return 0;
  } else {
    for (int i = 0; i <= 300; i++) {
      for (int j = 0; j <= 120; j++) {
        for (int k = 0; k <= 22; k++) {
          lol[4 * i + 9 * j + 49 * k] = true;
          lol[29400 - (45 * i + 40 * j + 49 * k)] = true;
        }
      }
    }
    long long up = 0;
    long long down = 0;
    for (int i = 0; i < 1001; i++) {
      if (lol[i]) down++;
    }
    for (int i = 29400; i >= 28400; i--) {
      if (lol[i]) up++;
    }
    ans = (49 * n - 1000) - (1000) + up + down - 1;
    cout << ans;
    return 0;
  }
  return 0;
}
