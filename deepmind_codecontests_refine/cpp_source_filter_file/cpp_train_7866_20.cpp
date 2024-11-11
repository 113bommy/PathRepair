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
template <typename T>
inline void getint(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <typename T>
inline void print(T first) {
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
int a[100100];
map<int, int> mp;
int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    mp[a[i]] = 1;
  }
  if (n == 1 || n == m) {
    printf("%d 1\n", a[0]);
    return 0;
  }
  int ok = 0;
  if (n * 2 > m) {
    ok = 1;
    n = 0;
    for (int i = 0; i < m; i++) {
      if (!mp.count(i)) a[n++] = i;
    }
    mp.clear();
    for (int i = 0; i < n; i++) mp[a[i]] = 1;
  }
  if (n == 1) {
    printf("%d 1\n", (a[0] + m) % m);
    return 0;
  }
  int d = (a[0] - a[1] + m) % m;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (!mp.count((a[i] + d) % m)) k++;
  }
  d = 1LL * d * power(k, m - 2, m) % m;
  k = 0;
  long long s;
  for (int i = 0; i < n; i++) {
    if (!mp.count((m + a[i] - d) % m)) k++, s = a[i];
  }
  if (k == 1)
    printf("%I64d %d\n", (ok ? (s + 1LL * d * n) % m : s), d);
  else
    puts("-1");
  return 0;
}
