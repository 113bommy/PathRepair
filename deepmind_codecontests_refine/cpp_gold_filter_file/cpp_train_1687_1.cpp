#include <bits/stdc++.h>
using namespace std;
const long long int MX = 2e5 + 10, inf = 1e18;
bool a[MX], mrk[MX];
vector<long long int> p, pre;
int main() {
  ios::sync_with_stdio(0);
  for (int i = 2; i < sqrt(MX); i++)
    if (!mrk[i])
      for (int j = i * i; j < MX; j += i) mrk[j] = 1;
  for (int i = 2; i < MX; i++)
    if (!mrk[i]) pre.push_back(i);
  long long int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) p.push_back(i);
  }
  long long int k = p.size();
  if (k == 1) {
    cout << -1;
    return 0;
  }
  long long int ans = inf;
  for (int t = 2; t <= k; t++) {
    if (k % t == 0) {
      long long int javab = 0;
      for (int i = 0; i < k / t; i++) {
        long long int z = p[i * t + t / 2];
        for (int j = i * t; j < (i + 1) * t; j++) javab += abs(z - p[j]);
      }
      ans = min(ans, javab);
    }
  }
  cout << ans << endl;
  return 0;
}
