#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, y, x, k, n, sum1 = 0, sum2 = 0;
  vector<int> a, sums1, sums2, ans;
  cin >> n;
  sums1.push_back(0);
  sums2.push_back(0);
  a.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> x;
    sum1 += x;
    a.push_back(x);
    sums1.push_back(sum1);
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= n; i++) {
    sum2 += a[i];
    sums2.push_back(sum2);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> k >> x >> y;
    if (k == 1)
      ans.push_back(sums1[y] - sums1[x - 1]);
    else
      ans.push_back(sums2[y] - sums2[x - 1]);
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}
