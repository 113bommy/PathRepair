#include <bits/stdc++.h>
using namespace std;
long long vis[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  long long arr[n + 1], sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  memset(vis, 0, sizeof vis);
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      vis[a] -= sum;
      arr[a] = b;
    } else if (t == 2) {
      int c;
      cin >> c;
      sum += c;
    } else {
      int c;
      cin >> c;
      cout << (sum + arr[c] + vis[c]) << "\n";
    }
  }
  return 0;
}
