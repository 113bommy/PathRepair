#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1005;
vector<int> vec[MaxN];
vector<int> mp[MaxN];
int n;
int get_res(int x, int y) {
  if (((int)(mp[x]).size()) <= 1) return 0;
  int tmp = 0;
  int idx = 0, idy = 0;
  int nx = 0, ny = 0;
  int pre = mp[x][0];
  for (int i = 1; i < ((int)(mp[x]).size()); i++) {
    int now = mp[x][i];
    while (vec[x][idx] != pre && idx < ((int)(vec[x]).size())) idx++;
    while (vec[x][idx] == pre && idx < ((int)(vec[x]).size())) idx++;
    while (vec[y][idy] != pre && idy < ((int)(vec[y]).size())) idy++;
    while (vec[y][idy] == pre && idy < ((int)(vec[y]).size())) idy++;
    while (vec[x][nx] != now && nx < ((int)(vec[x]).size())) nx++;
    while (vec[y][ny] != now && ny < ((int)(vec[y]).size())) ny++;
    if (ny - idy != nx - idx) {
      tmp++;
    }
    idy = ny, idx = nx;
    pre = now;
  }
  return tmp;
}
int main() {
  while (1 == scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      mp[i].clear();
      vec[i].clear();
    }
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      while (k--) {
        int p;
        scanf("%d", &p);
        vec[i].push_back(p);
        vec[(i + 1) % n].push_back(p);
        mp[i].push_back(p);
      }
    }
    for (int i = 0; i <= n; i++) {
      sort(vec[i].begin(), vec[i].end());
      sort(mp[i].begin(), mp[i].end());
    }
    int res = 0;
    for (int i = 0; i < n; i++) res += get_res(i, (i + 1) % n);
    printf("%d\n", res);
  }
  return 0;
}
