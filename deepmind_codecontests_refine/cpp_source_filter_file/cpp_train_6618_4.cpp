#include <bits/stdc++.h>
using namespace std;
string trim(string x) {
  x = x.substr(0, x.size() - 2);
  return (x);
}
void solve() {
  string me;
  cin >> me;
  int n;
  cin >> n;
  vector<string> names;
  map<string, int> mp1;
  while (n--) {
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4;
    int p = 0;
    string a, b;
    if (s4 == "post") {
      p = 5;
      a = s1;
      b = trim(s3);
    } else {
      cin >> s5;
      if (s5 == "wall")
        p = 15;
      else if (s5 == "post")
        p = 10;
      a = s1;
      b = trim(s4);
    }
    if (a == me)
      mp1[b] += p;
    else
      mp1[a] = 0;
    if (b == me)
      mp1[a] += p;
    else
      mp1[b] = 0;
  }
  vector<pair<int, string>> v;
  for (map<string, int>::iterator it = mp1.begin(); it != mp1.end(); it++) {
    string s = it->first;
    int p = -(it->second);
    v.push_back({p, s});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i].second << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) solve();
  return (0);
}
