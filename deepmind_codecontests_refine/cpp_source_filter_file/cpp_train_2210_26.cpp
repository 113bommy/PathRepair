#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int num[25];
    memset(num, 0, sizeof(num));
    int x;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      num[x + 10]++;
    }
    long long ans = 0;
    for (int i = 0; i < 11; ++i) {
      if (i != 10)
        ans += (num[i] * num[20 - i]);
      else {
        ans += (num[i] * (num[i] - 1) / 2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
