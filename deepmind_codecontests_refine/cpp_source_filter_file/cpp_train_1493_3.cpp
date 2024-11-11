#include <bits/stdc++.h>
using namespace std;
struct seg {
  int l, r;
  seg inter(seg s) {
    if (r < s.l or s.r < l) return (seg){-1, -1};
    return (seg){max(l, s.l), min(r, s.r)};
  }
  int len() {
    if (l == -1) return 0;
    return r - l + 1;
  }
  bool operator<(seg s) const {
    if (l != s.l) return l < s.l;
    return r < s.r;
  }
};
vector<seg> explode(vector<seg> &s1, int mid) {
  vector<seg> ans;
  for (int i = (int)0; i < (int)s1.size(); i++) {
    if (s1[i].r < mid)
      ans.push_back(s1[i]);
    else if (s1[i].l <= mid) {
      seg p1 = (seg){s1[i].l, mid - 1};
      if (p1.l < p1.r) ans.push_back(p1);
      seg p2 = (seg){1, s1[i].r - mid};
      if (p2.l < p2.r) ans.push_back(p2);
    } else {
      seg x = (seg){s1[i].l - mid, s1[i].r - mid};
      ans.push_back(x);
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.size() == 1) return ans;
  vector<seg> res;
  int ini = 1, fin = mid - 1;
  int rgt = 0, lft = mid;
  for (int i = (int)0; i < (int)ans.size(); i++) {
    if (ini == ans[i].l) rgt = max(rgt, ans[i].r);
    if (fin == ans[i].r) lft = min(lft, ans[i].l);
  }
  seg _s1 = (seg){-1, -1};
  seg _s2 = (seg){-1, -1};
  if (ini < rgt) _s1 = (seg){ini, rgt};
  if (lft < fin) _s2 = (seg){lft, fin};
  if (ini == lft and rgt == fin)
    res.push_back((seg){ini, fin});
  else {
    if (_s1.l != -1) res.push_back(_s1);
    if (_s2.l != -1) res.push_back(_s2);
  }
  return res;
}
void print(vector<seg> s) {
  for (int i = (int)0; i < (int)s.size(); i++) {
    cout << " :*: " << s[i].l << ", " << s[i].r;
  }
  cout << endl;
}
int solve(int n, vector<seg> s1, vector<seg> s2) {
  int ans = 0;
  for (int i = (int)0; i < (int)s1.size(); i++)
    for (int j = (int)0; j < (int)s2.size(); j++)
      ans = max(ans, s1[i].inter(s2[j]).len());
  if (n == 1) return ans;
  int mid = (n + 1) / 2;
  return max(ans, solve(mid - 1, explode(s1, mid), explode(s2, mid)));
}
int main() {
  seg s1, s2;
  cin >> s1.l >> s1.r;
  cin >> s2.l >> s2.r;
  vector<seg> v1, v2;
  v1.push_back(s1);
  v2.push_back(s2);
  cout << solve((1 << 30) - 1, v1, v2) << endl;
  return 0;
}
