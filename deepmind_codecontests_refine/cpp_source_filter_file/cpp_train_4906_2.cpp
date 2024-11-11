#include <bits/stdc++.h>
using namespace std;
int mdeg[505];
int vis[505];
vector<pair<int, int> > edge;
int main() {
  int n;
  scanf("%d", &n);
  int lon = 0;
  int tampon = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &mdeg[i]);
    if (mdeg[i] > 1) lon++;
    if (mdeg[i] > 2) tampon += mdeg[i] - 2;
  }
  tampon += 2;
  int add = 0;
  for (int i = 0; i < n; i++) {
    if (mdeg[i] == 1) tampon--, add++;
  }
  if (tampon < 0)
    printf("NO\n");
  else {
    int prev = -1;
    int fir = 0;
    for (int i = 0; i < n; i++) {
      if (mdeg[i] > 1) {
        if (prev == -1) fir = i;
        if (prev != -1) edge.push_back(pair<int, int>(i + 1, prev + 1));
        vis[i] = 1;
        prev = i;
      }
    }
    mdeg[fir]++;
    mdeg[prev]++;
    int j = 0;
    while (j < n) {
      while (j < n && vis[j]) j++;
      if (j >= n) break;
      if (mdeg[fir] > 2) {
        edge.push_back(pair<int, int>(fir + 1, j));
        mdeg[fir]--;
        vis[j] = 1;
        break;
      }
    }
    while (j < n) {
      while (j < n && vis[j]) j++;
      if (j >= n) break;
      if (mdeg[prev] > 2) {
        edge.push_back(pair<int, int>(prev + 1, j));
        mdeg[prev]--;
        vis[j] = 1;
        break;
      }
    }
    int i = 0;
    while (j < n && i < n) {
      while (j < n && vis[j]) j++;
      while (i < n && mdeg[i] <= 2) i++;
      if (j >= n || i >= n) break;
      mdeg[i]--;
      vis[j] = 1;
      edge.push_back(pair<int, int>(i + 1, j + 1));
    }
    add = min(add, 2);
    printf("YES %d\n", add + lon - 1);
    printf("%d\n", edge.size());
    for (i = 0; i < edge.size(); i++) {
      printf("%d %d\n", edge[i].first, edge[i].second);
    }
  }
  return 0;
}
