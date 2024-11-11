#include <bits/stdc++.h>
using namespace std;
void printer(string name, long long value) {
  cout << name << ":\t" << value << "\n";
}
long long tot, n, m;
long long a, b, c, d;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  string s, t;
  cin >> s;
  cin >> t;
  vector<pair<long long, long long> > ans;
  vector<long long> v[300], w[300];
  map<char, long long> x, y;
  for (long long i = 0; i < s.size(); ++i) {
    if (s[i] == '?')
      v[0].push_back(i);
    else
      v[s[i] - 'a' + 1].push_back(i);
  }
  for (long long i = 0; i < t.size(); ++i) {
    if (t[i] == '?')
      w[0].push_back(i);
    else
      w[t[i] - 'a' + 1].push_back(i);
  }
  long long c = 0, d = 0;
  for (long long i = 1; i < 'z' + 1; ++i) {
    long long a = 0, b = 0;
    while (a < v[i].size() && b < w[i].size()) {
      ans.push_back(make_pair(v[i][a], w[i][b]));
      a++;
      b++;
    }
    while (a < v[i].size() && d < w[0].size()) {
      ans.push_back(make_pair(v[i][a], w[0][d]));
      a++;
      d++;
    }
    while (c < v[0].size() && b < w[i].size()) {
      ans.push_back(make_pair(v[0][c], w[i][b]));
      b++;
      c++;
    }
  }
  while (c < v[0].size() && d < w[0].size()) {
    ans.push_back(make_pair(v[0][c], w[0][d]));
    c++;
    d++;
  }
  cout << ans.size() << "\n";
  for (long long i = 0; i < ans.size(); ++i) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  }
}
