#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n;
int a[N + 5], pos[N + 5];
int fcnt[N + 5];
long long fsum[N + 5];
void update(int x, int gt) {
  for (; x <= n; x += x & -x) fcnt[x]++, fsum[x] += gt;
}
int Count(int x) {
  int ans = 0;
  for (; x >= 1; x -= x & -x) ans += fcnt[x];
  return ans;
}
long long Sum(int x) {
  long long ans = 0;
  for (; x >= 1; x -= x & -x) ans += fsum[x];
  return ans;
}
long long val(int x) { return 1ll * x * (x + 1) / 2; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
  int Cntinv = 0;
  long long sumpos = 0;
  for (int i = 1; i <= n; i++) {
    Cntinv += i - 1 - Count(pos[i] - 1);
    sumpos += pos[i];
    update(pos[i], pos[i]);
    int l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Count(mid) > i / 2)
        r = mid - 1;
      else
        l = mid + 1;
    }
    int x = l;
    int u = i / 2, v = i - u - 1;
    long long sumright = sumpos - Sum(x), sumleft = Sum(x - 1);
    long long ans = sumright - sumleft;
    ans += 1ll * x * (u - v);
    ans += Cntinv - val(u) - val(v);
    cout << ans << ' ';
  }
}
