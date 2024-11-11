#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  vector<int> cool;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    cool.push_back(v[i] - v[i - 1]);
  }
  sort(cool.begin(), cool.end());
  int ans = 1;
  for (int i = 1; i < n - 1; i++) {
    if (cool[i] != cool[i - 1]) break;
    ans++;
  }
  cout << cool[0] << " " << ans << endl;
}
