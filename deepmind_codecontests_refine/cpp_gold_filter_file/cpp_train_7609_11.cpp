#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vt;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    vt.push_back(v);
  }
  sort(vt.begin(), vt.end());
  int ans = 0;
  int prev = vt[0];
  for (int i = 1; i < n; i++) {
    int cur = vt[i];
    int diff = cur - prev;
    if (diff > 1) {
      ans += (diff - 1);
    }
    prev = cur;
  }
  cout << ans;
  return 0;
}
