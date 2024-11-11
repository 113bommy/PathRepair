#include <bits/stdc++.h>
using namespace std;
const int N = 101005;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> And(n + 1), Or(n + 1);
  for (int i = 2; i <= n; i++) {
    cout << "and 1 " << i << endl;
    cin >> And[i];
    cout << "or 1 " << i << endl;
    cin >> Or[i];
  }
  int a1 = 0, x = Or[2], a23;
  for (int i = 2; i <= n; i++) {
    a1 |= And[i];
    x &= Or[i];
  }
  cout << "and 2 3" << endl;
  cin >> a23;
  for (int i = 0; i < (int)(31); ++i) {
    int cur = (1 << i);
    if ((cur & x) == 0) continue;
    if ((cur & a23) == 0 && (cur & a1) == 0) a1 += cur;
  }
  vector<int> a(n);
  a.push_back(a1);
  for (int i = 2; i <= n; i++) {
    int tmp = (Or[i] - And[i]) ^ a1;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  cout << "finish " << a[k - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(9);
  solve();
  return 0;
}
