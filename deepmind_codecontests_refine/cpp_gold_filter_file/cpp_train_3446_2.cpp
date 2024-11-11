#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, id;
  long long ans;
  int operator<(const node &o) const {
    return b < o.b || b == o.b && a < o.a || b == o.b && a == o.a && id < o.id;
  }
};
const int bd = 550;
long long sum[601010], ans[601010];
long long a[601010];
node c[601010];
int n, k;
void make(int x) {
  c[x].ans = 0LL;
  for (int i = c[x].a; i <= n; i += c[x].b) c[x].ans += a[i];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> c[i].a >> c[i].b, c[i].id = i;
  sort(c + 1, c + 1 + k);
  for (int t = 1; t <= k; t++)
    if (t == 1 || c[t].b != c[t - 1].b) {
      int lo = t, hi = k;
      for (int i = t; i <= k; i++)
        if (c[i].b != c[t].b) {
          hi = i - 1;
          break;
        }
      if (c[lo].b > bd)
        for (int i = lo; i <= hi; i++) make(i);
      else {
        for (int i = n; i; i--) {
          sum[i] = a[i];
          if (i + c[lo].b <= n) sum[i] += sum[i + c[lo].b];
        }
        for (int i = lo; i <= hi; i++) c[i].ans = sum[c[i].a];
      }
    }
  for (int i = 1; i <= k; i++) ans[c[i].id] = c[i].ans;
  for (int i = 1; i <= k; i++) cout << ans[i] << endl;
  return 0;
}
