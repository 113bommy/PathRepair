#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
int a[100000];
int nnum[100000];
vector<int> e[100000];
int p[100000];
int cnt[100000];
bool chk[100000];
bool sortf(int x, int y) { return a[x] < a[y]; }
int root(int x) { return x == p[x] ? x : p[x] = root(p[x]); }
void merge(int x, int y) {
  cnt[y] += cnt[x];
  p[x] = y;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), nnum[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  sort(nnum, nnum + n, sortf);
  for (int i = 0; i < n; i++) p[i] = i, cnt[i] = 1;
  double ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = nnum[i];
    chk[x] = true;
    int c = 0;
    for (int j = 0; j < e[x].size(); j++) {
      int y = e[x][j];
      if (chk[y]) {
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
          ans += (double)cnt[rx] * cnt[ry] * a[x];
          merge(rx, ry);
        }
      }
    }
  }
  printf("%.6lf\n", 2 * ans / n / (n - 1));
  return 0;
}
