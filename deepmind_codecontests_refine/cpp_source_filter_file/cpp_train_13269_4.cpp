#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
int a[N], b[N], ans[N];
int main() {
  int n, mx = 0, mxx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mxx = max(mxx, x);
    ans[i] = b[x] + 1;
    b[x]++;
    mx = max(mx, b[x]);
  }
  for (int i = 1; i < N; i++)
    if (b[i] < b[i - 1]) return cout << -1, 0;
  cout << mx << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
