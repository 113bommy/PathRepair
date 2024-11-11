#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(a, 0, sizeof(a));
    int m;
    long long n, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      long long x;
      cin >> x;
      sum += x;
      for (int j = 0; j < 60; j++)
        if ((x >> j) & 1 == 1) a[j]++;
    }
    if (sum < n) {
      cout << "-1" << endl;
      continue;
    }
    int ans = 0;
    for (int i = 0; i < 60; i++) {
      if ((n >> i) & 1) {
        if (!a[i]) {
          for (int j = i + 1; j < 60; j++)
            if (a[j]) {
              a[j]--;
              int now = j;
              while (now != i) {
                now--;
                a[now]++;
                ans++;
              }
              a[now] += 2;
              break;
            }
        }
        a[i]--;
      }
      a[i + 1] += a[i] / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
