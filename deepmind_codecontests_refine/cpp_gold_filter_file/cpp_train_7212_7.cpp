#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 1, x = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int N = 3e3 + 7;
int n, k, num[N];
long long f[N], ans;
vector<long long> a[N];
inline void dp(int x) {
  for (int(i) = (k); (i) >= (num[x]); --(i))
    f[i] = max(f[i], f[i - num[x]] + a[x][num[x]]);
}
inline void solve(int l, int r) {
  if (l == r) {
    for (int(i) = (1); (i) <= (min(k, num[l])); ++(i))
      ans = max(ans, f[k - i] + a[l][i]);
    return;
  }
  int mid = (l + r) >> 1;
  long long tmp[N];
  memset(tmp, 0, sizeof(tmp));
  for (int(i) = (0); (i) <= (k); ++(i)) tmp[i] = f[i];
  for (int(i) = (l); (i) <= (mid); ++(i)) dp(i);
  solve(mid + 1, r);
  for (int(i) = (0); (i) <= (k); ++(i)) f[i] = tmp[i];
  for (int(i) = (mid + 1); (i) <= (r); ++(i)) dp(i);
  solve(l, mid);
  for (int(i) = (0); (i) <= (k); ++(i)) f[i] = tmp[i];
}
int main() {
  n = read<int>(), k = read<int>();
  for (int(i) = (1); (i) <= (n); ++(i)) {
    num[i] = read<int>(), a[i].push_back(0);
    for (int(j) = (1); (j) <= (num[i]); ++(j)) {
      int x = read<int>();
      a[i].push_back(a[i][j - 1] + x);
    }
  }
  solve(1, n);
  return printf("%lld", ans), 0;
}
