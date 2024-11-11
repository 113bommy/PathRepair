#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n, m;
int a[maxn], b[maxn], vis[maxn], num[maxn];
vector<int> vec[maxn];
bool com(int a, int b) { return a > b; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    int x;
    if (b[i] > a[i])
      x = b[i] - a[i];
    else
      x = b[i] + n - a[i];
    vec[a[i]].push_back(x);
  }
  for (int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
  for (int i = 1; i <= n; i++) {
    int res = -1;
    for (int j = 1; j <= n; j++) {
      if (!vec[j].size()) continue;
      int x = 0;
      if (i <= j)
        x = j - i;
      else
        x = n + j - i;
      int y = vec[j].size() - 1;
      x += y * n;
      x += vec[j][0];
      if (res < x) res = x;
    }
    cout << res << " ";
  }
}
