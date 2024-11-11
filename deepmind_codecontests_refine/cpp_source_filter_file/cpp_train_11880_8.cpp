#include <bits/stdc++.h>
using namespace std;
int n, x, parent[10005];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> x;
    parent[i] = x;
  }
  for (int i = n; i >= 1;) {
    v.push_back(i);
    i = parent[i];
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
