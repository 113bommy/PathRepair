#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int M = 1e9 + 7;
const double eps = 1e-6;
const double PI(acos(-1.0));
int n, k;
int a[N];
pair<int, int> v[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = (1); i <= (n); i++) {
    cin >> v[i].first;
  }
  for (int i = (1); i <= (n); i++) {
    cin >> v[i].second;
  }
  sort(v + 1, v + 1 + n, [](pair<int, int> a, pair<int, int> b) {
    return a.first - a.second < b.first - b.second;
  });
  int t = 0;
  for (int i = (1); i <= (n); i++) {
    if (i <= k) {
      t += v[i].first;
    } else {
      if (v[i].first < v[i].second)
        t += v[i].first;
      else
        t += v[i].second;
    }
  }
  cout << t << "\n";
}
