#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const double PI = acos(-1.0);
int n, m, k, a[maxn], cnt;
vector<int> pos[maxn];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]].push_back(i);
  }
  int maxx = 0;
  for (int i = 1; i <= m; i++) {
    int len = pos[i].size();
    int nowmaxx = 0;
    if (len > 0) nowmaxx = max(nowmaxx, 1);
    int nowk = 0, l = 0;
    for (int j = 1; j < len; j++) {
      int need = pos[i][j] - pos[i][j - 1] - 1;
      nowmaxx++;
      nowk += need;
      while (nowk > k && l < j) {
        nowk = nowk - pos[i][l + 1] - pos[i][l] - 1;
        nowmaxx--;
        ++l;
      }
      maxx = max(maxx, nowmaxx);
    }
  }
  printf("%d\n", maxx);
  return 0;
}
