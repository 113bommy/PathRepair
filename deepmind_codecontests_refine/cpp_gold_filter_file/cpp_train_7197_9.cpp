#include <bits/stdc++.h>
using namespace std;
vector<long long> dfs(long long vis[], long long s, long long n,
                      vector<long long> v) {
  if (s < n - 1 && vis[s + 2] == 0) {
    v.push_back(s + 2);
    vis[s + 2] = 1;
    dfs(vis, s + 2, n, v);
  }
  if (s < n - 2 && vis[s + 3] == 0) {
    v.push_back(s + 3);
    vis[s + 3] = 1;
    dfs(vis, s + 3, n, v);
  }
  if (s < n - 3 && vis[s + 4] == 0) {
    v.push_back(s + 4);
    vis[s + 4] = 1;
    dfs(vis, s + 4, n, v);
  }
  if (s > 2 && vis[s - 2] == 0) {
    v.push_back(s - 2);
    vis[s - 2] = 1;
    dfs(vis, s - 2, n, v);
  }
  if (s > 3 && vis[s - 3] == 0) {
    v.push_back(s - 3);
    vis[s - 3] = 1;
    dfs(vis, s - 3, n, v);
  }
  if (s > 4 && vis[s - 4] == 0) {
    v.push_back(s - 4);
    vis[s - 4] = 1;
    dfs(vis, s - 4, n, v);
  } else {
    memset(vis, 0, sizeof(vis));
    v.clear();
    v.push_back(s);
  }
  return v;
}
void frooty() {
  long long n;
  cin >> n;
  long long pa = 0, push_back = 0;
  long long a, b;
  long long ans = 0;
  cin >> a >> b;
  ans += (min(a, b)) + 1;
  n--;
  pa = a, push_back = b;
  while (n--) {
    cin >> a >> b;
    if (pa > push_back) {
      if (pa == push_back) ans--;
      if (b >= pa) {
        ans += (min(a, b) - pa) + 1;
      } else {
        ans += 0;
      }
    } else {
      if (pa == push_back) ans--;
      if (a >= push_back) {
        ans += (min(a, b) - push_back) + 1;
      } else {
        ans += 0;
      }
    }
    pa = a;
    push_back = b;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    frooty();
  }
}
