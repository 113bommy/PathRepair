#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, i;
char c[N];
inline bool ck(int o) {
  int i, j;
  set<int> s;
  for (i = k + 1; i <= n; ++i)
    if (c[i] == o + '0') s.insert(i);
  for (i = k; i <= n; ++i) {
    if (*s.rbegin() - *s.begin() + 1 > k) return 0;
    if (c[i - k + 1] == o + '0') s.insert(i - k + 1);
    if (c[i + 1] == o + '0') s.erase(i + 1);
  }
  return 1;
}
int main() {
  scanf("%d%d%s", &n, &k, c + 1);
  int mn0 = N, mx0 = 0, mn1 = N, mx1 = 0;
  for (i = 1; i <= n; ++i)
    if (c[i] == '0')
      mx0 = i;
    else
      mx1 = i;
  for (i = n; i; --i)
    if (c[i] == '0')
      mn0 = i;
    else
      mn1 = i;
  if (mx0 - mn0 < k || mx1 - mn1 < k) {
    puts("tokitsukaze");
    return 0;
  }
  if (ck(0) && ck(1)) {
    puts("quailty");
    return 0;
  }
  puts("once again");
  return 0;
}
