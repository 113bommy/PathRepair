#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 5;
int p[maxn], vis[maxn], pn;
void init() {
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) p[pn++] = i;
    for (int j = 0; j < pn && i * p[j] < maxn; j++) vis[i * p[j]] = 1;
  }
}
map<int, int> aaa;
int solve() {
  init();
  int n, x, t, cnt(0);
  scanf("%d", &n);
  scanf("%d", &x);
  for (int i = 0; i < n; ++i) scanf("%d", &t), aaa[t]++;
  if (x == 2) return printf("0");
  if (aaa.count(1)) return printf("1");
  if (x > 5e6) return printf("-1");
  for (int i = 0; i < pn; ++i) {
    if (p[i] > x) break;
    if (!aaa.count(p[i]))
      return printf("-1");
    else
      cnt++;
  }
  return printf("%d", cnt);
}
int main() { solve(); }
