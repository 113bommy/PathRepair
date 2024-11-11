#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'A']++;
  }
  for (int i = 0; i < k; ++i) {
    ans = min(ans, cnt[i]);
  }
  cout << ans * k << endl;
}
