#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int b = (2 * n) / 2;
    int a = (2 * n) / 2 + 1;
    cout << abs(v[a] - v[b]);
    cout << endl;
  }
  return 0;
}
