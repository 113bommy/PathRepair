#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, a, c, sum = 0, i, rem, cnt = 0, f = 0;
  vector<long long int> v;
  cin >> n >> m;
  while (n--) {
    cin >> a >> c;
    sum += a;
    v.push_back(a - c);
  }
  if (sum <= m)
    cout << 0;
  else {
    rem = sum - m;
    sort(v.begin(), v.end(), greater<long long int>());
    for (i = 0; i < v.size(); i++) {
      rem -= v[i];
      cnt++;
      if (rem <= 0) {
        f = 1;
        cout << cnt;
        break;
      }
    }
    if (f == 0) cout << -1;
  }
  return 0;
}
