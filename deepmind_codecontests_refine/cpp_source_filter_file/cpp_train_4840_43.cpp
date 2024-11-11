#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int vis[200];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1 || a[i][j] == 3) vis[i] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) cout << i << " ";
  }
  cout << endl;
  return 0;
}
