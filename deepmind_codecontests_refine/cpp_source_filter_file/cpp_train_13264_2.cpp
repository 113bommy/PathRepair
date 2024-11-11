#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40;
int n, m, q;
int a[MAXN][MAXN];
int ans[MAXN][MAXN][MAXN][MAXN];
void precompute(int x1, int y1) {
  vector<int> d(m, x1 - 1);
  for (int i = x1; i < n; i++) {
    for (int j = y1; j < m; j++) {
      if (a[i][j] == 1) {
        d[j] = i;
      }
    }
    int cur = 0;
    int res = 0;
    stack<pair<int, int> > st;
    for (int j = y1; j < m; j++) {
      while (!st.empty() && d[st.top().first] <= d[j]) {
        cur -= st.top().second;
        st.pop();
      }
      int lg = (st.empty() ? y1 - 1 : st.top().first);
      st.push(make_pair(j, (i - d[j]) * (j - lg)));
      cur += (i - d[j]) * (j - lg);
      res += cur;
      ans[x1][y1][i][j] = res + (i > y1 ? ans[x1][y1][i - 1][j] : 0);
    }
  }
}
int main() {
  scanf("%d %d %d\n", &n, &m, &q);
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%c", &c);
      if (c == '0') {
        a[i][j] = 0;
      } else {
        a[i][j] = 1;
      }
    }
    scanf("%c", &c);
  }
  for (int ug = 0; ug < n; ug++) {
    for (int lg = 0; lg < m; lg++) {
      precompute(ug, lg);
    }
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d\n", ans[x1 - 1][y1 - 1][x2 - 1][y2 - 1]);
  }
  return 0;
}
