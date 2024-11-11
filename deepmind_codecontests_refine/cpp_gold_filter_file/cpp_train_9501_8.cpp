#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> div;
  int k = 1;
  int cnt = 0;
  int j = 0;
  while (j < (n - 1)) {
    cnt++;
    if (s[j + 1] != s[j]) {
      j++;
      break;
    } else {
      j++;
    }
  }
  string str = s.substr(0, cnt);
  s += str;
  int z = s.size();
  s += "0";
  for (int i = j; i < z; i++) {
    if (s[i + 1] != s[i]) {
      div.push_back(k);
      k = 1;
    } else {
      k++;
    }
  }
  int x = div.size();
  int ans = 0;
  for (int i = 0; i < x; i++) {
    ans += (div[i] / 3);
  }
  if (x == 1 && ans > 0 && div[0] % 3 != 0) {
    ans++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
