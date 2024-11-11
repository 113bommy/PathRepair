#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int n;
long long b[N];
char s[N];
long long q[257][106], cnt[257], q1[N], q2[N];
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n / 2; ++i)
    if (s[i] == s[n + 1 - i])
      q[s[i]][++cnt[s[i]]] = min(b[i], b[n + 1 - i]), cnt[0]++;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += b[i];
  for (int i = 'a'; i <= 'z'; ++i)
    for (int t = 1; t <= cnt[i]; ++t) ans -= q[i][t];
  for (int i = 'a'; i <= 'z'; ++i) {
    if (cnt[i] > cnt[0] / 2) {
      int res = cnt[i] - cnt[0] / 2;
      for (int t = 1; t <= n; ++t)
        if (s[n + 1 - t] != s[t] && s[n + 1 - t] != i && s[t] != i)
          q1[++q1[0]] = b[t];
      sort(q1 + 1, q1 + q1[0] + 1);
      for (int t = 1; t <= res; ++t) ans -= q1[t];
      cout << ans;
      return 0;
    }
  }
  cout << ans;
}
