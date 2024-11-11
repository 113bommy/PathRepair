#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int son[N];
vector<int> h[N];
bool vis[N];
map<pair<int, int>, int> S;
void bfs(int cnt) {
  queue<pair<int, int>> q;
  q.push({1, -1});
  vis[1] = true;
  while (q.size()) {
    pair<int, int> t = q.front();
    q.pop();
    for (int i = 0; i < h[t.first].size(); i++) {
      int j = h[t.first][i];
      if (vis[j]) continue;
      S[{min(t.first, j), max(t.first, j)}] = (++t.second) % cnt;
      q.push({j, (t.second) % cnt});
      vis[j] = true;
    }
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  static pair<int, int> temp[N];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    h[a].push_back(b);
    h[b].push_back(a);
    son[a]++, son[b]++;
    temp[i] = {min(a, b), max(a, b)};
  }
  int l = 0, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (son[i] > mid) cnt++;
    if (cnt <= k)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  bfs(l);
  for (int i = 1; i < n; i++)
    printf("%d ", S[{temp[i].first, temp[i].second}] + 1);
  return 0;
}
