#include <bits/stdc++.h>
using namespace std;
long long l[5010];
int tot;
long long ans, n, k;
void prepare() {
  tot = 2;
  l[0] = 4, l[1] = 7;
  for (int i = 0; i < tot; i++)
    if (l[i] > 2e9)
      break;
    else
      l[tot++] = l[i] * 10 + 4, l[tot++] = l[i] * 10 + 7;
}
bool inside(long long t) {
  for (int i = 0; i < tot; i++)
    if (l[i] == t) return 1;
  return 0;
}
long long deal(int b, int n) {
  long long ret = 0, temp = 1;
  for (int i = 1; i <= n; i++) temp *= i;
  bool v[20];
  memset(v, 0, sizeof v);
  if (temp < k) return -0x7ffffff;
  k--;
  for (int i = n; i >= 1; i--) {
    temp /= i;
    int t = k / temp + 1, j;
    k -= (t - 1) * temp;
    for (j = 1; j <= n; j++) {
      if (!v[j]) t--;
      if (!t) break;
    }
    v[j] = 1;
    if (inside(b + j) && inside(b + n - i + 1)) ret++;
  }
  return ret;
}
int main() {
  prepare();
  cin >> n >> k;
  if (n <= 15)
    ans = deal(0, n);
  else {
    for (int i = 0; l[i] <= n - 15; i++) ans++;
    ans += deal(n - 15, 15);
  }
  if (ans < 0)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
