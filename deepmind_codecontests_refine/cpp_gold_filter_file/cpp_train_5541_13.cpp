#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int a[n + 10];
  string s[m + 10];
  map<string, int> cmp;
  vector<string> v;
  set<string> p;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
    cmp[s[i]]++;
    p.insert(s[i]);
  }
  for (auto i : p) v.push_back(i);
  long long mn = 0, mx = 0;
  vector<int> v1;
  for (int i = 0; i < v.size(); i++) v1.push_back(cmp[v[i]]);
  sort(v1.rbegin(), v1.rend());
  for (int i = 0; i < v1.size(); i++) mn = mn + v1[i] * a[i + 1];
  reverse(a + 1, a + n + 1);
  for (int i = 0; i < v1.size(); i++) mx = mx + a[i + 1] * v1[i];
  cout << mn << " " << mx;
}
