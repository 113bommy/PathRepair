#include <bits/stdc++.h>
using namespace std;
int par[500005];
int find_papa(int a) {
  if (par[a] == a)
    return a;
  else {
    return find_papa(par[a]);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  while (m--) {
    int k;
    cin >> k;
    if (k == 0) continue;
    if (k == 1) {
      int a;
      cin >> a;
    } else {
      int p;
      cin >> p;
      for (int i = 1; i < k; i++) {
        int a;
        cin >> a;
        int p1 = find_papa(p);
        int p2 = find_papa(a);
        if (p1 == p2) {
          continue;
        } else {
          if (p1 > p2) swap(p1, p2);
          par[p2] = p1;
        }
      }
    }
  }
  int ans[500005];
  for (int i = 1; i <= n; i++) {
    int kk = find_papa(i);
    ans[kk]++;
  }
  for (int i = 1; i <= n; i++) {
    int kk = find_papa(i);
    cout << ans[kk] << " ";
  }
  cout << endl;
  return 0;
}
