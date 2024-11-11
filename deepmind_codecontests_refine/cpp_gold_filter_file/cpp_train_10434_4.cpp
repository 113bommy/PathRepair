#include <bits/stdc++.h>
using namespace std;
long long s[100];
int vis[100];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(vis, 0, sizeof(vis));
    int n;
    long long k;
    cin >> n >> k;
    int i = 0;
    s[i] = 1;
    for (i = 1;; i++) {
      s[i] = s[i - 1] * k;
      if (s[i] > 1e16) break;
    }
    int flag = 0;
    for (int k = 1; k <= n; k++) {
      long long x;
      cin >> x;
      for (int j = i - 1; j >= 0; j--) {
        if (x >= s[j]) {
          x -= s[j];
          vis[j]++;
        }
      }
      if (x != 0) flag = 1;
    }
    for (int k = 0; k < i; k++) {
      if (vis[k] >= 2) flag = 1;
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
