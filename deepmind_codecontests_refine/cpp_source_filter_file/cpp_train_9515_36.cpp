#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, high = 0, cnt[2] = {0};
  cin >> n;
  while (n--) {
    cin >> a;
    if (a == 1) {
      cnt[1]++;
      if (cnt[0] > 0) cnt[0]--;
    } else {
      cnt[0]++;
      high = max(high, cnt[0]);
    }
  }
  cout << cnt[1] + high;
  return 0;
}
