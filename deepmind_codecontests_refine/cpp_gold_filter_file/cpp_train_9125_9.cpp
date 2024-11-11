#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int N = 200005;
const long long oo = 6e18;
int v[N];
long long ft[N];
void add(int x, long long val) {
  for (; x < N; x += x & -x) ft[x] += val;
}
long long sum(long long x) {
  long long ans = 0;
  for (; x; x -= x & -x) ans += ft[x];
  return ans;
}
set<int> s[33];
int lg(int x) { return !x ? 0 : 32 - __builtin_clz(x); }
void ins(int id) { s[lg(v[id])].insert(id); }
void rem(int id) { s[lg(v[id])].erase(id); }
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
    add(i, v[i]);
    ins(i);
  }
  int a, b;
  while (q--) {
    scanf("%d %d", &a, &b);
    add(a, b - v[a]);
    rem(a);
    v[a] = b;
    ins(a);
    int ans = -1;
    for (int i = 0; i < 33 && ans == -1; i++) {
      int j = 0;
      for (int x : s[i]) {
        if (j++ == 2) break;
        if (v[x] == sum(x - 1)) ans = x;
      }
    }
    printf("%d\n", ans);
  }
}
