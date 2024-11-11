#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < (int)n; ++i) cin >> a[i];
  int ans = -100000;
  for (int i = 0; i < (int)n; ++i)
    for (int j = i + 1; j < n; ++j) {
      vector<int> cur;
      int sum = 0;
      for (int k = i; k < j; ++k) cur.push_back(a[k]);
      vector<int> tmp;
      for (int k = 0; k < i; ++k) tmp.push_back(a[k]);
      for (int k = j; k < n; ++k) tmp.push_back(a[k]);
      sort(tmp.rbegin(), tmp.rend());
      int l = min((int)tmp.size(), K);
      for (int k = 0; k < (int)l; ++k) cur.push_back(cur[k]);
      sort(cur.rbegin(), cur.rend());
      for (int k = 0; k < (int)j - i; ++k) sum += cur[k];
      ans = max(ans, sum);
    }
  cout << ans << endl;
  return 0;
}
