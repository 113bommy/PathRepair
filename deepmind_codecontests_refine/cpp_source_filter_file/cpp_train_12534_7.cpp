#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[] = {-1, 1, 0, 0, 1, -1, -1, 1};
void run();
int main() {
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(16);
  run();
}
int n;
long long a[10];
long long x[10];
int facs[10];
int facsleft[10];
int children[10];
int factor(long long x) {
  int res = 0;
  for (long long i = 2; i * i <= x; ++i) {
    while (x % i == 0) res++, x /= i;
  }
  if (x > 1) res++;
  return res;
}
int ans = 1 << 30;
void dfs(int i) {
  if (i > n) {
    int res = n;
    if (children[0] > 1) res++;
    for (int j = (1); j < (n + 1); ++j) {
      if (facs[j] > 1) res += facsleft[j];
    }
    ans = min(ans, res);
    return;
  }
  for (int j = (0); j < (i); ++j) {
    if (x[j] % a[i] == 0) {
      x[j] /= a[i];
      facsleft[j] -= facs[i];
      children[j]++;
      dfs(i + 1);
      x[j] *= a[i];
      facsleft[j] += facs[i];
      children[j]--;
    }
  }
}
void run() {
  cin >> n;
  for (int i = (1); i < (n + 1); ++i) cin >> a[i];
  sort(a + 1, a + 1 + n, greater<int>());
  for (int i = (1); i < (n + 1); ++i)
    x[i] = a[i], facs[i] = facsleft[i] = factor(a[i]);
  a[0] = 0;
  dfs(1);
  cout << ans << endl;
}
