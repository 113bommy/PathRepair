#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932385;
const long double E = 2.71828182845904523536;
const long long mod = 1e9 + 7;
const long long eps = 1e-15;
const long long inf = 1e15;
int frq[500];
set<char> se;
queue<char> q;
vector<char> v;
vector<char> ans;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    frq[s[i]]++;
    q.push(s[i]);
    se.insert(s[i]);
  }
  for (auto c : se) {
    while (v.size() && v.back() <= c) {
      ans.push_back(v.back());
      v.pop_back();
    }
    while (frq[c] && q.size()) {
      char x = q.front();
      q.pop();
      frq[x]--;
      if (x == c)
        ans.push_back(c);
      else
        v.push_back(x);
    }
  }
  for (auto x : ans) cout << x;
  reverse(v.begin(), v.end());
  for (auto x : v) cout << x;
  return 0;
}
