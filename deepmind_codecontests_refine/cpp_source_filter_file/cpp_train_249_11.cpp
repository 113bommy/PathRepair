#include <bits/stdc++.h>
using namespace std;
const int maxn = 40010;
const long long inf = 1e18;
int vis[maxn][35];
long long my_pow(long long a, long long b) {
  long long ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
  }
  return ans;
}
int dfs(long long a, long long b, long long n, int p) {
  if (vis[a][b]) return vis[a][b];
  if (a == 1) {
    if (my_pow(2, b) >= n) return vis[a][b] = 3;
    if (dfs(a + 1, b, n, 3 - p) == 3 - p) return vis[a][b] = 3 - p;
    return vis[a][b] = dfs(a, b + 1, n, 3 - p);
  }
  if (b == 1 && my_pow(a, b + 1) >= n) {
    return vis[a][b] = (n - a + 1) % 2 + 1;
  }
  if (my_pow(a, b + 1) < n && dfs(a, b + 1, n, 3 - p) == 3 - p) {
    return vis[a][b] = 3 - p;
  }
  if (my_pow(a + 1, b) < n && dfs(a + 1, b, n, 3 - p) == 3 - p) {
    return vis[a][b] = 3 - p;
  }
  return vis[a][b] = p;
}
int main() {
  ios::sync_with_stdio(false);
  long long a, b, n, ans;
  cin >> a >> b >> n;
  ans = dfs(a, b, n, 1);
  if (ans == 1) {
    cout << "Stas\n";
  } else if (ans == 2) {
    cout << "Masha\n";
  } else {
    cout << "Missing\n";
  }
  return 0;
}
