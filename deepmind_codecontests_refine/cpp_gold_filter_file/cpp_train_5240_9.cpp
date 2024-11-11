#include <bits/stdc++.h>
using namespace std;
const int lmt = 26;
const int lmt2 = 200005;
int bit[lmt][lmt2];
void update(int n, int idx, int val) {
  while (idx < lmt2) {
    bit[n][idx] += val;
    idx += idx & (-idx);
  }
}
int query(int n, int idx) {
  int ans = 0;
  while (idx > 0) {
    ans += bit[n][idx];
    idx -= idx & (-idx);
  }
  return ans;
}
int main() {
  int k, q, occ;
  char ch;
  string s, res = "";
  cin >> k;
  cin >> s;
  for (int i = 0; i < k; i++) res += s;
  for (int i = 0; i < res.size(); i++) update(res[i] - 'a', i + 1, 1);
  cin >> q;
  while (q--) {
    cin >> occ >> ch;
    int l = 1, r = lmt2 - 1, md;
    while (l < r) {
      md = (l + r) / 2;
      if (query(ch - 'a', md) >= occ)
        r = md;
      else
        l = md + 1;
    }
    res[l - 1] = '-';
    update(ch - 'a', l, -1);
  }
  string ans = "";
  for (int i = 0; i < res.size(); i++)
    if (res[i] != '-') ans += res[i];
  cout << ans << "\n";
  return 0;
}
