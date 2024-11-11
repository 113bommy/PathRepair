#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int f[N], vis[N], p[N];
void pre() {
  for (int i = 2; i * i < N; ++i) {
    if (!vis[i]) p[++p[0]] = i;
    for (int j = 1; j <= p[0] && i * p[j] < N; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) {
        break;
      }
    }
  }
}
int main() {
  int Q;
  scanf("%d", &Q);
  pre();
  memset(f, -0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= 1000; ++i)
    for (int j = 0; j < i; ++j)
      if (vis[i - j]) f[i] = max(f[i], f[j] + 1);
  while (Q--) {
    int x;
    scanf("%d", &x);
    int ans = 0;
    if (x >= 1000) {
      if (x % 4 == 0) ans = x / 4;
      if (x % 4 == 1) ans = (x - 9) / 4 + 1;
      if (x % 4 == 2) ans = (x - 6) / 4 + 1;
      if (x % 4 == 3) ans = (x - 21) / 4 + 1;
    } else {
      ans = f[x];
    }
    cout << (ans <= 0 ? -1 : ans) << endl;
  }
}
