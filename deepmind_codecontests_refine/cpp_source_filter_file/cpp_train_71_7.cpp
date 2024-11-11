#include <bits/stdc++.h>
using namespace std;
long long ast[1000009];
long long pos[1000009];
long long val[1000009];
long long power(long long a, long long b) {
  long long r = 1;
  while (b != 0) {
    if (b % 2 != 0) {
      r = r * a;
      r %= 1000000007;
    }
    a = a * a;
    a = a % 1000000007;
    b = b / 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long n, m, k, cr = 0, mm = 1;
    cin >> n >> m >> k;
    long long ast[m + 1], pos[n + 1];
    pos[0] = 0;
    for (int i = 1; i <= m; i++) {
      cin >> ast[i];
      pos[ast[i]] = -1;
    }
    long long val[k + 1];
    for (int j = 1; j <= k; j++) {
      cin >> val[j];
    }
    if (pos[0] == -1) {
      cout << -1 << endl;
      return 0;
    }
    for (int i = 1; i < n; i++) {
      if (pos[i] == -1) {
        mm = max(mm, i - cr);
        pos[i] = cr;
      } else {
        cr = i;
        pos[i] = i;
      }
    }
    long long ans = 1e18, v = 0;
    if ((mm + 1) > k) {
      cout << -1 << endl;
      return 0;
    }
    for (int i = (mm + 1); i <= k; i++) {
      long long j = 0;
      v = 0;
      while (j < n) {
        if (pos[j] == j) {
          v += val[i];
          j = j + i;
        } else {
          v += val[i];
          j = pos[j];
          j = j + i;
        }
      }
      ans = min(ans, v);
    }
    cout << ans << endl;
  }
}
