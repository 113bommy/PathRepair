#include <bits/stdc++.h>
using namespace std;
struct data {
  long long a, b, h;
} a[100003];
int n;
bool cmp(data x, data y) { return x.b == y.b ? x.a < y.a : x.b > y.b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].a >> a[i].b >> a[i].h;
  sort(a + 1, a + n + 1, cmp);
  stack<data> s;
  long long r = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    while (s.size() && a[i].b <= s.top().a) {
      r -= s.top().h;
      s.pop();
    }
    s.push(a[i]);
    r += a[i].h;
    res = max(res, r);
  }
  cout << res;
  return 0;
}
