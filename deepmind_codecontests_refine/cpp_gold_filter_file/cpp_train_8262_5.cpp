#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void test_case() {
  int ans = 0;
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> h;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]]++;
  }
  for (auto x : h) {
    if (x.first != 0 && x.second > 2) {
      cout << "-1";
      return;
    } else if (x.first != 0 && x.second == 2)
      ans++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) test_case();
}
