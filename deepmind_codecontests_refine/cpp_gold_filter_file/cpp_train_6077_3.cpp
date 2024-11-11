#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int f[100009];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(f, 0, sizeof(f));
  int ans;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vector<int> t;
    for (int j = 2; j * j <= x; j++)
      if (x % j == 0) {
        t.push_back(j);
        while (x % j == 0) x /= j;
      }
    if (x > 1) t.push_back(x);
    ans = 0;
    for (int j = 0; j < t.size(); j++) ans = max(ans, f[t[j]]);
    for (int j = 0; j < t.size(); j++) f[t[j]] = ans + 1;
  }
  ans = 1;
  for (int i = 0; i < 100009; i++) ans = max(ans, f[i]);
  cout << ans << endl;
}
