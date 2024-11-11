#include <bits/stdc++.h>
using namespace std;
const long double pi = 2 * acos(0.0);
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class TT>
bool pal(T a, TT n) {
  int k = 0;
  for (int i = 0; i <= n / 2; i++) {
    if (a[i] != a[n - i - 1]) {
      k = 1;
      break;
    }
  }
  return k ? 0 : 1;
}
long long x, y, col[222222];
vector<long long> v[222222];
int flag;
void dfs(int u) {
  for (auto it : v[u]) {
    if (col[it]) {
      if (col[it] == col[u]) {
        flag = 1;
        return;
      }
      continue;
    }
    if (col[u] == 1)
      col[it] = 2, y++;
    else
      col[it] = 1, x++;
    dfs(it);
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (!m) return cout << "3 " << (n * (n - 1) * (n - 2)) / 6, 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int oo = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) {
      x = 1, y = 0;
      flag = 0;
      col[i] = 1;
      dfs(i);
      if (flag) return cout << "0 1\n", 0;
      if ((x + y) > 2) {
        ans += (x * (x - 1)) / 2ll;
        ans += (y * (y - 1)) / 2ll;
        oo = 1;
      }
    }
  }
  if (!oo) return cout << m * (n - 2), 0;
  cout << "1 " << ans;
  getchar();
  getchar();
  return 0;
}
