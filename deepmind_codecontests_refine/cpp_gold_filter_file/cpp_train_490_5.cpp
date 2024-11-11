#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
const int MOD = 1e9 + 7;
const long long inf = 1e14 + 5;
const long long dd = 1e5 + 5;
ll ncr(ll n, ll r) {
  ll res = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (ll i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
ll sum, sz;
vector<int> parent(dd);
vector<int> degree(55), par(55);
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void merge(int a, int b) { par[find(a)] = find(b); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  if (n < m) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    degree[x]++;
    degree[y]++;
    if (degree[x] > 2 or degree[y] > 2 or (find(x) == find(y) and n != i)) {
      cout << "NO" << '\n';
      return 0;
    }
    merge(x, y);
  }
  cout << "YES" << '\n';
  cout << n - m << '\n';
  for (int i = 1; i <= n; i++) {
    while (degree[i] < 2) {
      int j = i + (n != 1);
      for (; j <= n; j++) {
        if (degree[j] < 2 and (m + 1 == n or n <= 2 or find(i) != find(j))) {
          cout << i << " " << j << endl;
          degree[i]++;
          degree[j]++;
          m++;
          merge(i, j);
          break;
        }
      }
    }
  }
  return 0;
}
