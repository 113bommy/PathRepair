#include <bits/stdc++.h>
template <class T>
T sabs(T x) {
  if (x < 0)
    return x * -1;
  else
    return x;
}
template <class T>
T sgcd(T x, T y) {
  if (y == 0)
    return x;
  else
    return sgcd(y, x % y);
}
template <class T>
T smax(T x, T y) {
  if (x > y)
    return x;
  else
    return y;
}
template <class T>
T smin(T x, T y) {
  if (x > y)
    return y;
  else
    return x;
}
template <class T>
T smod(T a, T b, T m) {
  T res = 1, x = b;
  while (b > 0) {
    if (x & 1) res = ((res % m) * (x % m)) % m;
    x = (x * x) % m;
    b = (b >> 1);
  }
  return res;
}
using namespace std;
inline void writeInt(int x) {
  if (x == -1) {
    putchar('-');
    putchar('1');
    putchar('\n');
  } else {
    int i = 10;
    char buf[11];
    buf[10] = ' ';
    do {
      buf[--i] = x % 10 + '0';
      x /= 10;
    } while (x);
    do {
      putchar(buf[i]);
    } while (buf[i++] != ' ');
  }
}
inline void fastInput(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
struct stu {
  int l, d;
} a[100005];
bool comp(const stu &x, const stu &y) {
  if (x.l == y.l)
    return x.d < y.d;
  else
    return x.l < y.l;
}
multiset<int> s;
multiset<int>::iterator it;
int tot, n, suf[100005], pre[100005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].l;
  for (int i = 0; i < n; i++) cin >> a[i].d, tot += a[i].d;
  sort(a, a + n, comp);
  pre[0] = a[0].d;
  for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i].d;
  suf[n - 1] = a[n - 1].d;
  for (int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] + a[i].d;
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (a[j].l == a[i].l) j++;
    int res = suf[j], cnt = j - i - 1;
    if (i != 0) res += pre[i - 1];
    for (it = s.begin(); it != s.end() && cnt > 0; it++) {
      res -= *it;
      cnt--;
    }
    while (i < j) s.insert(a[i++].d);
    i--;
    ans = min(ans, res);
  }
  printf("%d\n", ans);
  return 0;
}
