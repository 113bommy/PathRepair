#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<bool> aa(n);
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (x == '1') aa[i] = 1;
  }
  vector<int> ans(200, 0);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (aa[i]) {
      for (int j = 1; j < b; j++) ans[j]++;
      b += a;
    }
    while (b < 200) {
      for (int j = b; j < b + a && j < 200; j++) {
        ans[j]++;
      }
      b += a + a;
    }
  }
  int mx = 0;
  for (auto e : ans) mx = max(mx, e);
  cout << mx;
  return 0;
}
