#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e17 + 17;
const int N = 15e4 + 10;
vector<int> g[N];
vector<int> par(N), sz(N), eg(N);
int find_par(int a) {
  if (par[a] == a)
    return a;
  else
    return par[a] = find_par(par[a]);
}
void union_set(int a, int b) {
  a = find_par(a);
  b = find_par(b);
  if (a != b) {
    if (sz[b] > sz[a]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    eg[a] += eg[b] + 1;
  } else
    eg[a]++;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    union_set(a, b);
  }
  bool ans = true;
  for (int i = 1; i <= n; i++) {
    if (par[i] == i) {
      long long req = (sz[i] * 1LL * (sz[i] - 1)) / 2;
      if (req != eg[i]) {
        ans = false;
        break;
      }
    }
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
