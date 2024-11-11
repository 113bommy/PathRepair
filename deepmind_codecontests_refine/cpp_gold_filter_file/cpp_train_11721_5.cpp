#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 100005;
int a[N], R[N], ar[N];
template <typename T>
inline void SI(T &n) {
  char c = getchar();
  for (n = 0; (c > 47 && c < 58); c = getchar()) n = 10 * n + c - 48;
}
int f(int e) {
  memset(ar, -1, sizeof ar);
  int r = 0, c = 0;
  for (int j = 1; j <= n; j++) {
    if (ar[a[j]] == r) continue;
    ar[a[j]] = r;
    c++;
    if (c > e) {
      c = 1;
      r++;
      ar[a[j]] = r;
    }
  }
  return r;
}
void F(int l, int r) {
  if (l > r) return;
  R[l] = f(l);
  R[r] = f(r);
  if (R[l] == R[r]) {
    for (int i = l + 1; i < r; i++) R[i] = R[l];
    return;
  }
  F(l + 1, (l + r) / 2);
  F((l + r) / 2 + 1, r - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  SI(n);
  for (int i = 1; i <= n; i++) SI(a[i]);
  F(1, n);
  for (int i = 1; i <= n; i++) printf("%d ", R[i] + 1);
  return 0;
}
