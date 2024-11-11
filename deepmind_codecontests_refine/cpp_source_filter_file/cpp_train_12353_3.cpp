#include <bits/stdc++.h>
using namespace std;
int aib[200005];
void update(int n, int poz, int val) {
  for (; poz <= n; poz += (poz & -poz)) aib[poz] += val;
}
int query(int poz) {
  int ans = 0;
  for (; poz > 0; poz -= (poz & -poz)) ans += aib[poz];
  return ans;
}
int a[200005];
struct Query {
  int a, x;
} q[200005];
bool cmp(Query a, Query b) { return a.x < b.x; }
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    x = min(x, n);
    a[i] = x;
    q[i] = {i, x};
    if (a[i] >= i) ans--;
  }
  sort(q + 1, q + n + 1, cmp);
  int poz = 1;
  for (int i = 1; i <= n; ++i) {
    update(n, a[i], 1);
    while (poz <= n && q[poz].x == i) {
      ans += (query(n) - query(q[i].a - 1));
      poz++;
    }
  }
  cout << ans / 2;
  return 0;
}
