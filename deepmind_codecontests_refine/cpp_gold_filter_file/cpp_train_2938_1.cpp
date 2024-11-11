#include <bits/stdc++.h>
using namespace std;
vector<string> qry(int l, int r) {
  cout << "? " << l << " " << r << endl;
  vector<string> ret((r - l + 2) * (r - l + 1) / 2);
  for (auto &s : ret) {
    cin >> s;
    sort(s.begin(), s.end());
  }
  sort(ret.begin(), ret.end());
  return ret;
}
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<string> v1 = qry(1, n);
  if (n == 1) {
    cout << "! " << v1[0] << endl;
    exit(0);
  }
  vector<string> v2 = qry(1, n - 1);
  vector<string> v3;
  set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                 inserter(v3, v3.begin()));
  sort(v3.begin(), v3.end(), [](const string &s1, const string &s2) -> bool {
    return s1.length() < s2.length();
  });
  vector<int> cnt(26, 0);
  string res(n, 0);
  for (int i = 0; i < n; i++) {
    fill(cnt.begin(), cnt.end(), 0);
    for (auto c : v3[i]) cnt[c - 'a'] += 1;
    for (int j = 0; j < i; j++) cnt[res[n - j - 1] - 'a'] -= 1;
    for (int j = 0; j < 26; j++)
      if (cnt[j] > 0) res[n - i - 1] = (char)(j + 'a');
  }
  cout << "! " << res << endl;
  return 0;
}
