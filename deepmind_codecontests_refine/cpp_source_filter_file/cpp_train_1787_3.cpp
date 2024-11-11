#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
const int INF = 1e9 + 9;
int n, r[N], ans;
string st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> st;
  n = st.size();
  fill(r, r + n + 1, n);
  for (int i = n - 1; i >= 0; i--) {
    r[i] = r[i + 1];
    for (int j = 1; i + 2 * j < r[i]; j++)
      if (st[i] == st[i + j] && st[i + j] == st[i + j * 2]) {
        r[i] = i + 2 * j;
        break;
      }
    ans += n - r[i];
  }
  cout << ans;
  return 0;
}
