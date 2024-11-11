#include <bits/stdc++.h>
using namespace std;
const int N = 109;
bool B[N], G[N];
int main() {
  int n, m, a, b, x, f = 1;
  scanf("%d%d", &n, &m);
  scanf("%d", &a);
  for (int i = 0; i < a; ++i) {
    scanf("%d", &x);
    B[x] = 1;
  }
  scanf("%d", &b);
  for (int i = 0; i < b; ++i) {
    scanf("%d", &x);
    G[x] = 1;
  }
  for (int i = 0; i < N; ++i) {
    if (B[i % n] || G[i % m]) {
      B[i % n] = G[i % m] = 1;
    }
  }
  for (int i = 0; i < n; ++i)
    if (!B[i]) f = 0;
  for (int i = 0; i < m; ++i)
    if (!G[i]) f = 0;
  cout << (f ? "Yes" : "No");
  return 0;
}
