#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
const int M = N + 100;
const int P = 1000000007;
int inc(int x, int y) {
  int ans = x + y;
  if (ans > P) ans -= P;
  return ans;
}
int Dec(int x, int y) {
  int ans = x - y;
  if (ans <= 0) ans += P;
  return ans;
}
long long val[M];
void init_(int l, int r) {
  if (l == r - 1) return;
  int m = (r + l) >> 1;
  int d = (r - l) >> 1;
  init_(l, m);
  init_(m, r);
  for (int i = 0; i <= d - 1; i++) {
    (val[l + i] *= val[m + i]) %= P;
  }
}
void solve(int l, int r) {
  if (l == r - 1) return;
  int m = (r + l) >> 1;
  int d = (r - l) >> 1;
  solve(l, m);
  solve(m, r);
  for (int i = 0; i <= d - 1; i++) {
    val[l + i] = Dec(val[l + i], val[m + i]);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= N - 1; i++) val[i] = 1;
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    val[v] = inc(val[v], val[v]);
  }
  init_(0, N);
  solve(0, N);
  cout << val[0] << endl;
  return 0;
}
