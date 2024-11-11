#include <bits/stdc++.h>
using namespace std;
long long n, Li, ans, k;
int can[110];
int main() {
  cin >> n;
  cin >> Li;
  ans = 0;
  for (int i = 1; i < n; i++) cin >> can[i];
  sort(can + 1, can + n);
  while (Li <= can[n - 1]) {
    k = -1;
    do {
      k++;
      can[n - k - 1]--;
      Li++;
      ans++;
      if (Li > can[n - k - 1] + 1) {
        cout << ans;
        return 0;
      }
    } while (n - k - 2 >= 0 && can[n - k - 1] < can[n - k - 2]);
  }
  cout << ans;
  return 0;
}
