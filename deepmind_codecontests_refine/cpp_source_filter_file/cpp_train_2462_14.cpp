#include <bits/stdc++.h>
using namespace std;
vector<int> gr[1000005];
void dfs(vector<int> gr[], vector<int> &t, int a, int depth) {
  t[depth]++;
  for (auto u : gr[a]) dfs(gr, t, u, depth + 1);
}
int main() {
  int n;
  cin >> n;
  vector<int> t(n, 0);
  for (int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    gr[a].push_back(i);
  }
  dfs(gr, t, 1, 1);
  int ans = 0;
  for (int i = 0; i <= n; i++) ans += t[i] % 2;
  cout << ans << endl;
}
