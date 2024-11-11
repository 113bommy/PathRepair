#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char a[N], cpa[N];
int n, m, b[N], c[N], pos[N], p[N], vis[N];
queue<int> q;
vector<vector<int> > cycles;
vector<int> tmp, cycle;
int main() {
  int i, j, k, d, nxt;
  gets(a + 1);
  n = strlen(a + 1);
  scanf("%d\n", &m);
  for (i = 1; i <= m; i++) {
    while (!q.empty()) {
      q.pop();
    }
    cycles.clear();
    cycle.clear();
    scanf("%d %d", &k, &d);
    nxt = 0;
    for (j = 0; j <= d - 1; j++) {
      int t = 0;
      while (d * t + j + 1 <= k) {
        b[++nxt] = d * t + j + 1;
        t++;
      }
    }
    if (k == n) {
      for (j = 1; j <= k; j++) {
        p[j] = b[j];
      }
    } else {
      for (j = 1; j <= k; j++) {
        pos[b[j]] = j;
      }
      for (j = 2; j <= k; j++) {
        b[j - 1] = b[j];
      }
      b[k] = k + 1;
      nxt = 0;
      for (j = 0; j <= d - 1; j++) {
        int t = 0;
        while (d * t + j + 1 <= k) {
          c[++nxt] = b[d * t + j + 1];
          t++;
        }
      }
      int curr = 1;
      while (c[curr] != k + 1) {
        q.push(c[curr]);
        cycle.push_back(curr);
        vis[curr] = 1;
        curr = pos[c[curr]];
      }
      cycle.push_back(curr);
      vis[curr] = 1;
      for (j = 1; j <= k; j++) {
        if (!vis[j]) {
          tmp.clear();
          curr = j;
          while (!vis[curr]) {
            vis[curr] = 1;
            tmp.push_back(curr);
            curr = pos[c[curr]];
          }
          cycles.push_back(tmp);
        }
      }
      p[1] = 1;
      j = k + 1;
      q.push(k + 1);
      nxt = 2;
      while (nxt <= n - k) {
        p[nxt] = q.front();
        q.pop();
        q.push(j + 1);
        j++;
        nxt++;
      }
      curr = 1;
      j = 0;
      while (!q.empty()) {
        p[nxt + curr - 1] = q.front();
        if ((int(q.size())) != 1) {
          curr = cycle[j + 1];
        }
        j++;
        q.pop();
      }
      int idx, t;
      for (j = 0; j < (int(cycles.size())); j++) {
        int shift =
            (n - k - 1 + (int(cycles[j].size()))) % (int(cycles[j].size()));
        for (t = 0; t < (int(cycles[j].size())); t++) {
          idx = (t + shift) % (int(cycles[j].size()));
          idx = cycles[j][idx];
          p[nxt + cycles[j][t] - 1] = c[idx];
        }
      }
    }
    for (j = 1; j <= n; j++) {
      cpa[j] = a[p[j]];
      vis[j] = 0;
    }
    puts(cpa + 1);
    for (j = 1; j <= n; j++) {
      a[j] = cpa[j];
    }
  }
  return 0;
}
