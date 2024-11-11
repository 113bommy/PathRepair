#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
long long n, k, l;
long long calc(long long i) {
  if (i == 0) return k * (k + 1) / 2;
  long long bas = i / k * l, p = bas + calc(i / k);
  long long le = bas + i % k * k + 1, ri = le + k - 1;
  if (le == p)
    le++, ri++;
  else if (le <= p && p <= ri)
    ri++;
  long long s = (le + ri) * (ri - le + 1) / 2;
  if (le <= p && p <= ri) s -= p;
  return s - i * l;
}
void rmain() {
  read(n), read(k), l = k * k + 1;
  long long i = (n - 1) / l, p = calc(i);
  if ((n - 1) % l + 1 == p)
    printf("%lld\n", (i + 1) * (k + 1));
  else {
    long long ans = i * (l - 1) + i * k, t = n - i * l;
    if (p < t) t--;
    ans += t + (t - 1) / k;
    printf("%lld\n", ans);
  }
}
int main() {
  int T;
  read(T);
  while (T--) rmain();
  return 0;
}
