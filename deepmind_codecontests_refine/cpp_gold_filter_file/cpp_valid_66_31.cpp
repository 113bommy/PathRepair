#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void solve() {
  int k;
  cin >> k;
  cout << v[k - 1] << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i < 100000; i++) {
    if (i % 10 == 3) continue;
    if (i % 3 == 0) continue;
    v.push_back(i);
    if (v.size() == 1000) break;
  }
  for (int i = 0; i < t; i++) {
    solve();
  }
}
