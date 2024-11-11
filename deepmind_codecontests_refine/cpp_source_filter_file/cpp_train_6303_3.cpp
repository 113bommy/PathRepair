#include <bits/stdc++.h>
using namespace std;
unsigned long long int p2[66];
map<unsigned long long int, unsigned long long int> nodeweight;
bool smlvl(unsigned long long int a, unsigned long long int b) {
  return (upper_bound(p2, p2 + 66, a) == upper_bound(p2, p2 + 66, b)) ? 1 : 0;
}
int main() {
  p2[0] = 1;
  p2[1] = 2;
  for (long long int i = 2; i <= 65; i++) p2[i] = p2[i - 1] * i;
  unsigned long long int q, c, u, v, w, r;
  cin >> q;
  while (q--) {
    scanf("%lld", &c);
    if (c == 1) {
      scanf("%lld %lld %lld", &u, &v, &w);
      if (u < v) swap(u, v);
      while (smlvl(u, v) == 0) {
        if (nodeweight.find(u) != nodeweight.end())
          nodeweight[u] += w;
        else
          nodeweight[u] = w;
        u >>= 1;
      }
      while (u != v) {
        if (nodeweight.find(u) != nodeweight.end())
          nodeweight[u] += w;
        else
          nodeweight[u] = w;
        if (nodeweight.find(v) != nodeweight.end())
          nodeweight[v] += w;
        else
          nodeweight[v] = w;
        u >>= 1;
        v >>= 1;
      }
    } else {
      scanf("%lld %lld", &u, &v);
      r = 0;
      if (u < v) swap(u, v);
      while (smlvl(u, v) == 0) {
        if (nodeweight.find(u) != nodeweight.end()) r += nodeweight[u];
        u >>= 1;
      }
      while (u != v) {
        if (nodeweight.find(u) != nodeweight.end()) r += nodeweight[u];
        if (nodeweight.find(v) != nodeweight.end()) r += nodeweight[v];
        u >>= 1;
        v >>= 1;
      }
      printf("%lld\n", r);
    }
  }
  return 0;
}
