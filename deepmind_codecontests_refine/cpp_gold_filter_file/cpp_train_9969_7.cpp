#include <bits/stdc++.h>
const long long inf = 1e9;
const long long mod = 1e9 + 7;
const long long zero = 0;
const long long maxn = 1e5 + 5;
using namespace std;
bool v[maxn];
bool ch[maxn];
long long cnt, mx_pos;
bool isval(long long t1, long long t5, long long t10, long long t50,
           long long tmp, bool f) {
  if (!f) return f;
  cnt = t50 + t10 + t5 + t1, mx_pos = t1 + t5 * 5 + t10 * 10 + t50 * 50;
  if (mx_pos < tmp || cnt > tmp) return 0;
  if ((tmp - cnt) > 3 && (mx_pos - tmp) > 999 && f) return f;
  if ((tmp - cnt) > 3 && ch[mx_pos - tmp] && f) return f;
  if ((tmp - cnt) <= t10 && f) return f;
  if ((tmp - cnt) < 4) return 0;
  return 0;
}
long long n, ans, tmp, mx, mn;
int main() {
  cin >> n;
  if (n < 501) {
    for (int t1 = 0; t1 <= n; t1++) {
      for (int t5 = 0; t1 + t5 <= n; t5++) {
        for (int t10 = 0; t1 + t5 + t10 <= n; t10++) {
          int t50 = n - t1 - t5 - t10;
          v[t1 + 5 * t5 + 10 * t10 + 50 * t50] = 1;
        }
      }
    }
    ans = 0;
    for (int i = 1; i < maxn; i++) ans += v[i];
    cout << ans << endl;
  } else {
    tmp = 200;
    for (int t5 = 0; t5 <= tmp; t5++) {
      for (int t10 = 0; t10 <= tmp; t10++) {
        for (int t50 = 0; t50 <= tmp; t50++) {
          ch[4 * t5 + 9 * t10 + 49 * t50] = 1;
        }
      }
    }
    ans = 0;
    for (int t1 = 0; t1 < 5; t1++) {
      for (int t5 = 0; t5 < 2; t5++) {
        for (int t10 = 0; t10 < 5; t10++) {
          long long mx = n - t1 - t5 - t10;
          long long mn = max(0LL, (n - 10 * t10 - 5 * t5 - t1) / 50 - 1);
          if (mx - mn + 1 < 81)
            for (int i = mn; i <= mx; i++) ans += isval(t1, t5, t10, i, n, 1);
          else {
            ans += max(0LL, mx - mn + 1);
            for (int i = mn; i < mn + 36; i++)
              if (!isval(t1, t5, t10, i, n, 1)) ans--;
            for (int i = max(0LL, mx - 35); i <= mx; i++) {
              if (!isval(t1, t5, t10, i, n, 1)) {
                ans--;
              }
            }
          }
        }
      }
    }
    cout << ans << endl;
    return 0;
  }
}
