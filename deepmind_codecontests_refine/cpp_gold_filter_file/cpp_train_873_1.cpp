#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<string> v;
  int tc = n;
  while (tc--) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  int ans = 0, i, j;
  for (i = 0; i < n; i++) {
    int cnt = 0;
    for (j = 0; j <= k; j++) {
      if (v[i].find(to_string(j)) != -1) cnt++;
    }
    if (cnt == k + 1) ans++;
  }
  cout << ans << endl;
}
