#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const int n = 6;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
map<int, int> Map;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = -1;
  for (int i = 1; i < n; i++) {
    if (v[i] > ans + 1) {
      cout << i + 1 << "\n";
      return;
    } else
      ans = max(ans, v[i]);
  }
  cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
