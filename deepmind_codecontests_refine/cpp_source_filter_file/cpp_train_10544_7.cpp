#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
int n, k, x, b[mxn];
void solve() {
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> x;
    a.push_back(x);
  }
  set<int> s;
  for (int i = 0; i < (int)(k); ++i) {
    cin >> b[i];
    s.insert(b[i]);
  }
  long long ans = 1, tmp;
  vector<int>::iterator it;
  for (int i = 0; i < (int)(k); ++i) {
    s.erase(b[i]);
    it = find((a).begin(), (a).end(), b[i]);
    int idx = it - a.begin();
    bool lowOk = idx > 0 && !((s).find(a[idx - 1]) != (s).end());
    bool highOk =
        idx + 1 < int((a).size()) && !((s).find(a[idx + 1]) != (s).end());
    if (lowOk) {
      if (highOk) {
        tmp = 2;
      } else {
        tmp = 1;
      }
      a.erase(a.begin() + idx - 1);
    } else if (highOk) {
      tmp = 1;
      a.erase(a.begin() + idx + 1);
    } else
      tmp = 0;
    ans *= tmp;
    if (ans == 0) break;
  }
  ans %= 998244353;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int tCount = 1;
  cin >> tCount;
  for (int i = 1; i <= tCount; ++i) {
    solve();
  }
  return 0;
}
