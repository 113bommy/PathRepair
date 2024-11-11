#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
const int N = 5009;
long long mem[N][N], arr[N];
int main() {
  file();
  fast();
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) mem[i][j] = -1e18;
  for (int rem = 0; rem < x; rem++) {
    deque<pair<int, long long>> q;
    for (int idx = 0; idx < n; idx++) {
      long long add = 0;
      if (idx - k >= 0 || (!q.empty() && rem)) add = q.front().second;
      mem[idx][rem + 1] = max(mem[idx][rem + 1], arr[idx] + add);
      if (!q.empty() && q.back().first <= idx - k) q.pop_front();
      while (!q.empty() && q.back().second <= mem[idx][rem]) q.pop_back();
      q.push_back({idx, mem[idx][rem]});
    }
  }
  long long ans = -1;
  for (int i = n - k; i < n; i++) ans = max(ans, mem[i][x]);
  cout << ans << "\n";
  return 0;
}
