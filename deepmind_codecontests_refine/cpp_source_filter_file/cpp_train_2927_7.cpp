#include <bits/stdc++.h>
using namespace std;
int a[1505], val[1505];
pair<int, int> seg[1505];
bool isBad[1505];
int dp[1505][1505], g[1505];
int pre[1505];
int prevOverWrap[1505];
bool isGood(int n, int s, int m, int k, int value) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= m; ++i) {
    g[i] = -1e9;
  }
  g[0] = 0;
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1];
    if (a[i] <= value) {
      ++pre[i];
    }
  }
  int cur = 0;
  for (int i = 0; i < s; ++i) {
    while (cur < i) {
      if (seg[cur].second < seg[i].first) {
        for (int j = 0; j <= m; ++j) {
          g[j] = max(g[j], dp[cur][j]);
        }
        ++cur;
      } else {
        break;
      }
    }
    int l = seg[i].first, r = seg[i].second;
    dp[i][0] = -1e9;
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = -1e9;
      dp[i][j] = max(g[j - 1] + pre[r] - pre[l - 1], dp[i][j]);
      if (prevOverWrap[i] != -1) {
        int gl = seg[prevOverWrap[i]].second + 1;
        dp[i][j] =
            max(dp[i][j], dp[prevOverWrap[i]][j - 1] + pre[r] - pre[gl - 1]);
      }
      if (dp[i][j] >= k) {
        return true;
      }
    }
  }
  return false;
}
void solve() {
  int n, s, m, k;
  scanf("%d %d %d %d ", &n, &s, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d ", &a[i]);
    val[i] = a[i];
  }
  sort(val + 1, val + n + 1);
  for (int i = 0; i < s; ++i) {
    scanf("%d %d ", &seg[i].first, &seg[i].second);
    seg[i].second *= -1;
  }
  sort(seg, seg + s);
  for (int i = 0; i < s; ++i) {
    seg[i].second *= -1;
  }
  int pos = 0;
  for (int i = 0; i < s; ++i) {
    if (isBad[i]) {
      continue;
    }
    for (int j = i + 1; j < s; ++j) {
      if (seg[i].first <= seg[j].first && seg[j].second <= seg[i].second) {
        isBad[j] = true;
      }
    }
    seg[pos++] = seg[i];
  }
  for (int i = 0; i < pos; ++i) {
    prevOverWrap[i] = -1;
    for (int j = 0; j < i; ++j) {
      assert(seg[j].first < seg[i].first && seg[j].second < seg[i].second);
      if (seg[i].first < seg[j].second) {
        if (prevOverWrap[i] == -1 ||
            seg[prevOverWrap[j]].first > seg[j].first) {
          prevOverWrap[i] = j;
        }
      }
    }
  }
  const int lim = (1e9) + 1;
  int l = 1, r = lim, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (isGood(n, pos, m, k, mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l == lim) {
    printf("-1\n");
  } else {
    printf("%d\n", l);
  }
}
int main() {
  solve();
  return 0;
}
