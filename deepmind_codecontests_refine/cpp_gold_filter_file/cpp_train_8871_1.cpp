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
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
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
int used[222222], low[222222], col[222222], counter, p[222222];
vector<int> v[222222];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int root = 0;
  function<void(int)> dfs = [&](int u) {
    used[u] = 1;
    low[u] = col[u] = counter++;
    for (auto it : v[u]) {
      if (!used[it]) {
        p[it] = u;
        dfs(it);
        umin(low[u], low[it]);
      } else if (p[u] != it) {
        root = u;
        umin(low[u], col[it]);
      }
    }
  };
  dfs(1);
  cerr << "root"
       << " = " << root << '\n';
  vector<int> dis(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    queue<int> q;
    q.push(i);
    for (int j = 1; j <= n; j++) {
      dis[j] = 1000000021;
      used[j] = 0;
    }
    if (low[i] != col[i] || i == root) {
      cout << 0 << ' ';
      continue;
    }
    dis[i] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      used[u] = 1;
      for (auto it : v[u]) {
        if (dis[it] > dis[u] + 1) {
          dis[it] = dis[u] + 1;
          q.push(it);
        }
        if (low[it] != col[it] || it == root) {
          cout << dis[it] << ' ';
          while (!q.empty()) q.pop();
          break;
        }
      }
    }
  }
  getchar();
  getchar();
  return 0;
}
