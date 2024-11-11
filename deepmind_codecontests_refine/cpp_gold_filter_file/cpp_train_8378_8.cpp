#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &_x_) {
  _x_ = 0;
  bool f = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = !f;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    _x_ = _x_ * 10 + ch - '0';
    ch = getchar();
  }
  if (f) _x_ = -_x_;
}
const double eps = 1e-8;
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;
const long long inf = 1e15;
long long L[55], R[55];
long long n, q, x, y, z, v;
map<long long, int> mp;
int main() {
  L[1] = R[1] = 1;
  for (int i = 2; i <= 50; i++) {
    L[i] = L[i - 1] << 1;
    R[i] = R[i - 1] << 1 | 1;
  }
  read(n), read(q);
  if (q == 0) {
    if (n == 1)
      puts("1");
    else
      puts("Data not sufficient!");
    return 0;
  }
  for (long long i = 1; i <= q; i++) {
    read(x), read(y), read(z), read(v);
    while (x < n) {
      y <<= 1;
      z = z << 1 | 1;
      x++;
    }
    if (v) {
      mp[y]++, mp[z + 1]--;
    } else {
      mp[L[n]]++, mp[y]--;
      mp[z + 1]++, mp[R[n] + 1]--;
    }
  }
  int sum = 0;
  long long pre = -1, cnt = 0, ans = 0;
  for (map<long long, int>::iterator i = mp.begin(); i != mp.end(); i++) {
    sum += i->second;
    if (pre != -1) {
      cnt += i->first - pre;
      ans = pre;
    }
    if (sum == q)
      pre = i->first;
    else
      pre = -1;
  }
  if (cnt == 0)
    puts("Game cheated!");
  else if (cnt > 1)
    puts("Data not sufficient!");
  else
    printf("%I64d\n", ans);
  return 0;
}
