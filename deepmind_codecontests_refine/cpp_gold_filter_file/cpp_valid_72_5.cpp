#include <bits/stdc++.h>
using namespace std;
string ans, a;
int n, k;
bool go(int i, int n, int k, set<int> &s, int gr) {
  if (i == n) return true;
  int val = a[i] - '0';
  if (gr == 1) {
    int x = 0;
    if (s.size() == k) {
      x = (*s.begin());
    }
    ans.push_back((char)(x + '0'));
    int flag = 0;
    if (s.empty() == true || s.find(x) == s.end()) {
      s.insert(x);
    } else {
      flag = 1;
    }
    if (go(i + 1, n, k, s, gr) == true)
      return true;
    else {
      if (flag == 0) {
        s.erase(x);
      }
      ans.pop_back();
      return false;
    }
  }
  if (s.size() == k) {
    if (s.lower_bound(val) == s.end()) {
      return false;
    }
    int ins = (*s.lower_bound(val)) + '0';
    int nextgr = 0;
    nextgr = ((ins - '0') == val) ? 0 : 1;
    ans.push_back(ins);
    if (go(i + 1, n, k, s, nextgr) == true)
      return true;
    else {
      ans.pop_back();
      if (s.upper_bound(val) == s.end())
        return false;
      else {
        ans.push_back((*s.upper_bound(val)) + '0');
        if (go(i + 1, n, k, s, 1) == true)
          return true;
        else {
          ans.pop_back();
          return false;
        }
      }
    }
  }
  int flag = 0;
  ans.push_back(a[i]);
  if (s.empty() == true || s.find(val) == s.end())
    s.insert(val);
  else
    flag = 1;
  if (go(i + 1, n, k, s, gr) == true)
    return true;
  else {
    ans.pop_back();
    if (flag == 0) s.erase(val);
    int flag2 = 0;
    if (s.empty() == true || s.find((val + 1) % 10) == s.end())
      s.insert((val + 1) % 10);
    else
      flag2 = 1;
    ans.push_back((char)((val + 1) % 10 + '0'));
    if (go(i + 1, n, k, s, 1) == true)
      return true;
    else {
      ans.pop_back();
      if (flag2 == 0) s.erase((val + 1) % 10);
      return false;
    }
  }
}
void solve() {
  ans = "", a = "";
  cin >> n >> k;
  a = to_string(n);
  set<int> s;
  go(0, a.size(), k, s, 0);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
