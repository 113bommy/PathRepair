#include <bits/stdc++.h>
using namespace std;
string lt = "abcde";
bool Sort(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  if (a.first - a.second < b.first - b.second) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<string> v;
    string s;
    for (long long int i = 1; i <= n; i++) {
      cin >> s;
      v.push_back(s);
    }
    long long int mx = 0;
    for (long long int i = 0; i < 4; i++) {
      long long int cn = 0, ot = 0;
      vector<pair<long long int, long long int> > v1;
      long long int c = 0;
      for (long long int j = 0; j < n; j++) {
        s = v[j];
        long long int c1 = 0, c2 = 0;
        for (long long int k = 0; k < v[j].size(); k++) {
          if (v[j][k] == lt[i])
            c1 += 1;
          else
            c2 += 1;
        }
        if (c1 > c2) {
          cn += c1;
          ot += c2;
          c += 1;
        } else {
          v1.push_back(make_pair(c1, c2));
        }
      }
      sort(v1.begin(), v1.end(), Sort);
      for (long long int j = 0; j < v1.size(); j++) {
        if (cn + v1[j].first > ot + v1[j].second) {
          c += 1;
          cn += v1[j].first;
          ot += v1[j].second;
        }
      }
      mx = max(mx, c);
    }
    cout << mx << '\n';
  }
}
