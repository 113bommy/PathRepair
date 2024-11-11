#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long v[maxn], t[maxn], sumt[maxn], f[maxn], ans[maxn];
int n;
int lobit(int x) { return (x & -x); }
void add(long long x, long long val) {
  while (x <= n) {
    f[x] += val;
    x += lobit(x);
  }
}
long long query(long long x) {
  long long sum = 0;
  while (x) {
    sum += f[x];
    x -= lobit(x);
  }
  return sum;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    sumt[i] = sumt[i - 1] + t[i];
  }
  for (int i = 1; i <= n; i++) {
    long long tt =
        lower_bound(sumt + i, sumt + n + 1, v[i] + sumt[i - 1]) - sumt;
    if (tt == n + 1) {
      add(i, 1);
      add(n + 1, -1);
    } else {
      add(i, 1);
      if (v[i] == t[i])
        add(tt + 1, -1);
      else {
        add(tt, -1);
        ans[tt] += v[i] - (sumt[tt - 1] - sumt[i - 1]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] + t[i] * query(i) << " ";
  }
  return 0;
}
