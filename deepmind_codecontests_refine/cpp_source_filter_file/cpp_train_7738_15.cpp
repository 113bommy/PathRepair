#include <bits/stdc++.h>
using namespace std;
int n, k, cnt, ans, p[1005], tot = 0;
int x[1005];
bool f[1005];
int main() {
  memset(x, 0x3f3f3f3f, sizeof x);
  cin >> n >> k;
  for (int i = 2; i <= n; i++)
    if (!f[i]) {
      p[++cnt] = i;
      for (int j = i * 2; j <= n; j += i) f[j] = 1;
    }
  for (int i = 3; i <= cnt; ++i)
    for (int j = 1; j <= i - 2; ++j) {
      if (p[j] + p[j + 1] + 1 == p[i]) x[++tot] = p[i];
    }
  for (int i = 1; i <= tot; ++i)
    if (x[i] > n) {
      ans = i - 1;
      break;
    }
  if (ans >= k)
    cout << "YES";
  else
    cout << "NO";
}
