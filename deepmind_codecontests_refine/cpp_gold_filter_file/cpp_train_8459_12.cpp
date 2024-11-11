#include <bits/stdc++.h>
using namespace std;
int prime[100010];
bool ispri[100010], vis[100010];
int query(char x, int y) {
  int ans;
  cout << x << " " << y << endl << flush;
  scanf("%d", &ans);
  return ans;
}
int main() {
  int n, cur, ans = 1, tot = 0;
  cin >> n;
  cur = n;
  ispri[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!ispri[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
      ispri[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 1; i <= tot; i += 100) {
    for (int j = i; j < i + 100 && j <= tot; j++) cur -= query('B', prime[j]);
    int t = query('A', 1);
    if (t == cur) continue;
    cur = t;
    for (int j = i; j < i + 100 && j <= tot; j++)
      if (query('A', prime[j])) {
        t = prime[j];
        for (long long k = 1ll * t * prime[j]; ans * k <= n; k *= prime[j])
          if (query('A', k))
            t = k;
          else
            break;
        ans *= t;
      }
  }
  cout << "C " << ans << endl << flush;
  return 0;
}
