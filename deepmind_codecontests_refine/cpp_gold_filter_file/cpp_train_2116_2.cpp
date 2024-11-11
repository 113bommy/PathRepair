#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s[105];
  set<char> ms;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  long long ans = 1;
  for (int i = 0; i < m; i++) {
    ms.clear();
    for (int j = 0; j < n; j++) ms.insert(s[j][i]);
    ans = ans * ms.size() % 1000000007;
  }
  cout << ans % 1000000007;
}
