#include <bits/stdc++.h>
using namespace std;
string t[101];
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  int ans = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = 0;
    for (int j = 0; j < n; j++) {
      if (t[i] == t[j]) {
        res++;
      }
    }
    ans = max(res, ans);
  }
  cout << res << '\n';
}
