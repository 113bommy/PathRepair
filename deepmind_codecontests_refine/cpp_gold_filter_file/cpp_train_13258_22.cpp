#include <bits/stdc++.h>
using namespace std;
bool sortp(const pair<int, int> a, const pair<int, int> b) {
  if (a.first > b.first)
    return 0;
  else if (a.first < b.first)
    return 1;
  else
    return a.second > b.second;
}
int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> b;
  vector<pair<int, int>> a;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    b.first = x;
    b.second = y;
    a.push_back(b);
  }
  sort(a.begin(), a.end(), sortp);
  int flag = 0;
  for (int i = 0; i < m; i++) {
    if (n <= a[i].first) {
      cout << "NO" << endl;
      flag = 1;
      break;
    } else {
      n += a[i].second;
    }
  }
  if (flag == 0) {
    cout << "YES" << endl;
  }
}
