#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  vector<pair<int, int>> v1;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    v1.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end(), sortbysec);
  int fl = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] != v1[i]) {
      fl = 1;
      break;
    }
  }
  if (fl == 1)
    cout << "Happy Alex";
  else
    cout << "Poor Alex";
}
