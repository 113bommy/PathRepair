#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, b;
  cin >> n;
  vector<pair<int, int> > q;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    q.push_back(make_pair(a, b));
  }
  map<int, int> sum, diff;
  vector<pair<int, int> >::iterator it;
  for (i = 0; i != q.size(); i++) {
    sum[q[i].first + q[i].second]++;
    diff[q[i].first - q[i].second]++;
  }
  int sum2 = 0;
  map<int, int>::iterator x, y;
  for (x = sum.begin(); x != sum.end(); x++) {
    sum2 += ((x->second) * (x->second - 1)) / 2;
  }
  for (x = diff.begin(); x != diff.end(); x++) {
    sum2 += ((x->second) * (x->second - 1)) / 2;
  }
  cout << sum2;
}
