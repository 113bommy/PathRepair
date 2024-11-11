#include <bits/stdc++.h>
using namespace std;
string s1, s2;
vector<vector<int>> cnt1, cnt2;
bool check(int b1, int e1, int b2, int e2) {
  bool ok = true;
  for (int i = b1; i <= e1; ++i) {
    if (s1[i - 1] != s2[i + b2 - b1 - 1]) {
      ok = false;
      break;
    }
  }
  if (ok) return true;
  if (e1 == b1 or ((e1 - b1 + 1) & 1)) return false;
  vector<int> c1_1(26), c1_2(26), c2_1(26), c2_2(26);
  int m1 = (b1 + e1) / 2, m2 = (b2 + e2) / 2;
  for (int i = 0; i < 26; ++i) {
    c1_1[i] = cnt1[i][m1] - cnt1[i][b1 - 1];
    c2_1[i] = cnt2[i][m2] - cnt2[i][b2 - 1];
    c1_2[i] = cnt1[i][e1] - cnt1[i][m1];
    c2_2[i] = cnt2[i][e2] - cnt2[i][m2];
  }
  if (c1_1 == c2_1 and c1_2 == c2_2) {
    if (check(b1, m1, b2, m2) and check(m1 + 1, e1, m2 + 1, e2)) return true;
  }
  if (c1_1 == c2_2 and c1_2 == c2_1) {
    if (check(b1, m1, m2 + 1, e2) and check(m1 + 1, e1, b2, m2)) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s1 >> s2;
  int n = s1.size();
  cnt1 = vector<vector<int>>(26, vector<int>(n + 1));
  cnt2 = vector<vector<int>>(26, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    ++cnt1[s1[i] - 'a'][i + 1];
    ++cnt2[s2[i] - 'a'][i + 1];
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 1; j <= n; ++j) {
      cnt1[i][j] += cnt1[i][j - 1];
      cnt2[i][j] += cnt2[i][j - 1];
    }
  }
  if (check(1, n, 1, n))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
