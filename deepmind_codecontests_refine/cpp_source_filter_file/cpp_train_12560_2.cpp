#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int find_no_A(int a, int b, int sa[]) {
  int la = a, ra = b + 1;
  while (la < ra) {
    int mid = (la + ra) >> 1;
    if (sa[b] - sa[mid - 1] == b - mid + 1)
      ra = mid;
    else
      la = mid + 1;
  }
  return b - la + 1;
}
int sa[N], sb[N];
int ta[N], tb[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int ls = s.length();
  int lt = t.length();
  s = '_' + s;
  t = '_' + t;
  for (int i = 1; i <= ls; i++) {
    if (s[i] == 'A')
      sa[i] = 1;
    else
      sb[i] = 1;
    sa[i] += sa[i - 1];
    sb[i] += sb[i - 1];
  }
  for (int i = 1; i <= lt; i++) {
    if (t[i] == 'A')
      ta[i] = 1;
    else
      tb[i] = 1;
    ta[i] += ta[i - 1];
    tb[i] += tb[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int nbs = sb[b] - sb[a - 1];
    int nbt = tb[d] - tb[c - 1];
    int nas, nat;
    if (nbs > nbt || ((nbt - nbs) & 1) ||
        (nas = find_no_A(a, b, sa)) < (nat = find_no_A(c, d, ta))) {
      cout << 0;
    } else {
      if (nbt == nbs && (nas - nat) % 3) {
        cout << 0;
      } else if (!nbs && nbt && nas - 1 < nat) {
        cout << 0;
      }
      cout << 1;
    }
  }
  cout << "\n";
  return 0;
}
