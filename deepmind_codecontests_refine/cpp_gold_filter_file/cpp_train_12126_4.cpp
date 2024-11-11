#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double pi = acos(-1.0);
set<long long> st[40];
stack<char> ans;
long long par[40];
bool vis[40];
bool marked[40];
long long flag = 0;
map<long long, long long> f;
void check_cycle(long long node) {
  vis[node] = true;
  marked[node] = true;
  if (st[node].size() > 0) {
    for (auto& x : st[node]) {
      if (vis[x] == false) {
        par[x] = node;
        check_cycle(x);
      } else if (marked[x]) {
        flag = 1;
      }
    }
  }
  marked[node] = false;
  if (f[node] == 0) {
    ans.push(char(node + 'a'));
    f[node]++;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    string s[n + 1];
    for (long long i = 0; i < n; i += 1) cin >> s[i];
    set<long long> v;
    for (char c = 'a'; c <= 'z'; c++) {
      st[c - 'a'].clear();
    }
    for (long long i = 1; i < n; i++) {
      long long j = 0;
      for (j; j < s[i].length(); j++) {
        if (j < s[i - 1].length() && s[i][j] != s[i - 1][j]) {
          v.insert(s[i - 1][j] - 'a');
          v.insert(s[i][j] - 'a');
          st[s[i - 1][j] - 'a'].insert(s[i][j] - 'a');
          break;
        }
      }
      if (j >= s[i].length() && j < s[i - 1].length()) {
        return cout << "Impossible", 0;
      }
    }
    memset(vis, false, sizeof(vis));
    memset(marked, false, sizeof(marked));
    for (auto& x : v) {
      if (!vis[x]) {
        flag = 0;
        check_cycle(x);
        if (flag) {
          return cout << "Impossible", 0;
        }
      }
    }
    while (ans.size() > 0) {
      cout << ans.top();
      ans.pop();
    }
    for (char a = 'a'; a <= 'z'; a++) {
      if (v.count(a - 'a') == 0) {
        cout << a;
      }
    }
  }
  return 0;
}
