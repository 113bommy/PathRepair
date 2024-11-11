#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int mod = 1e9 + 7;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int a[N];
vector<int> cow[N];
int l[N], r[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    cow[x].push_back(y);
  }
  int ans = 0, num = 1;
  for (int t = 0; t <= n; t++) {
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= t; i++) l[a[i]]++;
    for (int i = t + 1; i <= n; i++) r[a[i]]++;
    if (t != 0) {
      int ok = 0;
      for (auto &x : cow[a[t]]) {
        if (x == l[a[t]]) {
          ok = 1;
          break;
        }
      }
      if (!ok) continue;
    }
    int tmp = (t == 0) ? 0 : 1, sum = 1;
    for (int i = 1; i <= n; i++) {
      int x = 0, y = 0;
      for (auto &p : cow[i]) {
        if (p <= l[i]) x++;
        if (p <= r[i]) y++;
      }
      if (i == a[t]) x = 0, y -= (r[i] >= l[i]);
      if (x > y) swap(x, y);
      if (!y)
        continue;
      else if (!x)
        tmp++, sum = mul(sum, y);
      else if (y == 1)
        tmp++, sum = mul(sum, 2);
      else
        tmp += 2, sum = mul(sum, mul(x, y - 1));
    }
    if (tmp > ans)
      ans = tmp, num = sum;
    else if (tmp == ans)
      num = add(num, sum);
  }
  cout << ans << ' ' << num << endl;
  return 0;
}
