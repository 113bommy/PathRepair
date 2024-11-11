#include <bits/stdc++.h>
using namespace std;
long long num[6][200005];
int cnt[6], a[200005];
long long out[200005], five[200005], mn[200005];
long long ans = 0;
int n, b, c, k;
void solve1() {
  sort(a + 1, a + n + 1);
  ans = 1LL << 60;
  long long *v = out;
  for (int i = 1; i <= n; i++) v[i] = a[i] + v[i - 1];
  for (int i = k; i <= n; i++)
    ans = min(ans, (long long)a[i] * n - (v[i] - v[i - k]));
}
void solve2() {
  sort(a + 1, a + n + 1);
  for (int i = 1, t; i <= n; i++) num[t = a[i] % 5][++cnt[t]] = a[i];
  for (int i = 0; i < 5; i++) sort(num[i] + 1, num[i] + cnt[i] + 1);
  ans = 1LL << 62;
  for (int i = 0; i < 5; i++) num[i][cnt[i] + 1] = 2e9 + 2;
  for (int f = 0; f < 5; f++) {
    int pf[6], pb[6];
    for (int j = 0; j < 5; j++) pf[j] = pb[j] = 0;
    long long x = -1;
    long long val = 0, t, ct = 0;
    x = (a[k] - f - 1) / 5 * 5 + f + 5;
    for (int i = 0; i < 5; i++)
      while (num[i][pf[i] + 1] <= x)
        ct++, pf[i]++, val += (t = x - num[i][pf[i]]) / 5 * b + t % 5 * c;
    ans = min(ans, val);
    for (int v = k + 1; v <= n; v++) {
      t = (a[v] - f - 1) / 5 * 5 + f + 5;
      val += b * (t - x) / 5 * ct;
      x = t;
      for (int i = 0; i < 5; i++)
        while (num[i][pf[i] + 1] <= x)
          ct++, pf[i]++,
              val += (x - num[i][pf[i]]) / 5 * b + (x - num[i][pf[i]]) % 5 * c;
      while (ct > k) {
        int t2 = -1;
        long long v = 0;
        for (int i = 0; i < 5; i++) {
          if (pb[i] < pf[i] &&
              (t = ((t = x - num[i][pb[i] + 1]) / 5 * b + t % 5 * c)) >= v)
            v = t, t2 = i;
        }
        val -= (t = x - num[t2][pb[t2] + 1]) / 5 * b + t % 5 * c;
        pb[t2]++;
        ct--;
      }
      ans = min(ans, val);
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &k, &b, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += 1e9 + 10;
  if (c * 5 <= b) {
    solve1();
  } else {
    solve2();
  }
  cout << ans << endl;
  return 0;
}
