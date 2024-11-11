#include <bits/stdc++.h>
using namespace std;
int n;
int p[100005];
bool vis[100005];
bool par = true;
int res1 = -1, res2 = -1;
int pareja;
int k, szz;
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> p[i];
  for (int i = 1; i < n + 1; i++) {
    if (!vis[i]) {
      vis[i] = true;
      k = p[i];
      szz = 1;
      while (k != i) {
        vis[k] = true;
        k = p[k];
        szz++;
      }
      if (szz == 1) res1 = i;
      if (szz == 2) {
        res2 = i;
        pareja = p[i];
      }
      if (szz % 2 == 1) par = false;
    }
  }
  if (res1 != -1) {
    cout << "YES" << endl;
    for (int i = 1; i < n + 1; i++)
      if (i != res1) cout << res1 << " " << i << endl;
  } else if (res2 != -1 && par) {
    cout << "YES" << endl;
    memset(vis, false, sizeof vis);
    cout << res2 << " " << pareja << endl;
    ;
    vis[res2] = true;
    vis[pareja] = true;
    for (int i = 1; i < n + 1; i++) {
      if (!vis[i]) {
        vis[i] = true;
        szz = 1;
        k = p[i];
        cout << pareja << " " << i << endl;
        while (k != i) {
          vis[k] = true;
          szz++;
          if (szz % 2 == 0)
            cout << pareja << " " << k << endl;
          else
            cout << res2 << " " << k << endl;
          k = p[k];
        }
      }
    }
  } else
    cout << "NO" << endl;
}
