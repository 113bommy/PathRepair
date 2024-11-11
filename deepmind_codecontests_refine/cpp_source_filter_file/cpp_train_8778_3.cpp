#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(make_pair(x, y));
  }
  sort(a.begin(), a.end(), sortbysec);
  long long second = 0;
  int i = m - 1;
  while (n > 0 && i > 0) {
    second += (n <= a[i].first ? n : a[i].first) * a[i].second;
    n -= a[i].first;
    i--;
  }
  cout << second << endl;
  return 0;
}
