#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    int arr[5], ans = 0, i, n;
    for (i = 1; i < 5; i++) cin >> arr[i];
    string s;
    cin >> s;
    for (i = 0; i < s.size(); i++) ans += arr[s[i] - '0'];
    cout << ans;
  }
  return 0;
}
