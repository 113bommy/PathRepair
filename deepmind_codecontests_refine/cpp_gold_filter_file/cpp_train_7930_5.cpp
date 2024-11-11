#include <bits/stdc++.h>
using namespace std;
int N;
int seg[300010][2];
bool vis[300010];
vector<int> vail;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
      seg[i][0] = 691691691, seg[i][1] = 0, vis[i] = 0;
    vail.clear();
    int a;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
      scanf("%d", &a);
      if (!vis[a]) {
        vis[a] = 1, cnt++;
      }
      seg[a][0] = min(seg[a][0], i);
      seg[a][1] = i;
    }
    for (int i = 1; i <= N; i++)
      if (vis[i]) vail.push_back(i);
    int ans = 691691691;
    int l, r;
    int now = 0;
    l = 0;
    for (int i = 0; i < vail.size(); i++) {
      if (seg[vail[i]][0] > now) {
        now = seg[vail[i]][1];
        r = i;
      } else {
        ans = min(ans, cnt - (r - l + 1));
        now = seg[vail[i]][1];
        l = i, r = i;
      }
    }
    ans = min(ans, cnt - (r - l + 1));
    cout << ans << endl;
  }
  return 0;
}
