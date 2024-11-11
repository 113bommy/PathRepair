#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, s;
int a[N];
bool vis[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int cnt = 0;
  if (a[s - 1]) {
    cnt++;
    a[s - 1] = 0;
  }
  sort(a, a + n);
  memset(vis, false, sizeof false);
  vis[0] = true;
  for (int i = 1; i < n; ++i) vis[a[i]] = true;
  int cmax = 0;
  for (int i = 1; i < n; ++i) {
    if (!a[i]) {
      while (cmax < n && vis[cmax]) cmax++;
      if (cmax < n) {
        vis[cmax] = true;
      }
      cnt++;
    } else {
      int pos = n - 1;
      for (int j = i; j <= pos; ++j) {
        if (!vis[a[j] - 1]) {
          while (pos >= j && cmax < a[j] - 1) {
            while (cmax < a[j] - 1 && vis[cmax]) cmax++;
            vis[cmax] = true;
            pos--;
            cnt++;
            if (cmax == a[j] - 1) break;
          }
          if (!vis[a[j] - 1]) {
            while (cmax < a[j] - 1 && vis[cmax]) cmax++;
            vis[cmax] = true;
            cnt++;
          }
        }
      }
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}
