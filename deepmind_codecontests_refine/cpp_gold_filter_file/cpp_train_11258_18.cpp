#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Cin(T& x) {
  char c;
  T sign = 1;
  x = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sign;
}
template <typename T, typename... Args>
inline void Cin(T& a, Args&... args) {
  Cin(a);
  Cin(args...);
}
long long w, cnt[9], used[9], s = 0, t = 0;
mt19937 r(time(0));
void Enter() {
  Cin(w);
  for (int i = 1; i <= 8; ++i) Cin(cnt[i]), s += 1ll * cnt[i] * i;
  if (s <= w) {
    cout << s;
    exit(0);
  }
}
void Solve() {
  s = 0;
  for (int i = 1; i <= 8; ++i) {
    t = (w - s) / i;
    if (t >= cnt[i])
      s += 1ll * cnt[i] * i, used[i] = cnt[i], cnt[i] = 0;
    else
      s += 1ll * t * i, used[i] = t, cnt[i] -= t;
  }
  long long res = s;
  for (int i = 0; i < 10000000; ++i) {
    if (s < w) {
      int x = r() % 8 + 1;
      if (cnt[x]) s += x, --cnt[x], ++used[x];
    } else {
      int x = r() % 8 + 1;
      if (used[x]) ++cnt[x], --used[x], s -= x;
    }
    if (s <= w) res = max(res, s);
    if (s == w) {
      cout << w;
      exit(0);
    }
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Enter();
  Solve();
  return 0;
}
