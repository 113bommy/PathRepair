#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, p, j, ans;
  map<long long int, long long int> m;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> p;
      if (p == 1 || p == 3) {
        m[i] = 1;
      }
      if (p == 2 || p == 3) {
        m[j] = 1;
      }
    }
  }
  ans = 0;
  vector<long long int> v;
  for (i = 0; i < n; i++) {
    ans += (m[i] == 0);
    if (m[i] == 0) v.push_back(i);
  }
  cout << ans << endl;
  for (auto x : v) {
    cout << x << " ";
  }
}
