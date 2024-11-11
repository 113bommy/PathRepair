#include <bits/stdc++.h>
using namespace std;
string s[101];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  long long int ans = 1;
  for (int j = 0; j < m - 1; ++j) {
    int cnt[26] = {0};
    for (int i = 0; i < n; ++i) {
      cnt[s[i][j] - '0']++;
    }
    int num = 0;
    for (int i = 0; i < 26; ++i)
      if (cnt[i]) ++num;
    ans = (ans * num) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
