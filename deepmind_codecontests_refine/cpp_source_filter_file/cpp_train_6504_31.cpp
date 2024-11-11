#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
int n;
int a[N], lit[N], mx[N];
bool mark[N];
long long ans;
void dfs(int x) {
  if (x > pow(2, n + 1) - 1) return;
  int y = 2 * x;
  lit[y] = lit[x] + a[y];
  lit[y + 1] = lit[x] + a[y + 1];
  dfs(y);
  dfs(y + 1);
}
void up(int x) {
  if (x < 1) return;
  mx[x / 2] = max(mx[x / 2], mx[x]);
  up(x / 2);
}
int main(int argc, const char* argv[]) {
  cin >> n;
  for (int i = 2; i < pow(2, n + 1); i++) cin >> a[i];
  dfs(1);
  for (int i = pow(2, n); i < pow(2, n + 1); i++) mx[i] = lit[i];
  for (int i = pow(2, n); i < pow(2, n + 1); i++) up(i);
  int mAx = mx[1];
  for (int i = 2; i < pow(2, n + 1); i++) {
    ans += mAx - mx[i];
    lit[i] += mAx - mx[i];
    dfs(i);
    for (int i = pow(2, n); i < pow(2, n + 1); i++) mx[i] = lit[i];
    for (int i = pow(2, n); i < pow(2, n + 1); i++) up(i);
  }
  cout << ans;
  return 0;
}
