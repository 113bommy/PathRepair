#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1200000;
int n, m;
int cnt[MAXN];
int a[MAXN];
long long gcd(long long a, long long b) {
  while (a > 0) {
    b %= a;
    swap(a, b);
  }
  return b;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] <= m) cnt[a[i]]++;
  }
  for (int i = m; i >= 1; --i) {
    for (int j = i + i; j <= m; j += i) cnt[j] += cnt[i];
  }
  int mi = 1;
  for (int i = 1; i <= m; ++i)
    if (cnt[i] >= cnt[mi]) mi = i;
  vector<int> ans;
  long long res = 1;
  for (int i = 0; i < n; ++i)
    if (mi % a[i] == 0) {
      ans.push_back(i + 1);
      res = res * a[i] / gcd(res, a[i]);
    }
  cout << res << " " << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  return 0;
}
