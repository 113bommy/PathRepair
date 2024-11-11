#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const int maxn = 100 + 10;
int n;
int d[maxn * 2];
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
    for (int i = n; i < n + n; ++i) d[i] = d[i - n];
    int s, t;
    scanf("%d%d", &s, &t);
    if (s > t) swap(s, t);
    --s, --t;
    int t1 = 0, t2 = 0;
    for (int i = s; i < t; ++i) t1 += d[i];
    for (int i = t; i < s + n; ++i) t2 += d[i];
    int ans = min(t1, t2);
    printf("%d\n", ans);
  }
  return 0;
}
