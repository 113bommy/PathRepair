#include <bits/stdc++.h>
using namespace std;
int a[9], b[9], s, s3, s4, i, j, k, n, ans;
long long fang(long long a, long long b, long long mo) {
  long long ans = 1;
  for (; b; b >>= 1) b& 1 ? ans = ans * a % mo : 0, a = a * a % mo;
  return ans;
}
template <class T>
void up(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
void down(T& a, T b) {
  if (a > b) a = b;
}
bool check(int x) {
  int i = 3 * x;
  if (i > s) return 0;
  if (s - i > i) return 0;
  a[1] = b[1], a[2] = b[2], a[3] = b[3], a[4] = b[4];
  return 1;
}
int work(int x) {
  s4 = s - x * 3;
  s3 = x - s4;
  int k = 0;
  if (s4 > a[4]) {
    if (s4 - a[4] <= a[3])
      if (s4 - a[4] <= a[1] + a[2] * 2)
        a[3] -= s3 - a[4], k += s4 - a[4];
      else {
        return s4 - a[4];
      }
    else {
      if (a[1] >= a[3])
        a[1] -= a[3];
      else if ((a[3] - a[1]) & 1)
        a[2] -= (a[3] - a[1] - 1) >> 1, a[1] = 1;
      else
        a[2] -= (a[3] - a[1]) >> 1, a[1] = 0;
      a[4] += a[3], k += a[3], a[3] = 0;
      if (s4 - a[4] <= a[2]) {
        k += (s4 - a[4]) * 2;
        if (a[1] > (s4 - a[4]) * 2) {
          a[1] -= (s4 - a[4]) * 2;
          a[2] -= s4 - a[4];
          a[4] = s4;
        } else
          a[2] -= s4 - a[4] - (a[4] - a[4] - a[1] >> 1), a[1] &= 1;
      } else {
        k += a[2] * 2;
        a[1] -= a[2] * 2;
        a[4] += a[2];
        a[2] = 0;
        k += (s4 - a[4]) * 3;
        a[1] -= (s4 - a[4]) * 4;
        a[4] = s4;
      }
    }
  } else {
    int i = a[4] - s4;
    a[3] += a[4] - s4;
    k += i;
    if (a[2] >= i)
      a[3] += i, a[2] -= i, i = 0;
    else
      a[3] += a[2], i -= a[2], a[2] = 0;
    if (i & 1)
      a[3] += i >> 1, a[1] -= i >> 1, a[1]--, a[2]++;
    else
      a[3] += i >> 1, a[1] -= i >> 1;
  }
  if (a[3] != s3) {
    if (s3 - a[3] <= a[2])
      return k + s3 - a[3];
    else
      return k + a[2] + (s3 - a[3] - a[2]) * 2;
  }
  return k;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &j), a[j]++, s += j;
  ans = s + 1;
  b[1] = a[1], b[2] = a[2], b[3] = a[3], b[4] = a[4];
  for (k = n; k * 4 >= s; k--)
    if (check(k)) down(ans, work(k));
  if (ans > s)
    puts("-1");
  else
    printf("%d", ans);
  return 0;
}
