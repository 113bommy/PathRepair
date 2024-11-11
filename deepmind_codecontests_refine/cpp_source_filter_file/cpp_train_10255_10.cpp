#include <bits/stdc++.h>
using namespace std;
bool pdo = true;
int n;
int s[2005], p[2005];
int c[2005], pos[2005], ps[2005], pa[2005], pb[2005], d[2005];
long long ansval = 0;
pair<int, int> tmppii;
vector<pair<int, int> > ans;
void showm() {
  printf("m -> ");
  for (int i = 1; i <= n; i++) printf("%d ", p[i]);
  printf("\n");
}
void showc() {
  printf("c -> ");
  for (int i = 1; i <= n; i++) printf("%d ", c[i]);
  printf("\n");
}
int main() {
  int mpos;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    pa[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    pb[s[i]] = i;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (p[i] == s[i]) continue;
      for (int j = i + 1; j <= pb[p[i]]; j++) {
        int t1, t2, tp1, tp2, cp1, cp2;
        cp1 = pb[p[i]] - i;
        cp2 = j - pb[p[j]];
        if (cp1 > 0 && cp2 > 0) {
          ansval += j - i;
          swap(p[i], p[j]);
          pa[p[i]] = i;
          pa[p[j]] = j;
          ans.push_back(make_pair(i, j));
        }
      }
    }
  }
  printf("%I64d\n", ansval);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
