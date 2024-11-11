#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  int ans = 1e9;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (auto i : arr) {
    int b, a = 0;
    while (i--) {
      cin >> b;
      a += b * 5 + 20;
    }
    ans = min(ans, a);
  }
  cout << ans << endl;
}
