#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
int n, m;
int ans[707][707][3];
bool used[707];
int start;
void DFS(int v, int len = 0) {
  used[v] = true;
  for (int i = 0; i < n; i++) {
    if (ans[v][i][0] && !used[v]) {
      DFS(i, len + 1);
    }
  }
  used[v] = false;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    ans[a][b][0] = ans[b][a][0] = 1;
  }
  for (int i = 0; i < n; i++) {
    used[i] = true;
    for (int u = 0; u < n; u++) {
      if (ans[i][u][0]) {
        used[u] = true;
        for (int t = 0; t < n; t++) {
          if (ans[u][t][0] && !used[t]) ++ans[i][t][1];
        }
        used[u] = false;
      }
    }
    used[i] = false;
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    used[i] = true;
    for (int u = 0; u < n; u++) {
      if (ans[i][u][0]) {
        used[u] = true;
        for (int t = 0; t < n; t++) {
          if (!used[t]) {
            ans[i][t][2] += ans[u][t][1];
            if (ans[i][t][0]) --ans[i][t][2];
          }
        }
        used[u] = false;
      }
    }
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    used[i] = true;
    for (int u = 0; u < n; u++) {
      if (ans[i][u][0]) {
        used[u] = true;
        for (int t = 0; t < n; t++) {
          if (!used[t] && ans[i][t][0]) {
            sum += ans[u][t][2];
            int minus = 0;
            if (ans[u][t][0]) minus = 1;
            sum -= (long long)(max(0, ans[i][u][1] - minus)) *
                   (max(0, ans[i][t][1] - minus));
          }
        }
        used[u] = false;
      }
    }
    used[i] = false;
  }
  cout << sum / 5 / 2 << endl;
  return 0;
}
