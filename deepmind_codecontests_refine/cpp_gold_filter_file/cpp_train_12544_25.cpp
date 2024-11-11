#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 7;
const int Inf = 1e8 + 7;
const int tmp = 1e3;
vector<pair<pair<int, int>, int> > V;
inline bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first / tmp == b.first.first / tmp)
    return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    V.push_back(make_pair(make_pair(++x, ++y), i));
  }
  sort(V.begin(), V.end(), cmp);
  for (int i = 0; i < n; i++) cout << V[i].second << " ";
  cout << endl;
  return 0;
}
