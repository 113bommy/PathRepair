#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int n;
int a[N];
struct Queue {
  long long cnt;
  long long num;
} d[N];
int tot;
long long num[2 * N];
long long sum[N * 20], sumcnt[N * 20];
int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
struct data {
  long long f, g, h;
} temp;
data calc(long long a, long long b, long long c, long long n) {
  data tmp;
  if (a == 0) {
    tmp.f = tmp.g = tmp.h = 0;
    return tmp;
  }
  if (a >= c || b >= c) {
    tmp = calc(a % c, b % c, c, n);
    tmp.h = tmp.h + n * (n + 1) * (2 * n + 1) / 6 * (a / c) * (a / c) +
            (n + 1) * (b / c) * (b / c) + 2 * (a / c) * tmp.g +
            2 * (b / c) * tmp.f + n * (n + 1) * (a / c) * (b / c);
    tmp.f = tmp.f + n * (n + 1) / 2 * (a / c) + (n + 1) * (b / c);
    tmp.g = tmp.g + n * (n + 1) * (2 * n + 1) / 6 * (a / c) +
            n * (n + 1) / 2 * (b / c);
    return tmp;
  }
  long long m = (a * n + b) / c;
  data nxt = calc(c, c - b - 1, a, m - 1);
  tmp.f = n * m - nxt.f;
  tmp.g = (n * (n + 1) * m - nxt.f - nxt.h) / 2;
  tmp.h = m * (m + 1) * n - 2 * (nxt.g + nxt.f) - tmp.f;
  return tmp;
}
long long Up(long long a, long long b) { return (a + b - 1) / b; }
long long Js(long long a, long long b, long long c, long long limx,
             long long limy) {
  if (b < 0) {
    long long d = (-b + a - 1) / a;
    b += d * a;
    limx -= d;
  }
  if (limx < 0) return 0;
  long long maxx = (c * limy - b) / a;
  data temp1 = calc(a, b, c, min(maxx, limx));
  if (limx < maxx)
    return temp1.f;
  else
    return temp1.f + limy * (limx - maxx);
}
long long check(long long p) {
  int j = 1;
  long long ans = 0;
  for (int i = 1; i <= tot; i++) {
    if (d[i].num > p) break;
    if (j < i) j = i;
    while (sum[j] - sum[i - 1] < p && j <= tot) j++;
    if (i != j)
      ans += 1ll * d[i].cnt * (sumcnt[j - 1] - sumcnt[i]) +
             d[i].cnt * (d[i].cnt + 1) / 2;
    if (j > tot) {
      ans += (sumcnt[j - 1] - sumcnt[i] + 1) * (sumcnt[j - 1] - sumcnt[i]) / 2;
      break;
    }
    for (int k = j; k <= tot; k++) {
      if (i == k) {
        int tmp = p / d[i].num;
        ans += 1ll * (d[i].cnt + (d[i].cnt + 1 - tmp)) * tmp / 2;
        continue;
      }
      if (sum[k - 1] - sum[i] + d[k].num + d[i].num > p) break;
      ans +=
          Js(d[k].num, p - (sum[k] - sum[i]), d[i].num, d[k].cnt - 1, d[i].cnt);
    }
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i >= 1; i--) {
    int k = 1;
    for (int j = 1; j <= tot; j++) {
      int r = gcd(d[j].num, a[i]);
      if (d[k - 1].num == r)
        d[k - 1].cnt += d[j].cnt;
      else {
        d[k].cnt = d[j].cnt;
        d[k].num = r;
        k++;
      }
    }
    if (d[k - 1].num == a[i])
      d[k - 1].cnt++;
    else {
      d[k].num = a[i];
      d[k].cnt = 1;
      k++;
    }
    tot = k - 1;
    for (int j = 1; j <= tot; j++) num[d[j].num] += d[j].cnt;
  }
  memset(d, 0, sizeof(d));
  tot = 0;
  for (int i = 1; i < 2 * N; i++)
    if (num[i]) {
      tot++;
      d[tot].num = i;
      d[tot].cnt = num[i];
    }
  for (int i = 1; i <= tot; i++) {
    sum[i] = sum[i - 1] + d[i].num * d[i].cnt;
    sumcnt[i] = sumcnt[i - 1] + d[i].cnt;
  }
  long long l, r;
  l = 1;
  r = 1e18;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid) >=
        ((1ll * n * (n + 1) / 2 + 1) * (1ll * n * (n + 1) / 2) / 2 + 1) / 2)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
}
