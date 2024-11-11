#include <bits/stdc++.h>
using namespace std;
string qry(int l1, int r1, int l2, int r2) {
  cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << "\n";
  while (l1 <= r1) cout << l1++ << " ";
  cout << "\n";
  while (l2 <= r2) cout << l2++ << " ";
  cout << "\n";
  cout.flush();
  string ans;
  cin >> ans;
  return ans;
}
void answer(int ans) {
  cout << "! " << ans << "\n";
  cout.flush();
}
int T, N, K;
void solve() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> N >> K;
  vector<int> ask;
  for (int i = 2; i <= N; i++) ask.push_back(i);
  shuffle(ask.begin(), ask.end(), rng);
  int pos = 0;
  while (pos < min(25, (int)ask.size())) {
    string q = qry(1, 1, ask[pos], ask[pos]);
    if (q == "SECOND") {
      answer(1);
      return;
    }
    pos++;
  }
  int x = 1;
  while (1) {
    int nx = min(N, 2 * x);
    string q = qry(1, x, x + 1, nx);
    if (q == "EQUAL")
      x = nx;
    else
      break;
  }
  int l = x + 1, r = min(2 * x, N);
  while (l < r) {
    int m = (l + r + 1) / 2;
    int tm = m - x;
    string q = qry(1, tm, x + 1, m);
    if (q == "EQUAL")
      l = m;
    else
      r = m - 1;
  }
  answer(l + 1);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
