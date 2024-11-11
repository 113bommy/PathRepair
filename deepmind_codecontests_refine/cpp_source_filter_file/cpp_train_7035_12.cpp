#include <bits/stdc++.h>
using namespace std;
bool issubsequence(string s1, string s2) {
  int l1, l2;
  l1 = s1.length();
  l2 = s2.length();
  int j = 0;
  for (int i = 0; i < l1; i++) {
    if (s1[i] == s2[j] && j < l2) j++;
    if (j == l2) return true;
  }
  return false;
}
bool check(string t, string p, int m, vector<int> &a) {
  for (int i = 0; i <= m; i++) {
    t[a[i] - 1] = '#';
  }
  return issubsequence(t, p);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  string t, p;
  cin >> t >> p;
  int length_of_t, length_of_p, l, h, m, res;
  length_of_t = t.length();
  length_of_p = p.length();
  vector<int> a(length_of_t);
  for (int i = 0; i < length_of_t; i++) cin >> a[i];
  l = 0;
  h = length_of_t - 1;
  res = INT_MIN;
  while (l <= h) {
    m = (l + h) / 2;
    if (check(t, p, m, a)) {
      l = m + 1;
      res = max(res, m + 1);
    } else {
      h = m - 1;
    }
  }
  cout << res << "\n";
  return 0;
}
