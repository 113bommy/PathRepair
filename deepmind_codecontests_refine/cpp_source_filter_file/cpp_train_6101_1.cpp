#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001000;
string s[maxn];
int pos[maxn], id[maxn];
int n;
signed main() {
  int mx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int cnt, sz = s[i].length();
    scanf("%d", &cnt);
    for (int j = 1; j <= cnt; j++) {
      int p;
      scanf("%d", &p);
      if (sz > pos[p]) {
        pos[p] = sz;
        id[p] = i;
      }
      mx = max(mx, p + sz - 1);
    }
  }
  int cnt = 0, tot = 0, now;
  string ret;
  for (int i = 1; i <= mx; i++) {
    if (pos[i] > cnt) {
      cnt = pos[i];
      now = id[i];
      tot = 0;
    }
    if (cnt == 0) {
      ret += 'a';
      continue;
    }
    ret += s[now][tot++];
    cnt--;
  }
  cout << ret << endl;
  return 0;
}
