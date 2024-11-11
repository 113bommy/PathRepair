#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int waiT = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (waiT <= v[i]) {
        cnt++;
        waiT += v[i];
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
