#include <bits/stdc++.h>
using namespace std;
int l = -1, r = -1;
string s1, s2, rs1, rs2;
vector<int> z1, z2, z3, pre;
void inline z_init(string s, vector<int> &z) {
  z.resize(s.size());
  fill(z.begin(), z.end(), 0);
  for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
    i <= r && (z[i] = min(z[i - l], r - i + 1));
    for (; i + z[i] < s.size() && s[z[i]] == s[i + z[i]]; ++z[i])
      ;
    i + z[i] - 1 > r && (l = i, r = i + z[i] - 1);
  }
}
void inline kmp_init(string s, vector<int> &l) {
  l.resize(s.size());
  fill(l.begin(), l.end(), 0);
  for (int i = 1, k = 0; i < s.size(); ++i) {
    for (; k && s[i] != s[k]; k = l[k - 1])
      ;
    k += s[i] == s[k];
    l[i] = k;
  }
}
int main() {
  ios::sync_with_stdio(0);
  getline(cin, s1);
  getline(cin, s2);
  if (s1.size() != s2.size()) {
    cout << l << ' ' << r << '\n';
    return 0;
  }
  rs1 = s1, rs2 = s2;
  reverse(rs1.begin(), rs1.end()), reverse(rs2.begin(), rs2.end());
  z_init(s1 + '#' + rs2, z1);
  kmp_init(rs1 + '#' + s2, z2);
  z_init(s2 + '#' + s1, z3);
  for (int i = 0; i < rs2.size(); ++i) {
    z1[i] = z1[i + s1.size() + 1];
  }
  z1.resize(rs2.size());
  for (int i = 0; i < s2.size(); ++i) {
    z2[i] = z2[i + rs1.size() + 1];
  }
  z2.resize(s2.size());
  for (int i = 0; i < s1.size(); ++i) {
    z3[i] = z3[i + s2.size() + 1];
  }
  z3.resize(s1.size());
  pre = z2;
  for (int i = 1; i <= pre.size() - 1; ++i) {
    pre[i] = max(pre[i], pre[i - 1]);
  }
  for (int l1 = 1; l1 <= min(z1[0], (int)s2.size() - 1); ++l1) {
    int l2 = pre[s2.size() - l1 - 1], l3 = max(0, (int)s2.size() - l1 - l2);
    if (l2 && z3[l1] >= l3) {
      int cl = l1 - 1, cr = l1 + l3;
      if (cl > l) {
        l = cl, r = cr;
      }
    }
  }
  cout << l << ' ' << r << '\n';
}
