#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int c[maxn], n;
int sum(int x) {
  int ans = 0;
  while (x) {
    ans += c[x];
    x -= x & -x;
  }
  return ans;
}
void add(int x, int v) {
  while (x <= n) {
    c[x] += v;
    x += x & -x;
  }
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) c[i] = 0;
  queue<int> g[35];
  for (int i = 1; i <= n; i++) {
    g[s[i] - 'a'].push(i);
    add(i, 1);
  }
  long long ans = 0;
  for (int i = n; i; i--) {
    int x = g[s[i] - 'a'].front();
    g[s[i] - 'a'].pop();
    ans += sum(x) - 1;
    add(x, -1);
  }
  printf("%lld\n", ans);
  return 0;
}
