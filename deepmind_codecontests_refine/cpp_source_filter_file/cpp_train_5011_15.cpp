#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    string st, s = "RGB";
    long long n;
    cin >> n >> st;
    long long cnt = 0;
    for (long long i = 1; i < n - 1; i++) {
      if (st[i - 1] == st[i] && st[i + 1] == st[i]) {
        for (long long j = 0; j < 3; j++) {
          if (st[i - 1] != s[j] && st[i + 1] != s[j]) {
            st[i] = s[j];
            break;
          }
        }
        ++cnt;
      }
    }
    for (long long i = 1; i < n - 1; i++) {
      if (st[i - 1] == st[i] || st[i + 1] == st[i]) {
        for (long long j = 0; j < 3; j++) {
          if (st[i - 1] != s[j] && st[i + 1] != s[j]) {
            st[i] = s[j];
            break;
          }
        }
        ++cnt;
      }
    }
    if (n == 2 && st[0] != st[1]) {
      ++cnt;
      for (long long i = 0; i < 3; i++) {
        if (st[1] != s[i]) {
          st[0] = s[i];
          break;
        }
      }
    }
    cout << cnt << "\n" << st;
  }
  return 0;
}
