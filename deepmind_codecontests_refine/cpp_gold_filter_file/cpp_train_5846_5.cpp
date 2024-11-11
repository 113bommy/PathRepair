#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int m, a, b;
bool vis[N * 2];
long long gg, r[N * 2];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long cc(long long n) { return n * (n + 1) / 2; }
long long calc(long long n) {
  return cc((n + 1) / gg) * gg + (n + 1) % gg * (n / gg + 1);
}
int bfs(int num, int ini) {
  int ans = 0;
  queue<int> q;
  q.push(ini);
  vis[ini] = 1;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    ++ans;
    if (nd - b >= 0 && !vis[nd - b]) vis[nd - b] = 1, q.push(nd - b);
    if (nd + a <= num && !vis[nd + a]) vis[nd + a] = 1, q.push(nd + a);
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &m, &a, &b);
  long long ans = 0;
  bfs(0, 0);
  r[0] = 1;
  for (int i = 1; i <= min(a + b, m); i++)
    if (i - a >= 0 && vis[i - a]) {
      r[i] = r[i - 1] + bfs(i, i);
    } else
      r[i] = r[i - 1];
  for (int i = 0; i <= min(a + b, m); i++) ans += r[i];
  gg = gcd(a, b);
  if (m > a + b) ans += calc(m) - calc(a + b);
  cout << ans << endl;
  return 0;
}
