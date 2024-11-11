#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> vec(n), v;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  for (int i = n - 1; i > 0; i--) {
    v.push_back(max(vec[i], vec[i - 1]));
  }
  if (v.empty()) {
    sort(v.begin(), v.end());
    cout << min(v[0], min(vec[0], vec[n - 1])) << "\n";
  } else
    cout << vec[0] << "\n";
}
