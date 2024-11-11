#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(make_pair(a, i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
}
