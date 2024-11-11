#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> ans;
  bool bb = true;
  int p1 = 0, p2 = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (bb) {
      if (b[i] == a[p1]) {
        ans.push_back(1);
      }
      ans.push_back(i + 1);
      p1++;
      bb = !bb;
    } else {
      if (b[i] == a[p2]) {
        ans.push_back(1);
      }
      ans.push_back(i + 1);
      p2--;
      bb = !bb;
    }
  }
  cout << ans.size() << " ";
  for (auto i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
