#include <bits/stdc++.h>
using namespace std;
long long fp(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long res;
  res = fp(n, p / 2);
  res = (res * res);
  if (p % 2) res = (res * n);
  return res;
}
int n, t, k;
int col[200010], ans;
int sol(int a, int c) {
  int p = 0;
  for (int i = a; i <= a + k - 1; i++, c = (c + 1) % 3) {
    if (col[i] != c) p++;
  }
  return p;
}
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        col[i] = 0;
      else if (s[i] == 'G')
        col[i] = 1;
      else
        col[i] = 2;
    }
    int x0 = sol(0, 0), x1 = sol(0, 1), x2 = sol(0, 2);
    int p0 = (k + 1) % 3, p1 = k % 3, p2 = (k + 1) % 3;
    ans = min(x0, min(x1, x2));
    for (int i = k; i < n; i++) {
      int t1 = x0 + (col[i] != p1) - (col[i - k] != 0);
      int t2 = x1 + (col[i] != p2) - (col[i - k] != 1);
      int t0 = x2 + (col[i] != p0) - (col[i - k] != 2);
      ans = min(ans, min(t0, min(t1, t2)));
      x0 = t0;
      x1 = t1;
      x2 = t2;
    }
    cout << ans << '\n';
  }
  return 0;
}
