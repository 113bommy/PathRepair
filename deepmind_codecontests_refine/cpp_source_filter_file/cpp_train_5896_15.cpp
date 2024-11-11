#include <bits/stdc++.h>
using namespace std;
ifstream in("text.in");
ofstream out("text.out");
multiset<int> mst;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, ans = 0;
  cin >> n;
  mst.insert(0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (mst.find(x) != mst.end()) {
      mst.erase(mst.find(x));
      mst.insert(i);
    } else {
      ++ans;
      mst.insert(x);
    }
  }
  cout << ans;
  return 0;
}
