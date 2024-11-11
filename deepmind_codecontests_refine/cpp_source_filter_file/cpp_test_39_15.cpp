#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int ans[N], n, pos, last;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  last = n;
  for (int i = 1; i <= n; ++i) {
    cout << "? ";
    for (int j = 1; j < n; ++j) cout << 1 << " ";
    cout << i + 1 << endl;
    cout.flush();
    cin >> pos;
    if (pos == 0) break;
    ans[pos] = i;
  }
  for (int i = n; i > 1; --i) {
    cout << "? ";
    for (int j = 1; j < n; ++j) cout << n << " ";
    cout << i - 1 << endl;
    cout.flush();
    cin >> pos;
    if (!pos) {
      last = n - i + 1;
      break;
    }
    ans[pos] = i - n - 1;
  }
  cout << "! ";
  for (int i = 1; i <= n; ++i) cout << ans[i] + last << " ";
  cout << endl;
  return 0;
}
