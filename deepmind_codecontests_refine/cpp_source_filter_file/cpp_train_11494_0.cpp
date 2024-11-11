#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int vis[N] = {0}, n;
void dfs(int m) {
  if (m == 1) {
    cout << "0 1";
    return;
  }
  vis[m] = 1;
  if (!vis[(m + n) / 2])
    dfs((m + n) / 2);
  else
    dfs(m / 2);
  cout << " " << m;
}
int main() {
  cin >> n;
  if (n & 1)
    puts("-1");
  else
    dfs(n);
  return 0;
}
