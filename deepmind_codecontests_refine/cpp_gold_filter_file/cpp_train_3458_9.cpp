#include <bits/stdc++.h>
using namespace std;
long long int n, m;
long long int count(vector<long long int> &v, long long int idx) {
  map<long long int, long long int> reqd, shift;
  for (long long int i = 0, j = idx; i < n; i++, j += m) reqd[j] = i;
  for (long long int i = 0; i < v.size(); i++)
    if (reqd.find(v[i]) != reqd.end()) shift[(i - reqd[v[i]] + n) % n]++;
  long long int ans = n;
  for (long long int i = 0; i <= n; i++) {
    if (i >= ans) break;
    if (shift.count(i) > 0) ans = min(ans, i + n - shift[i]);
  }
  return ans;
}
int main() {
  cin >> n >> m;
  long long int ans = 0;
  vector<vector<long long int> > v(n, vector<long long int>(m));
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> v[i][j];
  for (long long int i = 0; i < m; i++) {
    vector<long long int> temp;
    for (long long int j = 0; j < n; j++) temp.push_back(v[j][i]);
    ans += count(temp, i + 1);
  }
  cout << ans << endl;
}
