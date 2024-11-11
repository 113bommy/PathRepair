#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> v(n), ind(n, 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[j] > v[i]) ind[i]++;
    }
  }
  for (auto i : ind) {
    cout << i << ' ';
  }
}
