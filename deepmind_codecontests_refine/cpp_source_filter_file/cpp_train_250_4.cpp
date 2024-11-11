#include <bits/stdc++.h>
using namespace std;
const int maxn = 222;
vector<int> v1, v2;
int a[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = -1000000000;
  for (int l = 1; l <= n; l++)
    for (int r = l; r <= n; r++) {
      int sum = 0;
      v1.clear();
      v2.clear();
      for (int i = 1; i < l; i++) v1.push_back(a[i]);
      for (int i = l; i <= r; i++) {
        v2.push_back(a[i]);
        sum += a[i];
      }
      for (int i = r + 1; i <= n; i++) v1.push_back(a[i]);
      sort(v1.begin(), v1.end());
      reverse(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      for (int i = 0; i < v1.size() && i < v2.size(); i++) {
        if (v2[i] >= v1[i]) break;
        sum += v1[i] - v2[i];
      }
      ans = max(ans, sum);
    }
  cout << ans << endl;
  cin >> n;
  return 0;
}
