#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<long long, long long>& a,
         const pair<long long, long long>& b) {
  return a.second < b.second;
};
struct compare {
  bool operator()(const int& l, const int& r) { return l > r; }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char, pair<int, int> > m;
  bool yes = 1;
  for (int i = 0; i < s.size(); i++) {
    if (m.find(s[i]) == m.end())
      m[s[i]] = {i, 0};
    else
      m[s[i]] = {m[s[i]].first, i};
  }
  for (int i = 0; i < s.size(); i++) {
    if (i == m[s[i]].first) {
      if (k > 0)
        k--;
      else {
        yes = 0;
        break;
      }
    }
    if (i == m[s[i]].second) k++;
  }
  if (yes)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
