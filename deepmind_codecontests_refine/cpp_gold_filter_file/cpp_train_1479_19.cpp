#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long INF = 1e18 + 7;
vector<vector<long long>> color(4);
vector<vector<int>> g;
int freq[maxn];
int cor[maxn];
int trad[4];
int resp;
void mark(int u, int c) {
  if (cor[u] != -1) return;
  cor[u] = c;
  c = (c + 1) % 3;
  for (auto v : g[u]) {
    mark(v, c);
  }
}
void seta(int i) {
  if (i == 0) {
    trad[0] = 0;
    trad[1] = 1;
    trad[2] = 2;
  } else if (i == 1) {
    trad[0] = 0;
    trad[1] = 2;
    trad[2] = 1;
  } else if (i == 2) {
    trad[0] = 1;
    trad[1] = 0;
    trad[2] = 2;
  } else if (i == 3) {
    trad[0] = 1;
    trad[1] = 2;
    trad[2] = 0;
  } else if (i == 4) {
    trad[0] = 2;
    trad[1] = 0;
    trad[2] = 1;
  } else if (i == 5) {
    trad[0] = 2;
    trad[1] = 1;
    trad[2] = 0;
  }
}
long long solve(int n) {
  long long mini = INF;
  long long sum;
  for (int i = 0; i < 6; i++) {
    sum = 0;
    seta(i);
    for (int i = 0; i < n; i++) {
      sum += color[trad[cor[i]]][i];
    }
    if (sum < mini) {
      mini = sum;
      resp = i;
    }
  }
  return mini;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      color[i].push_back(a);
    }
  }
  g.resize(n + 4);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    freq[u]++;
    freq[v]++;
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (freq[i] >= 3) ok = false;
  }
  if (ok == false)
    printf("%d\n", -1);
  else {
    for (int i = 0; i < n; i++) {
      cor[i] = -1;
    }
    for (int i = 0; i < n; i++) {
      if (freq[i] == 1) {
        mark(i, 0);
        break;
      }
    }
    long long ret = solve(n);
    seta(resp);
    printf("%lld\n", ret);
    for (int i = 0; i < n; i++) {
      printf("%d ", trad[cor[i]] + 1);
    }
    printf("\n");
  }
}
