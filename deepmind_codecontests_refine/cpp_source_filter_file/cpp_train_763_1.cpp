#include <bits/stdc++.h>
using namespace std;
int n, m;
long long d[1000005], s, ans1;
int main() {
  scanf("%d%d", &n, &m);
  s = n * (n - 1) / 2 * (n - 2) / 3;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    d[x]++, d[y]++;
  }
  for (int i = 1; i <= n; i++) ans1 += d[i] * (n - 1 - d[i]);
  cout << s - (ans1 >> 1);
}
