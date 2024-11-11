#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
inline void getint(int &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
inline void print(int first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int a[200200];
long long multi(long long a, long long b) {
  if ((long long)1e18 / a < b) return (long long)1e18;
  return a * b;
}
int main() {
  int n;
  long long k;
  cin >> n >> k;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    smax(mx, a[i]);
  }
  if (mx >= k) return puts("0"), 0;
  long long st = 0, ed = k, mid;
  while (ed - st > 1) {
    mid = st + ed >> 1;
    long long sum = 0, c = 1;
    for (int i = 0; i < n; i++) {
      sum += multi(c, a[i]);
      if (c < (long long)1e18) {
        long double tmp = (long double)c * (mid + i) / (i + 1);
        if (tmp > 1e18)
          c = (long long)1e18;
        else
          c = (long long)tmp;
      }
      if (sum >= k) break;
    }
    if (sum >= k)
      ed = mid;
    else
      st = mid;
  }
  cout << ed << endl;
  return 0;
}
