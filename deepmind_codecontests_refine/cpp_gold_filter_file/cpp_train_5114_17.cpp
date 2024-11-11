#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int y, a, b, c, i, t, j, n, d, e;
  bool flag;
  long long int cnt = 0;
  string s;
  vector<pair<long long int, long long int>> v;
  unordered_map<char, int> mp;
  unordered_map<int, int> mp1;
  long long int o[200001];
  long long int p[101];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (i = 2; i <= n - 1; i++) {
    if (p[i - 1] == 1 && p[i + 1] == 1 && p[i] == 0) {
      v.push_back(make_pair(i - 1, i + 1));
    }
  }
  if (v.size() > 0) v[v.size()].first = 9;
  for (i = 0; i < v.size(); i++) {
    if (v[i].second == v[i + 1].first) {
      i++;
      cnt++;
    } else
      cnt++;
  }
  cout << cnt;
}
