#include <bits/stdc++.h>
using namespace std;
int need[20110], a[1001010], pos[211010], dp[1001010], sum[1001010];
vector<pair<int, int> > reg;
inline int get(int L, int R) {
  if (L > R) return 0;
  if (L == 0) return sum[R];
  return sum[R] - sum[L - 1];
}
int main() {
  int an = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); ++i) scanf("%d", &(a[i]));
  sort(a, a + n);
  for (int i = 0; i < (m); ++i) scanf("%d", &(pos[i]));
  sort(pos, pos + m);
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && a[j] - a[i] == j - i; j++)
      ;
    reg.push_back(make_pair(a[i], j - i));
  }
  for (int i = 0; i < (m); ++i) need[i] = ((int)(reg).size()) - 1;
  sum[0] = reg[0].second;
  for (int i = (1); i < (((int)(reg).size())); ++i) {
    sum[i] = sum[i - 1] + reg[i].second;
  }
  int now = 0;
  for (int i = 0; i < (((int)(reg).size())); ++i) {
    if (i) dp[i] = max(dp[i], dp[i - 1]);
    while (now < m && pos[now] < reg[i].first) now++;
    int yo = dp[i - 1];
    for (int j = 0; j < (now); ++j) {
      while (need[j] >= 0 && get(need[j], i - 1) < reg[i].first - pos[j])
        need[j]--;
      if (need[j] >= 0) {
        if (need[j] == 0)
          yo = max(yo, now - j);
        else
          yo = max(yo, now - j + dp[need[j] - 1]);
      }
    }
    for (int j = (now); j < (m); ++j) {
      while (need[j] > i && get(i, need[j] - 1) >= pos[j] - reg[i].first + 1)
        need[j]--;
      if (get(i, need[j]) >= pos[j] - reg[i].first + 1) {
        dp[need[j]] = max(dp[need[j]], yo + j - now + 1);
      }
    }
    dp[i] = max(dp[i], yo);
  }
  an = dp[((int)(reg).size()) - 1];
  cout << an << endl;
  return 0;
}
