#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n, a, b, ans = 0, len, i, cnt;
  cin >> n;
  int arr[n + 5];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cnt = 2;
  for (i = 0; i < n; i++) {
    if (arr[i] == 1) {
      ans++;
      if (cnt < 2) ans += cnt;
      cnt = 0;
    } else {
      cnt++;
    }
  }
  cout << ans << endl;
}
