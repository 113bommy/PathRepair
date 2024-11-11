#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;
long long maxn = LONG_LONG_MIN;
long long minn = LONG_LONG_MAX;
int32_t main(int argc, char* argv[]) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int test;
  cin >> test;
  while (test-- > 0) {
    string s;
    cin >> s;
    string str;
    cin >> str;
    map<char, int> work;
    for (int i = 0; i < s.length(); i++) {
      work[s[i]] = i;
    }
    int ans, dem = 0;
    for (int i = 0; i < (int)str.length() - 1; i++) {
      ans += abs(work[str[i]] - work[str[i + 1]]);
    }
    cout << ans << '\n';
  }
  return 0;
}
