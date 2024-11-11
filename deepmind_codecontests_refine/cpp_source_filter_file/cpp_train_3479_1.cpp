#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
int m;
vector<int> B(100005);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m;
  int mx = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    B[x]++;
    mx = max(mx, x);
  }
  int res = 1;
  for (int i = mx - 1; i; i--) {
    if (B[i] >= 2)
      res += 2;
    else
      res++;
  }
  cout << res << endl;
  for (int i = 1; i < mx; i++) {
    if (B[i] >= 1) cout << i << " ";
  }
  cout << mx << " ";
  for (int i = mx - 1; i; i--) {
    if (B[i] >= 2) cout << i << " ";
  }
  return 0;
}
