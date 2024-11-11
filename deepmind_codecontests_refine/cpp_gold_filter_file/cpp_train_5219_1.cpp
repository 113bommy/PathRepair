#include <bits/stdc++.h>
using namespace std;
vector<int> arr[300001];
int vis[300001];
int coll[300001];
int color[2];
long long int power(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % 998244353;
      ;
    }
    n >>= 1;
    a = (a * a) % 998244353;
    ;
  }
  return res;
}
int biper(int src, int col) {
  vis[src] = 1;
  coll[src] = col;
  color[col]++;
  for (int child : arr[src]) {
    if (!vis[child]) {
      int res = biper(child, col ^ 1);
      if (res == -1) {
        return -1;
      }
    } else if (coll[src] == coll[child]) {
      return -1;
    }
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      arr[i].clear();
      vis[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    long long int ans = 1;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        color[0] = color[1] = 0;
        int res = biper(i, 0);
        if (res == -1) {
          flag = -1;
          break;
        }
        ans = (ans * (power(2, color[0]) + power(2, color[1]))) % 998244353;
        ;
      }
    }
    if (flag == -1) {
      cout << "0" << endl;
    } else {
      cout << ans << endl;
    }
  }
}
