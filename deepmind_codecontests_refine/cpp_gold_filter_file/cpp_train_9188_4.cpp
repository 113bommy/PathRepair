#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
long long a[2020202], b[2020202];
vector<long long> v;
pair<long long, long long> p[2020202];
map<long long, long long> mp;
set<pair<long long, long long> > st;
set<pair<long long, long long> >::iterator it;
string s;
long long q, t, n, m, k, z, x, y, cnt, sum, len, mx, bst, bsti;
long long ans[2020202];
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n - 1; i += 2) {
    cout << "? " << i << " " << i + 1 << endl;
    cin >> x;
    cout << "? " << i + 1 << " " << i << endl;
    cin >> y;
    if (x > y)
      ans[i] = x;
    else
      ans[i + 1] = y;
  }
  while (1) {
    v.clear();
    for (int i = 1; i <= n; i++)
      if (!ans[i]) v.push_back(i);
    if (v.size() <= 1) break;
    for (int i = 0; i < ((int)v.size()) - 1; i += 2) {
      cout << "? " << v[i] << " " << v[i + 1] << endl;
      cin >> x;
      cout << "? " << v[i + 1] << " " << v[i] << endl;
      cin >> y;
      if (x > y)
        ans[v[i]] = x;
      else
        ans[v[i + 1]] = y;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!ans[i]) {
      ans[i] = n;
    }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
