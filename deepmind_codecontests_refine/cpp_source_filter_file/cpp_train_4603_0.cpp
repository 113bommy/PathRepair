#include <bits/stdc++.h>
using namespace std;
const int base = 20;
unordered_map<long long, int> mp;
const int N = 2e5 + 5;
int a[N];
long long b[N];
int n, q;
long long ans;
void change(int id, bool inc) {
  if (inc) {
    if (b[id] < a[id]) --ans;
    ++b[id];
  } else {
    if (b[id] <= a[id]) ++ans;
    --b[id];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ans += a[i];
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int s, t, u;
    scanf("%d%d%d", &s, &t, &u);
    long long index = (s << 20) | t;
    if (mp.count(index)) {
      change(mp[index], false);
    }
    change(mp[index] = u, true);
    printf("%lld\n", ans);
  }
  return 0;
}
