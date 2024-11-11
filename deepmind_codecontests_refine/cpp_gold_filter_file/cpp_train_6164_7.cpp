#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
const long long mod = 1e9 + 7;
int fa[maxn];
int ans, n;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  fa[fx] = fy;
}
int main() {
  cin >> n;
  for (int i = 1; i <= 26; i++) fa[i] = i;
  vector<int> mp(30, 0);
  string s;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    mp[s[0] - 'a' + 1]++;
    for (int j = 1; j < s.size(); j++) {
      mp[s[j] - 'a' + 1]++;
      merge(s[j] - 'a' + 1, s[0] - 'a' + 1);
    }
  }
  for (int i = 1; i <= 26; i++) {
    if (mp[i] && fa[i] == i) {
      ++ans;
    }
  }
  cout << ans << "\n";
  return 0;
}
