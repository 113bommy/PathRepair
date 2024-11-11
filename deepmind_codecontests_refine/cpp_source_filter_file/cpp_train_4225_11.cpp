#include <bits/stdc++.h>
using namespace std;
int n, m, x, a[200005], b[200005];
int cnt1, cnt2, now1, now2, ans;
map<int, int> mp;
int read() {
  int x = 0, ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= n; ++i) {
    a[i] = read();
    if (a[i] & 1)
      cnt1++;
    else
      cnt2++;
    mp[a[i]]++;
  }
  if (n & 1) {
    puts("-1");
    return 0;
  }
  now1 = 1, now2 = 2;
  for (register int i = n; i >= 1; --i) {
    if (mp[a[i]] > 1) {
      if (cnt1 > cnt2) {
        while (mp[now2]) now2 += 2;
        if (now2 > m) {
          puts("-1");
          return 0;
        }
        b[i] = now2;
        mp[now2]++;
        if (a[i] & 1) cnt1--, cnt2++;
      } else if (cnt1 < cnt2) {
        while (mp[now1]) now1 += 2;
        if (now1 > m) {
          puts("-1");
          return 0;
        }
        b[i] = now1;
        mp[now1]++;
        if (!(a[i] & 1)) cnt2--, cnt1++;
      } else {
        if (a[i] & 1) {
          while (mp[now1]) now1 += 2;
          if (now1 > m) {
            puts("-1");
            return 0;
          }
          b[i] = now1;
          mp[now1]++;
        } else {
          while (mp[now2]) now2 += 2;
          if (now2 > m) {
            puts("-1");
            return 0;
          }
          b[i] = now2;
          mp[now2]++;
        }
      }
      mp[a[i]]--;
      ans++;
    } else
      b[i] = a[i];
  }
  if (cnt1 > cnt2) {
    for (register int i = 1; i <= n; ++i) {
      if (a[i] & 1) {
        while (mp[now2]) now2 += 2;
        if (now2 > m) {
          puts("-1");
          return 0;
        }
        b[i] = now2;
        mp[now2]++;
        mp[a[i]]--;
        cnt1--, cnt2++;
        ans++;
        if (cnt1 == cnt2) break;
      }
    }
  } else if (cnt1 < cnt2) {
    for (register int i = 1; i <= n; ++i) {
      if (!(a[i] & 1)) {
        while (mp[now1]) now1 += 2;
        if (now1 > m) {
          puts("-1");
          return 0;
        }
        b[i] = now1;
        mp[now1]++;
        mp[a[i]]--;
        cnt2--, cnt1++;
        ans++;
        if (cnt1 == cnt2) break;
      }
    }
  }
  if (cnt1 != cnt2) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans);
  for (register int i = 1; i < n; ++i) printf("%d ", b[i]);
  printf("%d\n", b[n]);
  return 0;
}
