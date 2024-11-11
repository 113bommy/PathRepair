#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  {
    long long n, i, c, sum;
    cin >> n;
    long long arr[n + 1];
    for (i = 0; i < n; i++) cin >> arr[i];
    string ans;
    ans = "";
    for (i = 0; i < n - 1;) {
      if (arr[i] == 0) {
        ans += "R";
        i++;
        continue;
      } else if (arr[i] > 0) {
        ans += "P";
        arr[i]--;
      }
      if (arr[i] > 0) {
        if (arr[i + 1] > 0) {
          ans += "RPL";
          arr[i + 1]--;
        } else
          ans += "RL";
      } else {
        ans += "R";
      }
      if (arr[i] == 0) i++;
    }
    while (arr[n - 1]) {
      if (arr[n - 1] > 0) {
        ans += "P";
        arr[n - 1]--;
      }
      if (arr[n - 1] > 0) {
        ans += "LR";
      }
    }
    cout << ans;
  }
  cerr << " Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s \n";
  return 0;
}
