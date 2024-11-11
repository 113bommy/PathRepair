#include <bits/stdc++.h>
using namespace std;
int a[200005];
vector<int> primes[200005];
vector<int> max_path[200005];
vector<int> L[200005];
int fact[200005];
void criba() {
  for (int i = 2; i * i < 200005; i++) {
    if (fact[i] == 0)
      for (int j = i * i; j < 200005; j += i)
        if (fact[j] == 0) fact[j] = i;
  }
  for (int i = 2; i < 200005; i++)
    if (fact[i] == 0) fact[i] = i;
}
int ans = 0;
void DFS(int u, int pd) {
  int num = a[u];
  while (num > 1) {
    int f = fact[num];
    primes[u].push_back(f);
    max_path[u].push_back(1);
    while (num % f == 0) num /= f;
  }
  for (int i = 0, v; i < L[u].size(); i++) {
    v = L[u][i];
    if (v == pd) continue;
    DFS(v, u);
    for (int j = 0; j < primes[u].size(); j++) {
      for (int k = 0; k < primes[v].size(); k++) {
        if (primes[v][k] > primes[u][j]) break;
        if (primes[v][k] == primes[u][j]) {
          ans = max(ans, max_path[u][j] + max_path[v][k]);
          max_path[u][j] = max(max_path[u][j], max_path[v][k] + 1);
        }
      }
    }
  }
  for (int j = 0; j < primes[u].size(); j++) ans = max(ans, max_path[u][j]);
}
int main() {
  int n;
  while (cin >> n) {
    criba();
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      maxi = max(maxi, a[i]);
    }
    int u, v;
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &u, &v);
      u--;
      v--;
      L[u].push_back(v);
      L[v].push_back(u);
    }
    if (maxi == 1)
      puts("0");
    else {
      DFS(0, 0);
      printf("%d\n", ans);
    }
  }
}
