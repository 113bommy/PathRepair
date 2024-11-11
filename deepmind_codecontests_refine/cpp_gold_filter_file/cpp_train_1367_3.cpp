#include <bits/stdc++.h>
template <typename T>
inline T const &MAX(T const &a, T const &b) {
  return a > b ? a : b;
}
template <typename T>
inline T const &MIN(T const &a, T const &b) {
  return a < b ? a : b;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c, b >>= 1;
  }
  return ans;
}
using namespace std;
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 100000 + 10, maxn = 200000 + 10, inf = 0x3f3f3f3f;
char s[N];
long long l[N];
vector<int> que[2];
int main() {
  int n, id;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &l[i]);
  scanf("%s", s + 1);
  long long ans = 0, x;
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'W')
      que[0].push_back(i), flag = true;
    else if (s[i] == 'G')
      que[1].push_back(i);
    else {
      while (l[i] && que[0].size()) {
        id = que[0].back();
        que[0].pop_back();
        x = min(l[i], l[id]);
        ans += x * 4;
        l[i] -= x;
        l[id] -= x;
        if (l[id]) que[0].push_back(id);
      }
      while (l[i] && que[1].size()) {
        id = que[1].back();
        que[1].pop_back();
        x = min(l[i], l[id]);
        ans += x * 6;
        l[i] -= x;
        l[id] -= x;
        if (l[id]) que[1].push_back(id);
      }
      if (flag)
        ans += l[i] * 4;
      else
        ans += l[i] * 6;
      l[i] = 0;
    }
  }
  que[0].clear();
  for (int i = 1; i <= n; ++i) {
    if (!l[i]) continue;
    if (s[i] == 'W')
      que[0].push_back(i);
    else if (s[i] == 'G') {
      while (l[i] && que[0].size()) {
        id = que[0].back();
        que[0].pop_back();
        x = min(l[i], l[id]);
        ans += x * 4;
        l[i] -= x;
        l[id] -= x;
        if (l[id]) que[0].push_back(id);
      }
      ans += l[i] * 3;
      l[i] = 0;
    }
  }
  for (auto it : que[0]) {
    ans += l[it] * 2;
  }
  printf("%I64d\n", ans);
  return 0;
}
