#include <bits/stdc++.h>
using namespace std;
int p, k, a[1000006], sz[1000006], link[1000006], ok[1000006];
int findLink(int x) {
  while (x != link[x]) x = link[x];
  return x;
}
bool isSameLink(int a, int b) { return findLink(a) == findLink(b); }
void unite(int a, int b) {
  a = findLink(a);
  b = findLink(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  link[b] = a;
}
int main() {
  cin >> p >> k;
  for (int i = 0; i < p; i++) sz[i] = 1, link[i] = i;
  if (k < 2) {
    long long int ans = 1;
    for (int i = 0; i < p - 1; i++) {
      ans *= p;
      ans %= 1000000007;
    }
    if (k == 1) {
      ans *= p;
      ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
  }
  for (int i = 0; i < p; i++) {
    int j = (1LL * k * i) % p;
    unite(i, j);
  }
  long long int ans = 1;
  for (int i = 0; i < p; i++) {
    int u = findLink(i);
    if (sz[u] == 1 || ok[u]) continue;
    ok[u] = 1;
    ans *= p;
    ans %= 1000000007;
  }
  cout << ans << endl;
}
