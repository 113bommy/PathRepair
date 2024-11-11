#include <bits/stdc++.h>
using namespace std;
const int N = 500 * 1000;
int n, m;
int par[N];
int siz[N];
int findpar(int v) {
  if (par[v] == v) return v;
  return par[v] = findpar(par[v]);
}
void merge(int a, int b) {
  a = findpar(a);
  b = findpar(b);
  if (a == b) return;
  if (siz[a] > siz[b]) swap(a, b);
  siz[b] += siz[a];
  par[a] = b;
}
int main() {
  for (int i = 1; i < N; i++) par[i] = i, siz[i] = 1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    if (k == 0) continue;
    int a, b;
    cin >> a;
    for (int j = 1; j < k; j++) {
      cin >> b;
      merge(a, b);
    }
  }
  for (int i = 1; i <= n; i++) {
    int t = i;
    t = findpar(t);
    cout << siz[t] << " ";
  }
  return 0;
}
