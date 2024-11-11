#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 10;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(mxN);
  int mx = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
    mx = max(mx, a[i]);
  }
  vector<int> ans;
  for (int i = 0; i < 5000; i++) {
    if (b[i]) {
      ans.push_back(i);
      b[i]--;
    }
  }
  for (int i = mx - 1; i >= 0; i--) {
    if (b[i]) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
int main() {
  int t = 1;
  for (long long cas = 1; cas <= t; cas++) {
    solve();
  }
  return 0;
}
