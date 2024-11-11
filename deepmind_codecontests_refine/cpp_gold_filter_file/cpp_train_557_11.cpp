#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> g(n);
  int sa = 0, sg = 0;
  string s = "";
  for (int i = 0; i < n; i++) cin >> a[i] >> g[i];
  for (int i = 0; i < n; i++) {
    if (abs((sa + a[i]) - sg) <= 500) {
      s += "A";
      sa += a[i];
    } else {
      s += "G";
      sg += g[i];
    }
  }
  if (abs(sa - sg) > 500)
    cout << -1;
  else
    cout << s;
  return 0;
}
