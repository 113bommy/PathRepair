#include <bits/stdc++.h>
using namespace std;
char s[100005][25];
int n, m, k, minn[100005], a[100005];
long long ans;
map<string, int> mp;
int main(int argc, const char* argv[]) {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    minn[i] = 2147483647;
    for (int j = 1; j <= x; j++) {
      int t;
      cin >> t;
      mp[s[t]] = i;
      minn[i] = min(minn[i], a[t]);
    }
  }
  for (int i = 1; i <= m; i++) {
    string str;
    cin >> str;
    ans += minn[mp[str]];
  }
  cout << ans << endl;
  return 0;
}
