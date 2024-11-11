#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const int A = 1e6 + 3;
const int inf = 1e9;
int n, qf, qb, ans, par[A], d[A], minPrime[A], qu[N];
vector<int> a[A];
int main() {
  for (int i = 2; i * i < A; i++)
    if (minPrime[i] == 0) {
      for (int j = i * i; j < A; j += i)
        if (minPrime[j] == 0) {
          minPrime[j] = i;
        }
    }
  for (int i = 2; i < A; i++)
    if (minPrime[i] == 0) minPrime[i] = i;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, u = 0, v = 0;
    cin >> x;
    while (x != 1) {
      int tmp = minPrime[x], cnt = 0;
      while (x != 1 && x % tmp == 0) {
        x /= tmp;
        cnt++;
      }
      if (cnt % 2 == 0) continue;
      if (u == 0)
        u = tmp;
      else
        v = tmp;
    }
    if (u == 0 && v == 0) {
      u = 1;
      v = 1;
    } else if (v == 0)
      v = 1;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  ans = inf;
  minPrime[1] = 1;
  for (int i = 1; i <= 1000; i++)
    if (minPrime[i] == i) {
      qf = qb = 0;
      qu[0] = i;
      par[i] = -1;
      for (int j = 1; j < A; j++) d[j] = inf;
      d[i] = 0;
      while (qf <= qb) {
        bool skp = true;
        int u = qu[qf++];
        for (int j = 0; j < a[u].size(); j++) {
          int v = a[u][j];
          if (d[v] == inf) {
            d[v] = d[u] + 1;
            par[v] = u;
            qu[++qb] = v;
          } else {
            if (par[u] == v && skp) {
              skp = false;
              continue;
            }
            ans = min(ans, d[u] + d[v] + 1);
          }
        }
      }
    }
  cout << (ans == inf ? -1 : ans);
  return 0;
}
