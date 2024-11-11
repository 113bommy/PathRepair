#include <bits/stdc++.h>
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  bool flag = false;
  for (int i = 1; i < n - 1; i++) {
    if ((1ll * (a[i] - a[0]) * (a[i] - a[i + 1])) > 0) {
      cout << 3 << '\n';
      cout << 1 << " " << (i + 1) << " " << (i + 2) << '\n';
      flag = true;
      break;
    }
  }
  if (!flag) cout << 0 << '\n';
}
