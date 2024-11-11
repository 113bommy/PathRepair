#include <bits/stdc++.h>
using namespace std;
const int maxn = 16, INF = 0x3f3f3f3f;
char type[maxn];
int R[maxn], B[maxn];
char readchar() {
  for (;;) {
    char ch = getchar();
    if (!isspace(ch)) {
      return ch;
    }
  }
}
int n;
set<pair<int, int> > dp[1 << maxn];
void Insert(set<pair<int, int> >& s, const pair<int, int>& p) {
  set<pair<int, int> >::iterator it = s.lower_bound(p);
  if (it == s.begin() || (--it)->second > p.second) {
    s.insert(p);
    it = s.upper_bound(p);
    while (it != s.end() && it->second >= p.second) {
      s.erase(it++);
    }
  }
}
void DP(int s) {
  set<pair<int, int> >& res = dp[s];
  if (res.size()) {
    return;
  }
  if (s == 0) {
    res.insert(make_pair(0, 0));
    return;
  }
  int curR = 0, curB = 0;
  for (int i = 0; i < n; i++) {
    if (!((s & (1 << i)))) {
      if (type[i] == 'R') {
        curR++;
      } else {
        curB++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s & (1 << i)) {
      DP(s & (~(1 << i)));
      set<pair<int, int> >& tmp = dp[s & (~(1 << i))];
      for (set<pair<int, int> >::iterator it = tmp.begin(); it != tmp.end();
           it++) {
        Insert(res, make_pair(it->first + max(0, R[i] - curR),
                              it->second + max(0, B[i] - curB)));
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    type[i] = readchar();
    cin >> R[i] >> B[i];
  }
  DP((1 << n) - 1);
  int ans = INF;
  set<pair<int, int> >& res = dp[(1 << n) - 1];
  for (set<pair<int, int> >::iterator it = res.begin(); it != res.end(); it++) {
    ans = min(ans, it->first + it->second + n);
  }
  cout << ans << endl;
  return 0;
}
