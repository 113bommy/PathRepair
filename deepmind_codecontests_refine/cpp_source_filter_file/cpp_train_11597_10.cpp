#include <bits/stdc++.h>
using namespace std;
int n, s[112345];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<int> tmp_s(s, s + n);
  sort(tmp_s.begin(), tmp_s.end());
  int sz = (tmp_s.size() + 2) / 3;
  map<long long, long long> map_a, map_b;
  for (int i = 0; i < tmp_s.size(); ++i) {
    if (i < sz) {
      map_a[tmp_s[i]] = i;
      map_b[tmp_s[i]] = tmp_s[i] - i;
    } else if (i < sz * 2) {
      map_b[tmp_s[i]] = i;
      map_a[tmp_s[i]] = tmp_s[i] - i;
    } else {
      map_b[tmp_s[i]] = tmp_s.size() - i;
      map_a[tmp_s[i]] = tmp_s[i] - map_b[tmp_s[i]];
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; ++i) cout << map_a[s[i]] << " \n"[i + 1 == n];
  for (int i = 0; i < n; ++i) cout << map_b[s[i]] << " \n"[i + 1 == n];
}
