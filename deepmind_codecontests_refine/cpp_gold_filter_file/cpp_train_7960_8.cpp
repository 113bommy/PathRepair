#include <bits/stdc++.h>
using namespace std;
const long long maxn = 6e6;
const long long mod = 3e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, i, j, k;
  cin >> n;
  string ch[] = {"2", "3", "322", "5", "53", "7", "7222", "7332"};
  string ans = "", x;
  cin >> x;
  for (char c : x)
    if ((c - '0') > 1) ans += (ch[(c - '0') - 2]);
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans;
}
