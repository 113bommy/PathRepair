#include <bits/stdc++.h>
using namespace std;
int inf = 1000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    ans += a[int(s[i] - '0')];
  }
  cout << ans;
  return 0;
}
