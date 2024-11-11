#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T alex(T x) {
  return (x > 0) ? x : -x;
}
template <class T>
void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while ((ch < 48 || ch > 57) && ch != 45) ch = getchar();
  if (ch == 45) f = -1, ch = getchar();
  while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
int sum0[1000005], sum2[1000005], sum4[1000005], sum6[1000005];
long long n;
int power(int a, int b, int p) {
  int s = 1, w = a;
  while (b) {
    if (b & 1) s = (long long)s * w % p;
    w = (long long)w * w % p;
    b >>= 1;
  }
  return s;
}
int f(long long n) {
  int a = n, b = n + 1, c = n + 2;
  if (a % 2 == 0)
    a /= 2;
  else if (b % 2 == 0)
    b /= 2;
  if (a % 3 == 0)
    a /= 3;
  else if (b % 3 == 0)
    b /= 3;
  else if (c % 3 == 0)
    c /= 3;
  a %= 1000000007;
  b %= 1000000007;
  c %= 1000000007;
  return (long long)a * b % 1000000007 * c % 1000000007;
}
int cnt_all_point(int sqn) {
  int res = 0;
  for (int i = (0); i <= (sqn); i++) {
    (res += (int)sqrt(n - (long long)i * i)) %= 1000000007;
  }
  return res;
}
int ans;
int work1(int sqn) {
  int res = 0;
  for (int i = (0); i <= (sqn); i++) {
    int cnt = (int)sqrt(n - (long long)i * i);
    res = (res + (long long)i * i % 1000000007 * cnt % 1000000007) % 1000000007;
    res = (res + sum2[cnt]) % 1000000007;
  }
  return res;
}
int work2(int sqn) {
  int res = 0;
  for (int i = (0); i <= (sqn); i++) {
    int cnt = (int)sqrt(n - (long long)i * i);
    res = (res + (long long)i * i % 1000000007 * i % 1000000007 * i %
                     1000000007 * cnt % 1000000007) %
          1000000007;
    res = (res + (long long)2 * i * i % 1000000007 * sum2[cnt] % 1000000007) %
          1000000007;
    res = (res + sum4[cnt]) % 1000000007;
  }
  return res;
}
int work3(int sqn) {
  int res = 0;
  for (int i = (0); i <= (sqn); i++) {
    int cnt = (int)sqrt(n - (long long)i * i);
    res =
        (res + (long long)i * i % 1000000007 * i % 1000000007 * i % 1000000007 *
                   i % 1000000007 * i % 1000000007 * cnt % 1000000007) %
        1000000007;
    res = (res + (long long)3 * i * i % 1000000007 * i % 1000000007 * i %
                     1000000007 * sum2[cnt] % 1000000007) %
          1000000007;
    res = (res + (long long)3 * i * i % 1000000007 * sum4[cnt] % 1000000007) %
          1000000007;
    res = (res + sum6[cnt]) % 1000000007;
  }
  return res;
}
int main() {
  scanf("%lld", &n);
  int sqn = (int)sqrt(n);
  sum0[0] = sum2[0] = sum4[0] = sum6[0] = 0;
  for (int i = (1); i < (1000005); i++) {
    sum0[i] = (sum0[i - 1] + power(i, 0, 1000000007)) % 1000000007;
    sum2[i] = (sum2[i - 1] + power(i, 2, 1000000007)) % 1000000007;
    sum4[i] = (sum4[i - 1] + power(i, 4, 1000000007)) % 1000000007;
    sum6[i] = (sum6[i - 1] + power(i, 6, 1000000007)) % 1000000007;
  }
  int all_point = cnt_all_point(sqn);
  ans = (ans - 2 * work3(sqn) % 1000000007 + 1000000007) % 1000000007;
  ans = (ans + (n * 3 % 1000000007 + 6) * work2(sqn) % 1000000007) % 1000000007;
  ans = (ans - (n * 3 % 1000000007 + 4) * work1(sqn) % 1000000007) % 1000000007;
  ans = (long long)ans * power(6, 1000000007 - 2, 1000000007) % 1000000007;
  ans = ((long long)all_point * f(n) % 1000000007 - ans + 1000000007) %
        1000000007;
  ans = (long long)ans * 4 % 1000000007;
  ans = (ans + f(n)) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
