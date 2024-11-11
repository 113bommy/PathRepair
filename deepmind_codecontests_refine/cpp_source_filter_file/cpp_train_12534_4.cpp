#include <bits/stdc++.h>
using namespace std;
const int N = 9;
int p[1001000];
int pn;
void make_p() {
  for (int i = 2; i * i < 1001000; i++) {
    if (p[i]) continue;
    for (int j = i + i; j < 1001000; j += i) p[j] = 1;
  }
  pn = 0;
  for (int i = 2; i < 1001000; i++)
    if (!p[i]) p[pn++] = i;
}
int n;
long long a[N];
int ans;
int isp(long long x) {
  for (int i = 0; (long long)p[i] * p[i] <= x; i++) {
    if (x % p[i] == 0) return 0;
  }
  return 1;
}
int cal(long long x) {
  int cnt = 0;
  for (int i = 2; (long long)p[i] * p[i] <= x; i++) {
    while (x % p[i] == 0) {
      cnt++;
      x /= p[i];
    }
  }
  return cnt + (x != 1);
}
int calc(long long a, long long x) { return cal(x); }
int mark[N];
void dfs(int pos, int cost, int all) {
  if (cost >= ans) return;
  if (pos < 0) {
    if (all) {
      for (int i = 0; i < n - 1; i++)
        if (!mark[i]) return;
    }
    ans = cost;
    return;
  }
  if (isp(a[pos])) {
    dfs(pos - 1, cost + 1, all);
    return;
  }
  int up = 1 << pos;
  for (int i = 0; i < up; i++) {
    int ok = 1;
    long long x = a[pos];
    for (int j = 0; j < pos; j++)
      if (i & (1 << j)) {
        if (mark[j] || x % a[j])
          ok = 0;
        else
          x /= a[j];
      }
    if (!ok) continue;
    for (int j = 0; j < pos; j++)
      if (i & (1 << j)) {
        mark[j] = 1;
      }
    dfs(pos - 1, cost + 1 + calc(a[pos], x), all);
    for (int j = 0; j < pos; j++)
      if (i & (1 << j)) {
        mark[j] = 0;
      }
  }
}
int main() {
  make_p();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  ans = 0x3f3f3f3f;
  dfs(n - 1, 1, 0);
  dfs(n - 1, 0, 1);
  cout << ans << endl;
  return 0;
}
