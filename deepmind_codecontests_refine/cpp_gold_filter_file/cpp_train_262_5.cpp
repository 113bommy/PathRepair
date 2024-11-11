#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T mod(T a, T b) {
  while (a < 0) a += b;
  return a % b;
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mod(x * p, m);
    p = mod(p * p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T InverseEuler(T a, T m) {
  return (a == 1 ? 1 : power(a, m - 2, m));
}
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long exEuclid(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long g = exEuclid(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}
const int MAXN = 4e5 + 5;
vector<int> g[MAXN];
int n;
int subsz[MAXN];
void dfs_sz(int u = 1, int p = -1) {
  subsz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs_sz(v, u);
      subsz[u] += subsz[v];
    }
  }
}
int find_centroid(int u, int p) {
  for (auto v : g[u]) {
    if (v != p) {
      if (2 * subsz[v] > n) {
        return find_centroid(v, u);
      }
    }
  }
  return u;
}
int subtree[MAXN];
void dfs(int u, int p) {
  if (p != -1) {
    if (subtree[p] == -1) {
      subtree[u] = u;
    } else {
      subtree[u] = subtree[p];
    }
  }
  subsz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      subsz[u] += subsz[v];
    }
  }
}
int ans[MAXN];
int main(int argc, char *argv[]) {
  io();
  cin >> n;
  int x, y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs_sz(1, -1);
  int centroid = find_centroid(1, -1);
  subtree[centroid] = -1;
  dfs(centroid, -1);
  ans[centroid] = 1;
  int heaviest = -1, secondHeaviest = -1, heavyChild = -1;
  for (int i = 1; i <= n; i++) {
    if (subtree[i] == i) {
      if (subsz[i] == heaviest) {
        secondHeaviest = heaviest;
        heavyChild = -1;
      } else if (subsz[i] > heaviest) {
        secondHeaviest = heaviest;
        heaviest = subsz[i];
        heavyChild = i;
      } else if (subsz[i] > secondHeaviest) {
        secondHeaviest = subsz[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != centroid) {
      int max_rem = 0;
      if (subtree[i] == heavyChild) {
        max_rem = max(secondHeaviest, subsz[subtree[i]] - subsz[i]);
      } else {
        max_rem = heaviest;
      }
      ans[i] = (2 * (n - (subsz[i] + max_rem)) <= n);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}
