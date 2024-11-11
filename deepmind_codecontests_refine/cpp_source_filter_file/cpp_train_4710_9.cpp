#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
pair<long long, long long> F(long long p) {
  long long cnt = 0;
  for (long long i = 0;; i += 2) {
    cnt += (1ll << i);
    if (cnt >= p) {
      return make_pair(i, (1ll << i) + p - (cnt - (1ll << i) + 1));
    }
  }
}
long long T(long long p) {
  long long cnt = 0;
  for (long long i = 0;; i += 2) {
    cnt += (1ll << i);
    if (cnt >= p) {
      return p - (cnt - (1ll << i));
    }
  }
}
long long Get1(long long p) {
  pair<long long, long long> G = F(p);
  return G.second;
}
long long Solve(long long x, long long y) {
  if (!x) return 2;
  long long len = 1 << (x - 2);
  if (y <= len)
    return Solve(x - 2, y) + (1ll << (x + 1)) - (1ll << (x - 1));
  else if (y <= 2 * len)
    return Solve(x - 2, y - len) + (1ll << (x + 1)) - (1ll << (x - 1)) +
           (1ll << (x - 1));
  else if (y <= 3 * len)
    return Solve(x - 2, y - 2 * len) + (1ll << (x + 1)) - (1ll << (x - 1)) +
           (1ll << (x - 2)) * 3;
  else if (y <= 4 * len)
    return Solve(x - 2, y - 3 * len) + (1ll << (x + 1)) - (1ll << (x - 1)) +
           (1ll << (x - 2));
  return 0;
}
long long Get2(long long p) {
  pair<long long, long long> G = F(p);
  return Solve(G.first, T(p));
}
signed main() {
  long long cas = read();
  while (cas--) {
    long long x = read();
    if (x % 3 == 1) {
      printf("%lld\n", Get1((x + 2) / 3));
      continue;
    } else if (x % 3 == 2) {
      printf("%lld\n", Get2((x + 1) / 3));
    } else {
      printf("%lld\n", Get1(x / 3) ^ Get2(x / 3));
    }
  }
}
