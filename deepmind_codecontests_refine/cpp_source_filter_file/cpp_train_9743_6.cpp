#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
long long self, other;
vector<int> v[maxn];
bool mark[maxn];
bool is_loop[maxn];
void dfs(int u) {
  mark[u] = 1;
  for (int i = 0; i < (v[u]).size(); i++) {
    int y = v[u][i];
    if (!mark[y]) dfs(y);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) {
      self++;
      is_loop[a] = 1;
    } else {
      v[a].push_back(b);
      v[b].push_back(a);
      other++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((v[i]).size() != 0 || is_loop) {
      dfs(i);
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i] && ((v[i]).size() != 0 || is_loop)) {
      cout << 0;
      return 0;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long l = (v[i]).size();
    ans += ((l) * (l - 1)) / 2;
  }
  ans += (self * other);
  ans += (self * (self - 1)) / 2;
  cout << ans;
}
