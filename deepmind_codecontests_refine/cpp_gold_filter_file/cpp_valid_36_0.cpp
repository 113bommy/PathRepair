#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
const int MOD = 1e9 + 7;
string go(int n, char c) {
  assert(c <= 'z');
  if (n == 1) {
    string ret = "";
    c++;
    ret += c;
    return ret;
  }
  vector<int> v;
  int i = 1;
  while (n) {
    if (n % 2) {
      v.push_back(i);
    }
    n /= 2;
    i *= 2;
  }
  int nxt = 0;
  string pre = "";
  string suf = "";
  for (int x : v) {
    if (x == 1) {
      nxt += 1;
      continue;
    }
    int y = x / 2;
    for (int i = 0; i < y; i++) pre += c;
    for (int i = 1; i < y; i++) suf = c + suf;
    assert(((y + y - 1) & x) == 0);
    nxt += 1;
    c++;
  }
  string sep = go(nxt, c);
  string ret = pre;
  ret += sep;
  ret += suf;
  return ret;
}
void solve() {
  int n;
  cin >> n;
  string ans = go(n, 'a');
  assert(ans.size() == n);
  cout << ans << endl;
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
