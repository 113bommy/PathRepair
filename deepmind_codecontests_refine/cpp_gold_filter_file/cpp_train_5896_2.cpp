#include <bits/stdc++.h>
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
using namespace std;
int t[MAXN];
vector<int> ans;
multiset<int> s;
int n;
void dfs(int timer, int pos) {
  if (pos > n) return;
  if (s.find(t[pos]) == s.end())
    s.insert(timer);
  else {
    s.erase(s.find(t[pos]));
    s.insert(timer);
  }
  dfs(timer + 1, pos + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  ans.push_back(1);
  s.insert(0);
  dfs(1, 1);
  cout << s.size() << '\n';
  return 0;
}
