#include <bits/stdc++.h>
using namespace std;
int p[105 * 2][105], n, K, l, r;
int q[105], s[105];
bool solve() {
  bool flag = true;
  for (int i = 1; i <= n && flag; i++)
    if (s[i] != i) flag = false;
  if (flag) return false;
  if (l == -1 && r == -1) return false;
  if (l == -1) return (K - r) % 2 == 0;
  if (r == -1) return (K - l) % 2 == 0;
  if (l == 1 && r == 1 && K == 1) return true;
  if ((r > 1 || l > 1) && ((K - l) % 2 == 0 || (K - r) % 2 == 0)) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n; i++) p[100][i] = i;
  l = r = -1;
  for (int j = 101; j <= 100 + K; j++) {
    for (int i = 1; i <= n; i++) p[j][i] = p[j - 1][q[i]];
    bool flag = true;
    for (int i = 1; i <= n && flag; i++)
      if (p[j][i] != s[i]) flag = false;
    if (flag) {
      r = j - 100;
      break;
    }
  }
  for (int j = 99; j >= 100 - K; j--) {
    for (int i = 1; i <= n; i++) p[j][q[i]] = p[j + 1][i];
    bool flag = true;
    for (int i = 1; i <= n && flag; i++)
      if (p[j][i] != s[i]) flag = false;
    if (flag) {
      l = 100 - j;
      break;
    }
  }
  printf(solve() ? "YES\n" : "NO\n");
  return 0;
}
