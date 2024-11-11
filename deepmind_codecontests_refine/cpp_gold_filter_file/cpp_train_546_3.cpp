#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, string>> v;
vector<long long> pos;
long long n;
int main() {
  cin >> n;
  long long p;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s >> p;
    v.push_back(make_pair(p, s));
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    if (v[i].first > i) {
      cout << "-1";
      return 0;
    }
  }
  long long x = 1e4;
  for (long long i = 0; i < v.size(); i++)
    pos.insert(pos.begin() + v[i].first, i);
  for (long long i = 0; i < v.size(); i++)
    cout << v[pos[i]].second << " " << x - v[pos[i]].first << endl;
  return 0;
}
