#include <bits/stdc++.h>
using namespace std;
bool isLucky(int x) {
  if (x == 0) return false;
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
vector<int> coms;
vector<int> g[100010];
vector<int> m;
bool ny[100010];
int n;
void do_something(int s) {
  queue<int> q;
  q.push(s);
  int as = 0;
  while (!q.empty()) {
    as++;
    int a = q.front();
    ny[a] = 1;
    q.pop();
    for (int i = 0; i < g[a].size(); i++)
      if (ny[g[a][i]] == 0) {
        q.push(g[a][i]);
        ny[g[a][i]] = 1;
      }
  }
  coms.push_back(as);
}
int main() {
  cin >> n;
  int a, b, c;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if (!isLucky(c)) {
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  for (int i = 1; i <= n; i++)
    if (!ny[i]) do_something(i);
  long long r = 0;
  for (int i = 0; i < coms.size(); i++)
    if (n - coms[i] > 1) r += coms[i] * (n - coms[i]) * (n - coms[i] - 1);
  cout << r;
exit:
  return (0);
}
