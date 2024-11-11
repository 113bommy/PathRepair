#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
int a[mx], b[mx];
struct Q {
  int x, di;
};
Q q1[mx], q2[mx];
map<int, int> hs;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int r1 = 0, r2 = 0;
  q1[0].di = 0;
  q2[0].di = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    while (r1 > 0 && q1[r1].x < a[i]) {
      hs[q1[r1].x] = 0;
      r1--;
    }
    q1[++r1].di = i;
    q1[r1].x = a[i];
    hs[a[i]] = r1;
    while (r2 >= 0 && q2[r2].x > b[i]) r2--;
    q2[++r2].di = i;
    q2[r2].x = b[i];
    int h2 = r2, h1;
    while (h2 > 0) {
      if (hs[q2[h2].x]) {
        h1 = hs[q2[h2].x];
        int cut = min(q1[h1].di, q2[h2].di) - max(q1[h1 - 1].di, q2[h2 - 1].di);
        if (cut > 0) {
          ans += cut;
        }
      }
      h2--;
    }
  }
  cout << ans << endl;
}
