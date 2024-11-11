#include <bits/stdc++.h>
using namespace std;
int main() {
  int num[10];
  int n, x;
  while (cin >> n) {
    memset(num, 0, sizeof(num));
    int sum = 0;
    for (int i = (1); i <= (n); ++i) {
      scanf("%d", &x);
      num[x]++;
      sum += x;
    }
    if (sum == 1 || sum == 2 || sum == 5) {
      puts("-1");
      continue;
    }
    int ans = 0;
    int temp;
    temp = min(num[1], num[2]);
    ans += temp;
    num[1] -= temp;
    num[2] -= temp;
    num[3] += temp;
    if (num[1]) {
      ans += num[1] / 3 * 2;
      num[3] += num[1] / 3;
      num[1] %= 3;
      if (num[1] == 2) {
        ans += 2;
      } else if (num[1] == 1) {
        if (num[3])
          ans++;
        else
          ans += 2;
      }
    }
    if (num[2]) {
      ans += num[2] / 3 * 2;
      num[3] += num[2] / 3;
      num[2] %= 3;
      if (num[2] == 1) {
        if (num[4])
          ans++;
        else
          ans += 2;
      } else if (num[2] == 2) {
        ans += 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
