#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
const int maxn = 100100;
int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
int x[maxn];
int ans;
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", a + i, b + i, c + i);
  }
  for (int i = 1; i <= m; i++) {
    x[i] -= c[i];
    x[b[i]] += c[i];
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] < 0) ans += -x[i];
  }
  printf("%d", ans);
}
int main() { solve(); }
