#include <bits/stdc++.h>
template <typename T>
void scan(T &x) {
  x = 0;
  bool _ = 0;
  T c = getchar();
  _ = c == 45;
  c = _ ? getchar() : c;
  while (c < 48 || c > 57) c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  x = _ ? -x : x;
}
template <typename T>
void printn(T n) {
  bool _ = 0;
  _ = n < 0;
  n = _ ? -n : n;
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + 48;
    n /= 10;
  } while (n);
  --i;
  if (_) putchar(45);
  while (i >= 0) putchar(snum[i--]);
}
template <typename First, typename... Ints>
void scan(First &arg, Ints &...rest) {
  scan(arg);
  scan(rest...);
}
template <typename T>
void print(T n) {
  printn(n);
  putchar(10);
}
template <typename First, typename... Ints>
void print(First arg, Ints... rest) {
  printn(arg);
  putchar(32);
  print(rest...);
}
using namespace std;
using ll = long long;
constexpr ll inf = 1e15;
int k, n, maxb, t;
vector<int> b;
vector<vector<int>> v;
vector<vector<ll>> dp;
int main() {
  scan(k, n, maxb, t);
  b.resize(n + 1);
  v.resize(maxb + 1);
  dp.resize(n + 1);
  for (auto &i : dp) i.resize(maxb + 1);
  while (k--) {
    for (auto &i : v) i.clear();
    for (auto &i : dp) fill((i).begin(), (i).end(), inf);
    for (ll i = 1; i <= n; i++) {
      scan(b[i]);
      dp[1][b[i]] = min(dp[1][b[i]], i);
      v[b[i]].emplace_back(i);
    }
    for (int j = 1; j <= maxb; j++) dp[1][j] = min(dp[1][j], dp[1][j - 1]);
    int ans = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = i; j <= maxb; j++) {
        ll pre = dp[i - 1][j - 1];
        if (pre == inf or v[j].empty()) continue;
        ll atpre = (pre - 1) % n + 1;
        auto at = upper_bound((v[j]).begin(), (v[j]).end(), atpre);
        if (at == v[j].end()) {
          at = v[j].begin();
          dp[i][j] = pre + n - (atpre - *at);
        } else {
          dp[i][j] = pre + *at - atpre;
        }
      }
      for (int j = i; j <= maxb; j++) {
        if ((dp[i][j] + n - 1) / n <= t) {
          ans = max(ans, i);
        }
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      }
    }
    print(ans);
  }
  return 0;
}
