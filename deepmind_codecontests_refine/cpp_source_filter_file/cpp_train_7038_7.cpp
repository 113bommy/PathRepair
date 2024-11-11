#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
priority_queue<int> q;
int n, a, b, k, f, vis[30], w[30], ans;
char s1[310][30], s2[310][30];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> b >> k >> f;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
    if (i != 1 && !strcmp(s1[i], s2[i - 1]))
      w[i] = b;
    else
      w[i] = a;
    ans += w[i];
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    for (int j = i + 1; j <= n; j++) {
      if ((!strcmp(s1[i], s1[j]) && !strcmp(s2[i], s2[j])) ||
          (!strcmp(s1[i], s2[j]) && !strcmp(s2[i], s1[j]))) {
        w[i] += w[j];
        vis[j] = 1;
      }
    }
    q.push(w[i]);
  }
  int cnt = 0;
  while (!q.empty() && cnt < k) {
    int tmp = q.top();
    q.pop();
    if (tmp > f) {
      cnt++;
      ans -= (tmp - f);
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
