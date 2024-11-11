#include <bits/stdc++.h>
using namespace std;
int n, size[300002], k, nb[300002], par[300002];
bool a[300002];
void init(int n) {
  for (int i = 0; i <= n + 1; i++) {
    a[i] = 0;
    size[i] = 0;
    par[i] = i;
  }
  a[0] = a[n + 1] = 1;
}
int findset(int x) { return (par[x] == x) ? x : par[x] = findset(par[x]); }
void unions(int x, int y) {
  int u;
  if (x < y) {
    u = findset(y);
    par[x] = u;
    size[u] += size[x];
    size[x] = size[u];
  } else {
    u = findset(x);
    par[y] = u;
    size[y] += size[u];
    size[x] = size[y];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  cout << "1 ";
  int hi = n;
  init(n);
  for (int j = 1; j <= hi; j++) {
    cin >> k;
    a[k] = 1;
    size[k] = 1;
    if (a[k - 1]) unions(k, k - 1);
    if (a[k + 1]) unions(k, k + 1);
    cout << j - size[n + 1] + 1 << " ";
  }
}
