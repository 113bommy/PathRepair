#include <bits/stdc++.h>
using namespace std;
const long long max_n = 1000011;
int n, a[max_n], p[max_n], d[max_n], sum[max_n];
int ans;
vector<int> v[max_n];
void bfs() {
  queue<int> q;
  q.push(0);
  while (q.size()) {
    int x = q.front();
    if (x == 0)
      d[x] = 0;
    else
      d[x] = d[p[x]] + 1;
    q.pop();
    for (int i = 0; i < v[x].size(); ++i) {
      q.push(v[x][i]);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
    v[p[i]].push_back(i);
    a[i] = 1;
  }
  bfs();
  for (int i = 0; i < n; ++i) {
    ++sum[d[i]];
  }
  for (int i = 0; i < n; ++i) {
    ans += sum[i] % 2;
  }
  cout << ans << endl;
  return 0;
}
