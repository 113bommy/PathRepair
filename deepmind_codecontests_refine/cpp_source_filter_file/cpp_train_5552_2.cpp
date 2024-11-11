#include <bits/stdc++.h>
using namespace std;
bool sortbysec(pair<int, int> &x, pair<int, int> &y) {
  if (x.second == y.second)
    return (x.first > y.second);
  else
    return (x.second > y.second);
}
int main() {
  int n, x, y, c = 1, sum = 0;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end(), sortbysec);
  vector<pair<int, int> >::iterator it;
  for (int i = 0; i < n; i++) {
    if (c == 0) break;
    c--;
    c += v[i].second;
    sum += v[i].first;
  }
  cout << sum;
}
