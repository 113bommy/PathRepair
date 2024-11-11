#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
int n, m, id, points;
string name;
vector<vector<pair<int, string> > > res;
int main() {
  cin >> n >> m;
  res.resize(m + 1);
  for (int i = 0; i < int(n); ++i) {
    cin >> name >> id >> points;
    res[id].push_back(make_pair(points, name));
  }
  for (int i = int(1); i < int(m + 1); ++i) {
    sort(res[i].begin(), res[i].end());
    int Sz = res[i].size();
    if (Sz > 2) {
      if (res[i][Sz - 2].first == res[i][Sz - 3].first)
        cout << "?" << endl;
      else
        cout << res[i][Sz - 1].second << " " << res[i][Sz - 2].second << endl;
    } else if (Sz == 1)
      cout << "?" << endl;
    else
      cout << res[i][Sz - 1].second << " " << res[i][Sz - 2].second << endl;
  }
  return 0;
}
