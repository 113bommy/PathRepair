#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const double EPS = 1e-6;
const double PI = 3.1415926535;
const int MOD = 1000003;
void delCh(string &s, char ch) {
  for (int f = s.find(ch, 0); f != -1; f = s.find(ch, 0)) s.erase(f, 1);
}
int f(string s) {
  int i;
  for (i = 1; i < s.size() && s[i - 1] == s[i]; ++i)
    ;
  if (i == s.size()) return 0;
  for (i = 1; i < s.size() && s[i - 1] > s[i]; ++i)
    ;
  if (i == s.size()) return 1;
  return 2;
}
string names[100],
    text[3] = {
        "If you want to call a taxi, you should call: ",
        "If you want to order a pizza, you should call: ",
        "If you want to go to a cafe with a wonderful girl, you should call: "};
int main() {
  vector<vector<pair<int, int> > > v(3);
  int n, k;
  string s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k >> names[i];
    vector<int> cnt(3);
    for (int j = 0; j < k; ++j) {
      cin >> s;
      delCh(s, '-');
      ++cnt[f(s)];
    }
    for (int j = 0; j < 3; ++j) v[j].push_back(make_pair(cnt[j], n - i));
  }
  for (int i = 0; i < 3; ++i) {
    sort(v[i].begin(), v[i].end());
    cout << text[i] << names[n - v[i][n - 1].second];
    for (int j = n - 1 - 1; j >= 0; --j)
      if (v[i][j].first == v[i][n - 1].first)
        cout << ", " << names[n - v[i][j].second];
    cout << ".\n";
  }
  return 0;
}
