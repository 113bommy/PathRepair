#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int Q;
bool check(int x, long long t) {
  long long now = 9;
  for (int i = 1; i <= x; i++) {
    t -= now * i;
    now *= 10;
    if (t <= 0) return false;
  }
  return t > 0;
}
int getKth(long long k) {
  int l = 0, r = 19;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid, k))
      l = mid;
    else
      r = mid - 1;
  }
  long long S = 0, now = 9;
  for (int i = 1; i <= l; i++) {
    S += now * i;
    now *= 10;
  }
  now /= 9;
  now += (k - S - 1) / (l + 1);
  int c = l + 1 - (k - S - 1) % (l + 1);
  for (int i = 1; i < c; i++) now /= 10;
  return now % 10;
}
long long getLen(long long x) {
  int l = 0;
  for (long long t = x; t; t /= 10) l++;
  long long ret = 0, now = 9;
  for (int i = 1; i < l; i++) {
    ret += now * i;
    now *= 10;
    if (ret > inf) {
      ret = inf;
      break;
    }
  }
  now /= 9;
  ret += (x - l + 1) * l;
  return min(inf, ret);
}
long long sum[20];
long long k;
bool judge(long long x) {
  int l = 0;
  for (long long t = x; t; t /= 10) l++;
  long long s = k;
  for (int i = 1; i < l; i++) {
    s -= sum[i];
    if (s <= 0) return false;
  }
  long long t = 1;
  for (int i = 1; i < l; i++) t *= 10;
  long long n = x - t + 1, a1 = getLen(t), d = l;
  if (n >= s / a1 || a1 >= s / n) return false;
  s -= n * a1;
  if (s <= 0) return false;
  s -= n * (n - 1) / 2 * d;
  return s > 0;
}
long long getSum(long long x) {
  int l = 0;
  for (long long t = x; t; t /= 10) l++;
  long long s = 0;
  for (int i = 1; i < l; i++) {
    s += sum[i];
  }
  long long t = 1;
  for (int i = 1; i < l; i++) t *= 10;
  long long n = x - t + 1, a1 = getLen(t), d = l;
  s += n * a1;
  s += n * (n - 1) / 2 * d;
  return s;
}
void init() {
  long long now = 1;
  for (int l = 1; l <= 18; l++) {
    long long n = now * 9, a1 = getLen(now), d = l;
    sum[l] = n * a1 + n * (n - 1) / 2 * d;
    if (sum[l] > inf || sum[l] < 0) sum[l] = inf;
    now *= 10;
  }
}
int main() {
  init();
  scanf("%d", &Q);
  while (Q--) {
    scanf("%lld", &k);
    long long l = 0, r = (long long)1e9;
    while (l < r) {
      long long mid = (l + r + 1) / 2;
      if (judge(mid))
        l = mid;
      else
        r = mid - 1;
    }
    long long S = getSum(l);
    printf("%d\n", getKth(k - S));
  }
  return 0;
}
