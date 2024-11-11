#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, serial = 0, adj[100005], S = 0, G = 0, pin = 0, ans = 0, j = 0, mx = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      G++;
    }
    if (s[i] == 'S' || i == n - 1) {
      adj[S] = G;
      S++;
      if (G > 0) pin++;
      G = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S' || i == n - 1) {
      j++;
      if (s[i - 1] == 'G' && s[i + 1] == 'G') {
        if (pin > 2)
          ans = adj[j - 1] + adj[j] + 1;
        else
          ans = adj[j - 1] + adj[j];
      } else if ((s[i + 1] == 'G' || s[i - 1] == 'G') && pin > 2) {
        ans = adj[j - 1] + 1;
      } else {
        ans = adj[j - 1];
      }
    }
    mx = max(mx, ans);
  }
  cout << mx << endl;
  return 0;
}
