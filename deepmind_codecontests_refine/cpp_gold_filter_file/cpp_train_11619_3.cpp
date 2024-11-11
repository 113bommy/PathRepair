#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int arr[10005];
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    if (x <= r && x >= l) {
      int curr_pos = x - l;
      int gt = 0, lt = 0;
      for (int j = l; j <= r; j++) {
        if (arr[j] > arr[x]) gt++;
        if (arr[j] < arr[x]) lt++;
      }
      if (lt == curr_pos)
        cout << "Yes\n";
      else
        cout << "No\n";
    } else
      cout << "No\n";
  }
}
