#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[300001];
bool comp(pair<int, int> x, pair<int, int> y) { return x.second > y.second; }
bool comp1(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
int b[600001];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> x;
  vector<pair<int, int>> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    b[a[i].first] = i + 1;
    if (a[i].first > a[i].second)
      x.push_back({a[i].first, a[i].second});
    else
      y.push_back({a[i].first, a[i].second});
  }
  if (x.size() > y.size()) {
    sort(x.begin(), x.end(), comp1);
    cout << x.size() << '\n';
    for (int i = 0; i < x.size(); i++) {
      cout << b[x[i].first] << ' ';
    }
  } else {
    sort(y.begin(), y.end(), comp);
    cout << y.size() << '\n';
    for (auto next : y) {
      cout << b[next.first] << '\n';
    }
  }
}
