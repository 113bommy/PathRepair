#include <bits/stdc++.h>
using namespace std;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, -1};
const int MOD = 1e9 + 7, N = 2e5 + 5;
const double pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool bazet = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') bazet = true;
    }
    if (!bazet)
      cout << n << endl;
    else {
      int l = 1e9, r = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') r = i;
        if (s[i] == '1') l = min(l, i);
      }
      int ans1 = r - 0;
      int ans2 = n - l;
      cout << max(ans1, ans2) * 2 << endl;
    }
  }
  return 0;
}
