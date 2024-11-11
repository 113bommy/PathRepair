#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e6 + 5;
const int K = (1 << 17) + 10;
const long long int INF = 2e18 + 500;
const int inf = 2e9 + 500;
const int SQRT = 500;
const int lgN = 20;
long long int A[N];
vector<int> ans;
string response;
bool hasBranched = false;
void solve(int l, int r) {
  if (l > r) {
    return;
  }
  if (l == r) {
    ans.push_back(l);
    return;
  }
  int mid = (l + r) / 2;
  cout << "1 " << mid << ' ' << mid + 1 << endl;
  fflush(stdout);
  cin >> response;
  if (response == "TAK") {
    solve(l, mid);
  } else
    solve(mid + 1, r);
}
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  solve(1, n);
  if (ans[0] == n) {
    solve(1, n - 1);
    cout << "2 " << ans[1] << ' ' << ans[0] << endl;
    return 0;
  }
  if (ans[0] == 1) {
    solve(2, n);
    cout << "2 " << ans[0] << ' ' << ans[1] << endl;
    return 0;
  }
  solve(1, ans[0] - 1);
  solve(ans[0] + 1, n);
  assert(ans.size() > 2);
  if (ans[1] != ans[0] - 1) {
    cout << "2 " << ans[1] << ans[0] << endl;
    return 0;
  }
  if (ans[2] != ans[0] + 1) {
    cout << "2 " << ans[0] << ' ' << ans[2] << endl;
    return 0;
  }
  fflush(stdout);
  cout << "1 " << ans[0] - 1 << ' ' << ans[0] << endl;
  cin >> response;
  if (response == "TAK") {
    assert(ans[0] >= 2);
    cout << "2 " << ans[0] - 1 << ' ' << ans[0] << endl;
  } else {
    assert(ans[0] <= n);
    cout << "2 " << ans[0] << ' ' << ans[0] + 1 << endl;
  }
  return 0;
}
