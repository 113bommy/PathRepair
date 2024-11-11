#include <bits/stdc++.h>
using namespace std;
int num_q;
int flag;
long long u, v, w;
map<long long, long long> hs;
int main() {
  scanf("%d", &num_q);
  while (num_q--) {
    scanf("%d%I64d%I64d", &flag, &u, &v);
    if (flag == 1) {
      scanf("%I64d", &w);
      while (u != v) {
        if (u > v) {
          hs[u] += w;
          u /= 2;
        } else {
          hs[v] += w;
          v /= 2;
        }
      }
    } else {
      long long ans = 0;
      while (u != v) {
        if (u > v) {
          ans += hs[u];
          u /= 2;
        } else {
          ans += hs[v];
          v /= 2;
        }
      }
      printf("%I64d\n", ans);
    }
  }
}
