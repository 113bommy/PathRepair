#include <bits/stdc++.h>
using namespace std;
int n, m, tr[200005];
string dat;
vector<int> pos[305];
void upd(int id, int d) {
  for (; id <= n; id += id & -id) {
    tr[id] += d;
  }
}
int pre(int to) {
  int res = 0;
  for (; to; to -= to & -to) {
    res += tr[to];
  }
  return res;
}
int qry(int l, int r) { return pre(r) - pre(l - 1); }
int get_id(int id) {
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pre(mid) < id == 1) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> dat;
  dat = ' ' + dat;
  for (int i = 1; i <= n; ++i) {
    pos[(int)dat[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    upd(i, 1);
  }
  for (int i = 1; i <= m; ++i) {
    int l, r;
    char c;
    cin >> l >> r >> c;
    l = get_id(l);
    r = get_id(r);
    int from = lower_bound(pos[(int)c].begin(), pos[(int)c].end(), l) -
               pos[(int)c].begin(),
        to = upper_bound(pos[(int)c].begin(), pos[(int)c].end(), r) -
             pos[(int)c].begin();
    for (int j = from; j < to; ++j) {
      upd(pos[(int)c][j], -1);
      pos[(int)c].erase(pos[(int)c].begin() + j);
      --j;
      --to;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (qry(i, i)) {
      putchar(dat[i]);
    }
  }
  cout << endl;
}
