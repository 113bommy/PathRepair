#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1 << 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int nCase = 0;
int n, r;
pair<int, int> p[3600];
int cnt;
vector<pair<int, int> > ans, tmp;
int maxDis;
bool cmp(pair<int, int>& A, pair<int, int>& B) {
  return A.first * A.first + A.second * A.second >
         B.first * B.first + B.second * B.second;
}
long long calc(pair<int, int>& A, pair<int, int>& B) {
  return (A.first - B.first) * (A.first - B.first) +
         (A.second - B.second) * (A.second - B.second);
}
void dfs(int top) {
  if (tmp.size() == n) {
    long long x = 0LL;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) x += calc(tmp[i], tmp[j]);
    if (x > maxDis) {
      maxDis = x;
      ans = tmp;
    }
    return;
  }
  if (top == cnt) return;
  tmp.push_back(p[top]);
  dfs(top);
  tmp.pop_back();
  dfs(top + 1);
}
int main(int argc, const char* argv[]) {
  cin >> n >> r;
  for (int i = -r; i <= r; ++i)
    for (int j = -r; j <= r; ++j)
      if (i * i + j * j <= r * r) p[cnt++] = pair<int, int>(i, j);
  sort(p, p + cnt, cmp);
  cnt = min(cnt, 120 / n);
  dfs(0);
  cout << maxDis << endl;
  for (int i = 0; i < n; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
