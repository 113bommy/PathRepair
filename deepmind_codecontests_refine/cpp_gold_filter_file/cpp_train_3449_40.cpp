#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  for (int i = 9; i > 0; i--) {
    if (n % i == 0) {
      cout << (n / i) << endl;
      for (int j = 0; j < (n / i); j++) cout << (i) << " ";
      return 0;
    }
  }
  int d = 9, cnt[10] = {0}, ans = 0;
  while (n != 0) {
    ans = ans + (n / d);
    cnt[d] = n / d;
    n %= d;
    d--;
  }
  cout << ans << endl;
  for (int i = 1; i < 10; i++) {
    if (cnt[i] != 0) {
      for (int j = 0; j < cnt[i]; j++) cout << i << " ";
    }
  }
  return 0;
}
