#include <bits/stdc++.h>
using namespace std;
int cnt[50];
void solve(int T) {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum ^= x;
    int k = 0;
    while (x) {
      if (x % 2) {
        cnt[k]++;
        x /= 2;
      } else {
        x /= 2;
      }
      k++;
    }
  }
  if (n % 2 == 0 && sum != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    if (n % 2) {
      cout << n - 1 << endl;
      for (int i = 1; i + 2 <= n; i += 2) {
        printf("%d %d %d\n", i, i + 1, i + 2);
      }
      for (int i = 1; i <= n - 1; i += 2) {
        printf("%d %d %d\n", i, i + 1, n);
      }
    } else {
      cout << n - 2 << endl;
      for (int i = 1; i + 2 <= n - 1; i += 2) {
        printf("%d %d %d\n", i, i + 1, i + 2);
      }
      for (int i = 1; i <= n - 2; i += 2) {
        printf("%d %d %d\n", i, i + 1, n);
      }
    }
  }
}
signed main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
