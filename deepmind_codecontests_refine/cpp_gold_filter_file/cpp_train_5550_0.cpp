#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, x;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back({x, i + 1});
  }
  sort(v.begin(), v.end());
  cout << (v.size() + 1) / 2 << '\n';
  for (int i = 0; i < n; i += 2) {
    cout << v[i].second << " ";
  }
  cout << '\n';
  cout << v.size() / 2 << '\n';
  for (int i = 1; i < n; i += 2) {
    cout << v[i].second << " ";
  }
  return 0;
}
