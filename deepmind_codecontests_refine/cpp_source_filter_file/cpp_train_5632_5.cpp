#include <bits/stdc++.h>
using namespace std;
int a[101];
map<int, int> cnt;
vector<int> f;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (auto x : cnt) f.push_back(x.second);
  int l = 1, h = 100, ans = 0;
  while (l < h) {
    int mid = (l + h) / 2;
    int days = 0;
    for (auto p : f) {
      days += p / mid;
    }
    if (days >= n) {
      ans = max(ans, mid);
      l = mid + 1;
    } else
      h = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
