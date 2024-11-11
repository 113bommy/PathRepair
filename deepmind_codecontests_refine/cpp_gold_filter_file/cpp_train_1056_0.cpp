#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long LLINF = 1e18 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int n;
  string s;
  int mini = 0, maxi = 0, cur = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cur += s[i] == '-' ? -1 : 1;
    mini = min(mini, cur);
    maxi = max(maxi, cur);
  }
  cout << cur - mini;
}
