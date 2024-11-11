#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  string s;
  char c;
  cin >> n >> k >> s;
  vector<bool> let(26, 0);
  for (int i = 0; i < k; i++) {
    cin >> c;
    let[c - 'a'] = 1;
  }
  long long cnt = 0, ans = 0;
  for (char c : s) {
    if (let[c - 'a'])
      cnt++;
    else {
      ans += cnt * (cnt + 1) / 2;
      cnt = 0;
    }
  }
  ans += cnt * (cnt + 1) / 2;
  cout << ans << endl;
  return 0;
}
