#include <bits/stdc++.h>
using namespace std;
int p[200005], b[200005];
int vis[200005];
int main() {
  int n;
  cin >> n;
  int ans = 0, num = 0;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int pos = i;
      while (vis[pos] != 1) {
        vis[pos] = 1;
        pos = p[pos] - 1;
      }
      ans++;
    }
    num += b[i];
    num %= 2;
  }
  cout << (ans > 1 ? ans : 0) + !num - 1;
  return 0;
}
