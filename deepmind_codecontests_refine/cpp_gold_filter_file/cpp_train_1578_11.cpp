#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> tiles(n);
  int cnt1 = 0, cnt2 = 0;
  for (int& x : tiles) {
    cin >> x;
    cnt1 += x == 1;
    cnt2 += x == 2;
  }
  bool ok = 0;
  if (cnt2 && cnt1) {
    cout << "2 1";
    ok = true;
    --cnt2;
    --cnt1;
  }
  for (int i = (ok ? 2 : 0); i < n; ++i) {
    if (cnt2) {
      cout << " 2";
      --cnt2;
    } else {
      cout << " 1";
      --cnt1;
    }
  }
  cout << "\n";
}
