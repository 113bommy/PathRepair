#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int ans = 0, c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] > v[i + 1]) {
      c += abs(v[i] - v[i + 1]);
      ans += abs(v[i] - v[i + 1]);
    }
  }
  cout << ans << endl;
}
