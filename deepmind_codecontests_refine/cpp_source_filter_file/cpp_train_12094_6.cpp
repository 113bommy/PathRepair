#include <bits/stdc++.h>
using namespace std;
template <typename T>
T GCD(T a, T b) {
  T r;
  while (b) r = a % b, a = b, b = r;
  return a;
}
template <typename T>
void AddMod(T& x, int p) {
  if (x >= p) x -= p;
}
char y[200010];
int n;
bool IsValid(int k) {
  static bool vis[200010];
  memset(vis, 0, (n + 1) * sizeof(bool));
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int ans = y[i];
    vis[i] = true;
    int now = i + k;
    AddMod(now, n);
    while (now != i) {
      vis[now] = true;
      ans ^= y[i];
      AddMod(now += k, n);
    }
    if (ans) {
      return false;
    }
  }
  return true;
}
int main() {
  int ans = 1;
  static bool res[200010];
  scanf("%d", &n);
  memset(res, 0, sizeof(res));
  getchar();
  for (int i = 0; i < n; ++i) {
    y[i] = getchar() - '0';
  }
  for (int i = 0; i < n; ++i) {
    if (y[i]) {
      --ans;
      break;
    }
  }
  for (int k = 1; k < n; ++k) {
    int gcd = GCD(k, n);
    if (k == gcd) {
      res[k] = IsValid(k);
    } else {
      res[k] = res[gcd];
    }
  }
  for (int i = 1; i < n; ++i) {
    if (res[i]) {
      ++ans;
    }
  }
  printf("%d", ans);
  return 0;
}
