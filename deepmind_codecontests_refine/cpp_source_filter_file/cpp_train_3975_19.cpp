#include <bits/stdc++.h>
using namespace std;
const int maxn = 50, maxdel = 101;
long long d[maxn][maxn][maxdel];
pair<int, int> pr[maxn][maxn][maxdel];
struct subject {
  int num;
  long long a, b;
  int c;
};
inline bool operator<(const subject &s1, const subject &s2) {
  return s1.c < s2.c;
};
subject ss[maxn];
int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 3) {
    for (int i = 0; i < m; i++) {
      ss[i].num = i;
      scanf("%I64d%I64d%d", &ss[i].a, &ss[i].b, &ss[i].c);
    }
    sort(ss, ss + m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int y = 0; y <= (int)(ss[j].b - ss[j].a); y++) {
          d[i][j][y] = -((long long)3e18);
          pr[i][j][y] = make_pair(-1, -1);
        }
      }
    }
    for (int j = 0; j < m; j++) {
      for (long long a1 = ss[j].a; a1 <= ss[j].b; a1++) {
        d[0][j][(int)(a1 - ss[j].a)] = a1;
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (long long a1 = ss[j].a; a1 <= ss[j].b; a1++) {
          long long ansn = -((long long)3e18);
          pair<int, int> prn(-1, -1);
          long long aprev = a1 - k;
          for (int j0 = 0; ss[j0].c < ss[j].c; j0++) {
            if (ss[j0].a <= aprev && aprev <= ss[j0].b) {
              if (ansn < d[i - 1][j0][aprev - ss[j0].a]) {
                ansn = d[i - 1][j0][aprev - ss[j0].a];
                prn = make_pair(j0, aprev - ss[j0].a);
              }
            }
          }
          aprev = a1 / k;
          if (aprev * k == a1) {
            for (int j0 = 0; ss[j0].c < ss[j].c; j0++) {
              if (ss[j0].a <= aprev && aprev <= ss[j0].b) {
                if (ansn < d[i - 1][j0][aprev - ss[j0].a]) {
                  ansn = d[i - 1][j0][aprev - ss[j0].a];
                  prn = make_pair(j0, aprev - ss[j0].a);
                }
              }
            }
          }
          if (ansn > -((long long)3e18)) ansn += a1;
          d[i][j][(int)(a1 - ss[j].a)] = ansn;
          pr[i][j][(int)(a1 - ss[j].a)] = prn;
        }
      }
    }
    int i = n - 1;
    int j = -1, y = -1;
    long long mxans = -((long long)3e18);
    for (int jn = 0; jn < m; jn++) {
      for (int yn = 0; yn <= (int)(ss[jn].b - ss[jn].a); yn++) {
        if (mxans < d[i][jn][yn]) {
          mxans = d[i][jn][yn];
          j = jn;
          y = yn;
        }
      }
    }
    if (j == -1) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    vector<pair<int, long long> > ans;
    while (i >= 0) {
      ans.push_back(make_pair(j, y + ss[j].a));
      pair<int, int> prn = pr[i][j][y];
      j = prn.first;
      y = prn.second;
      i--;
    }
    reverse(ans.begin(), ans.end());
    assert((int)ans.size() == n);
    for (int i = 0; i < n; i++) {
      printf("%d %I64d\n", ans[i].first + 1, ans[i].second);
    }
  }
  return 0;
}
