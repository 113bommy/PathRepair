#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 5010 + 5;
map<char, int> ov;
map<string, int> mp;
map<int, string> mp2;
struct str {
  int n1, n2, n3, flag;
  bool operator<(const str& r) const {
    if (n2 < r.n2)
      return true;
    else if (n2 > r.n2)
      return false;
    return n3 < r.n3;
  }
};
str a[110000];
int pre[110000], suf[110000], tot1, tot2;
int tmp[110000], cur;
int main() {
  ov['a'] = 1;
  ov['e'] = 2;
  ov['i'] = 3;
  ov['o'] = 4;
  ov['u'] = 5;
  int n;
  string s;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (!mp[s]) {
      mp[s] = ++cnt;
      mp2[cnt] = s;
    }
    int x = 0, y = 0, sz = s.size();
    for (int j = sz - 1; j >= 0; j--) {
      if (ov[s[j]]) {
        x++;
        if (x == 1) y = ov[s[j]];
      }
    }
    a[i] = {mp[s], x, y, 1};
  }
  sort(a, a + n);
  int ans = 0;
  int st = 0, ed = 0;
  while (1) {
    while (a[ed + 1].n2 == a[st].n2) ed++;
    for (int i = st; i < ed; i++) {
      if (a[i].n3 == a[i + 1].n3 && a[i].flag && a[i + 1].flag) {
        suf[tot2++] = a[i].n1;
        suf[tot2++] = a[i + 1].n1;
        a[i].flag = a[i + 1].flag = 0;
      }
    }
    cur = 0;
    for (int i = st; i <= ed; i++) {
      if (a[i].flag) tmp[cur++] = a[i].n1;
    }
    if (cur & 1) cur--;
    for (int i = 0; i < cur; i++) pre[tot1++] = tmp[i];
    if (ed == n - 1) break;
    st = ed + 1;
    ed = st;
  }
  if (tot1 > tot2)
    ans = tot2 / 2;
  else {
    int tp = (tot2 - tot1) / 4;
    for (int i = tot1, j = tot2 - 1; i < tot1 + tp * 2; i++, j--)
      pre[i] = suf[j];
    tot2 -= tp * 2;
    tot1 += tp * 2;
    ans = min(tot1, tot2) / 2;
  }
  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    cout << mp2[pre[i * 2]] << " " << mp2[suf[i * 2]] << endl;
    cout << mp2[pre[i * 2 + 1]] << " " << mp2[suf[i * 2 + 1]] << endl;
  }
  return 0;
}
