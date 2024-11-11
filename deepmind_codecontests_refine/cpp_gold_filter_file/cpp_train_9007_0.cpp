#include <bits/stdc++.h>
using namespace std;
deque<int> d;
int a[500005], n, m, o, i, j, used[500005], cur, p, nxt[500005], lst[500005];
string s, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  cin >> s >> t;
  for (i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      d.push_back(i);
    else {
      a[i] = d.back();
      a[d.back()] = i;
      d.pop_back();
    }
  }
  for (i = 0; i < n; ++i) {
    nxt[i] = i + 1;
    lst[i] = i - 1;
  }
  --p;
  for (i = 0; i < m; ++i) {
    if (t[i] == 'L')
      p = lst[p];
    else if (t[i] == 'R')
      p = nxt[p];
    else {
      if (s[p] == ')') {
        used[p] = 2;
        used[a[p]] = 1;
      }
      if (s[p] == '(') {
        used[p] = 1;
        used[a[p]] = 2;
      }
      int l = min(p, a[p]);
      int r = max(p, a[p]);
      nxt[lst[l]] = nxt[r];
      lst[nxt[r]] = lst[l];
      if (nxt[r] == n)
        p = lst[l];
      else
        p = nxt[r];
    }
  }
  int bl = 0;
  for (i = 0; i < s.size(); ++i) {
    if (used[i] == 1)
      ++bl;
    else if (used[i] == 2)
      bl--;
    if (used[i] == 2 && bl == 0) continue;
    if (bl == 0) cout << s[i];
  }
}
