#include <bits/stdc++.h>
using namespace std;
int a[64];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < 64; i++) {
      a[i] = 0;
    }
    long long sum = 0;
    for (int i = 0; i < m; i++) {
      int tmp;
      cin >> tmp;
      sum += tmp;
      int c1 = 0;
      while (tmp / 2) {
        tmp /= 2;
        c1++;
      }
      a[c1]++;
    }
    if (n > sum) {
      cout << -1 << '\n';
      continue;
    }
    long long tmp = n;
    int BN = 0;
    while (tmp) {
      tmp = tmp >> 1;
      BN++;
    }
    tmp = n;
    for (int i = 0; i <= BN; i++) {
      if (tmp & (1ll << i)) {
        if (a[i]) {
          a[i]--;
          a[i + 1] += a[i] / 2;
        } else {
          int j = 0;
          for (j = i + 1; j <= 64; j++) {
            if (a[j])
              break;
            else
              a[j]++;
          }
          ans += j - i;
          a[j]--;
        }
      } else {
        a[i + 1] += a[i] / 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
