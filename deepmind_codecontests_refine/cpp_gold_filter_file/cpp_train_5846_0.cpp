#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int ans[MAX], vis[MAX];
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long pa(long long a0, long long an) {
  return (a0 + an) * (an - a0 + 1) / 2;
}
long long calc(long long m, int g) {
  int remainder = m % g + g;
  long long val = m;
  long long res = 0;
  while (remainder != g - 1) {
    res += val / g + 1;
    val--;
    remainder--;
    m--;
  }
  long long a0 = 1;
  long long an = m / g;
  res += pa(a0, an) * g;
  return res + m + 1;
}
int main() {
  int m, a, b;
  cin >> m >> a >> b;
  vis[0] = true;
  for (int i = 0; i < min(m + 1, MAX); i++) {
    ans[i] = i ? ans[i - 1] : 0;
    if (!vis[i]) continue;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      ans[i]++;
      int u = q.front();
      q.pop();
      if (u + a <= i and !vis[u + a]) {
        vis[u + a] = true;
        q.push(u + a);
      } else if (u + a < MAX)
        vis[u + a] = true;
      if (u - b >= 0 and !vis[u - b]) {
        vis[u - b] = true;
        q.push(u - b);
      }
    }
  }
  if (m < MAX) {
    long long cnt = 0;
    for (int i = 0; i <= m; i++) cnt += ans[i];
    cout << cnt << endl;
    return 0;
  }
  long long g = gcd(a, b);
  long long cnt = 0;
  for (int i = 0; i < MAX; i++) cnt += ans[i];
  long long aux = calc(m, g) - calc(MAX - 1, g);
  cout << cnt + aux << endl;
  return 0;
}
