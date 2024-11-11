#include <bits/stdc++.h>
using namespace std;
void operator+=(pair<int, int> &a, const pair<int, int> &b) {
  a.first += b.first;
  a.second += b.second;
}
const int N = 100;
bool mt[N][N];
int n, m, k;
pair<int, int> col(int j) {
  pair<int, int> ans(0, 0);
  int amt[N + 1] = {0};
  int pref[N + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; ++i) pref[i] = mt[i - 1][j] + pref[i - 1];
  for (int i = n - 1; i >= 0; --i)
    amt[i] = amt[i + 1] + mt[i][j] - amt[min(n, i + k)];
  for (int i = 0; i < n; ++i) {
    pair<int, int> current(min(k, amt[i]), pref[i]);
    if (ans.first < current.first ||
        (ans.first == current.first && current.second < ans.second))
      ans = current;
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int v;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      scanf("%d", &v);
      mt[i][j] = v;
    }
  pair<int, int> ans;
  for (int i = 0; i < m; ++i) {
    pair<int, int> t = col(i);
    ans += t;
  }
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
