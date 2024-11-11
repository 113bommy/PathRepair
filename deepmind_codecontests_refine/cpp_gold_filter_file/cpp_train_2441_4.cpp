#include <bits/stdc++.h>
using namespace std;
int n, m, k, tot, x, y, back;
vector<pair<int, int> > ans[50000];
void print() {
  for (int i = 1; i <= tot; ++i) {
    printf("%d", ans[i].size());
    for (int j = 0; j < ans[i].size(); ++j)
      printf(" %d %d", ans[i][j].first, ans[i][j].second);
    printf("\n");
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (m == 2) {
    for (int i = 1; i < k; ++i) {
      ans[++tot].push_back(make_pair(i, 1));
      ans[tot].push_back(make_pair(i, 2));
    }
    ++tot;
    for (int i = k; i <= n; ++i) {
      if (i % 2 == 0) {
        ans[tot].push_back(make_pair(i, 1));
        ans[tot].push_back(make_pair(i, 2));
      } else {
        ans[tot].push_back(make_pair(i, 2));
        ans[tot].push_back(make_pair(i, 1));
      }
    }
    print();
    return 0;
  }
  if (k <= n * (m / 2)) {
    bool bo = true;
    for (int i = 1; i < m; i += 2) {
      for (int j = 1; j <= n; ++j) {
        if (tot == k - 1) {
          x = j, y = i;
          bo = false;
          break;
        }
        ans[++tot].push_back(make_pair(j, i));
        ans[tot].push_back(make_pair(j, i + 1));
      }
      if (!bo) break;
    }
    ++tot;
    for (; x <= n; ++x)
      if ((n - x) % 2 == 1) {
        ans[tot].push_back(make_pair(x, y + 1));
        ans[tot].push_back(make_pair(x, y));
      } else {
        ans[tot].push_back(make_pair(x, y));
        ans[tot].push_back(make_pair(x, y + 1));
      }
    back = y;
    for (y += 2; y <= m; ++y) {
      if ((y - back) % 2 == 0)
        for (int i = n; i >= 1; --i) ans[tot].push_back(make_pair(i, y));
      else
        for (int i = 1; i <= n; ++i) ans[tot].push_back(make_pair(i, y));
    }
    print();
  } else {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j + 1 <= m; j += 2) {
        ans[++tot].push_back(make_pair(i, j));
        ans[tot].push_back(make_pair(i, j + 1));
      }
    k -= n * (m / 2);
    for (int i = 1; i < k; ++i) {
      ans[++tot].push_back(make_pair(2 * i - 1, m));
      ans[tot].push_back(make_pair(2 * i, m));
    }
    ++tot;
    for (int i = 2 * (k - 1) + 1; i <= n; ++i)
      ans[tot].push_back(make_pair(i, m));
    print();
  }
  return 0;
}
