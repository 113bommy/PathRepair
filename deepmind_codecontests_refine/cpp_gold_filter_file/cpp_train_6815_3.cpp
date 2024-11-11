#include <bits/stdc++.h>
using namespace std;
int vis[1000010];
int main() {
  memset(vis, 0, sizeof(vis));
  int a, b, c = 1, pos = -1;
  string str;
  cin >> str;
  cin >> a >> b;
  int n = str.size(), i;
  int v[n];
  vector<int> v1, v2;
  for (i = 0; i < n; i++) {
    v[i] = str[i] - '0';
  }
  c = 0;
  for (i = 0; i < n; i++) {
    c = (((c % a) * (10 % a)) % a + v[i] % a) % a;
    if (c == 0) {
      if (i < n && v[i + 1] != 0) {
        vis[i + 1] = 1;
      }
    }
  }
  c = 0;
  int z = 1;
  for (i = n - 1; i >= 0; i--) {
    c = ((v[i] % b) * (z % b) + c % b) % b;
    if (c == 0) {
      if (v[i] != 0 && vis[i]) {
        pos = i;
        break;
      }
    }
    z = (z % b * 10 % b) % b;
  }
  if (pos == -1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (i = 0; i < n; i++) {
    cout << v[i];
    if (i == pos - 1) cout << endl;
  }
}
