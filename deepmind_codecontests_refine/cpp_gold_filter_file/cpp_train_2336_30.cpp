#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 1e2 + 1;
struct frd {
  int k;
  int x;
  int m;
};
frd q[N];
long long dp[1 << 20];
long long tmp[1 << 20];
bool compare(const frd& lhs, const frd& rhs) { return lhs.k > rhs.k; }
int main() {
  for (int j = 0; j < 1 << 20; j++)
    dp[j] = (long long)2e18, tmp[j] = (long long)2e18;
  int n, m, b;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &b);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &q[i].x);
    scanf("%d", &q[i].k);
    int w;
    scanf("%d", &w);
    int mask = 0;
    for (int i = 0; i < w; i++) {
      int a;
      scanf("%d", &a);
      a--;
      mask = mask | (1 << a);
    }
    q[i].m = mask;
  }
  sort(q + 1, q + n + 1, compare);
  dp[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    int mask = q[i].m;
    for (int j = 0; j < 1 << m; j++) {
      tmp[j] = dp[j];
    }
    tmp[mask] = min(tmp[mask], (long long)q[i].x + q[i].k * 1ll * b);
    for (int j = 1; j < 1 << m; j++) {
      if (__builtin_popcount(mask | j) > m) break;
      tmp[mask | j] = min(tmp[mask | j], tmp[j] + q[i].x);
    }
    for (int j = 0; j < 1 << m; j++) dp[j] = tmp[j];
  }
  if (dp[(1 << m) - 1] == (long long)2e18) {
    printf("%d\n", -1);
  } else {
    printf("%lld\n", dp[(1 << m) - 1]);
  }
  return 0;
}
