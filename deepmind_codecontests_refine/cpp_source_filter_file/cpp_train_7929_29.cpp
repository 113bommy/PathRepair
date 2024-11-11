#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[205];
int a[105];
int b[105];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vis[a[i]] = true;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    vis[b[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[a[i] + b[i]]) {
        cout << a[i] << " " << b[i];
        return 0;
      }
    }
  }
}
