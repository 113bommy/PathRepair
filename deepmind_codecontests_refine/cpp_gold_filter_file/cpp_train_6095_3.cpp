#include <bits/stdc++.h>
using namespace std;
char a[1234][1213];
vector<pair<int, int> > v;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      a[i][j] -= '0';
      if (a[i][j] == 1) v.push_back(make_pair(i, j));
    }
  }
  if (v.size() != 4) return cout << "No", 0;
  if (!(v[0].first == v[1].first && v[0].second == v[2].second &&
        v[2].first == v[3].first && v[1].second == v[3].second))
    return cout << "No", 0;
  for (int i = v[0].first + 1; i < v[2].first; ++i)
    for (int j = v[0].second; j <= v[0].second; ++j)
      if (a[i][j] != 2) return cout << "No", 0;
  for (int i = v[0].first; i <= v[0].first; ++i)
    for (int j = v[0].second + 1; j < v[1].second; ++j)
      if (a[i][j] != 2) return cout << "No", 0;
  for (int i = v[0].first + 1; i < v[2].first; ++i)
    for (int j = v[2].second; j <= v[2].second; ++j)
      if (a[i][j] != 2) return cout << "No", 0;
  for (int i = v[1].first; i <= v[1].first; ++i)
    for (int j = v[0].second + 1; j < v[1].second; ++j)
      if (a[i][j] != 2) return cout << "No", 0;
  for (int i = v[0].first + 1; i < v[2].first; ++i)
    for (int j = v[0].second + 1; j < v[1].second; ++j)
      if (a[i][j] != 4) return cout << "No", 0;
  cout << "Yes";
  return 0;
}
