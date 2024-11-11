#include <bits/stdc++.h>
using namespace std;
int T, N, K, id[101 * 2], a[101], b[101];
bool vis[101 * 2];
int get() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
bool cross(int a, int b, int c, int d) {
  if (a > b) swap(a, b);
  if (c > a && c < b) return d < a || d > b;
  if (d > a && d < b) return c < a || c > b;
  return 0;
}
int main() {
  T = get();
  while (T--) {
    N = get(), K = get();
    for (int i = 1; i <= N * 2; i++) vis[i] = 0;
    for (int i = 1; i <= K; i++)
      a[i] = get(), b[i] = get(), vis[a[i]] = 1, vis[b[i]] = 1;
    int j = 1;
    for (int i = 1; i <= N - K << 1; i++) {
      while (vis[j]) j++;
      id[i] = j++;
    }
    for (int i = K + 1; i <= N; i++) a[i] = id[i - K], b[i] = id[i + N - K * 2];
    int ans = 0;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= i - 1; j++) ans += cross(a[i], b[i], a[j], b[j]);
    cout << ans << '\n';
  }
  return 0;
}
