#include <bits/stdc++.h>
using namespace std;
void fakemain() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n], tmp[n];
    for (int i = 0; i < n; i++) cin >> a[i], tmp[i] = a[i];
    int b[110];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b[x]++;
    }
    sort(tmp, tmp + n);
    set<int> s, s1;
    bool f = 1;
    for (int i = 0; i < n - 1; i++) {
      s.insert(a[i]);
      s1.insert(tmp[i]);
      if (s != s1 && b[i + 1] == 0) {
        f = 0;
        break;
      }
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() { fakemain(); }
