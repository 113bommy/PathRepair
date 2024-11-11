#include <bits/stdc++.h>
using namespace std;
int a[4005];
bool vis[4005][4006];
struct pi {
  int a[2];
} pp[4005];
int main() {
  int i, j, n, m;
  int s = -1;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &pp[i].a[0], &pp[i].a[1]);
    if (pp[i].a[0] > pp[i].a[1]) swap(pp[i].a[0], pp[i].a[1]);
    vis[pp[i].a[0]][pp[i].a[1]] = 1;
    vis[pp[i].a[1]][pp[i].a[0]] = 1;
    a[pp[i].a[0]]++;
    a[pp[i].a[1]]++;
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j < i; j++) {
      for (int f = 0; f < 2; f++) {
        for (int q = 0; q < 2; q++) {
          if (pp[i].a[f] == pp[j].a[q] && vis[pp[i].a[f ^ 1]][pp[j].a[q ^ 1]]) {
            int w = 0;
            for (int u = 0; u < 2; u++) {
              w += a[pp[i].a[u]] + a[pp[j].a[u]];
            }
            w -= a[pp[i].a[f]];
            w -= 6;
            if (s == -1)
              s = w;
            else
              s = min(s, w);
          }
        }
      }
    }
  }
  cout << s << endl;
}
