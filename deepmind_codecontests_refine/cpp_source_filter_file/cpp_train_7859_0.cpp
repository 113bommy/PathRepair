#include <bits/stdc++.h>
using namespace std;
const int MAXM = 3e4 + 10;
const int MAXW = 1e3 + 10;
const long long M1 = 1e7 + 19;
const long long M2 = 1e9 + 7;
struct item {
  int s, t, w;
  long long v;
};
int W, m, cnt = 0;
bool bq[MAXM];
long long pw[MAXW], f[20][MAXW];
item r[MAXM];
vector<int> st[MAXM * 20];
void lucky() {
  cin.tie(0);
  cin >> cnt >> W;
  for (int i = 1; i <= cnt; i++) cin >> r[i].v >> r[i].w, r[i].s = 1;
  cin >> m;
}
long long calc(long long *f) {
  long long res = 0;
  for (int i = 1; i <= W; i++) res = (res + 1LL * f[i] * pw[i - 1]) % M2;
  return res;
}
void solve(int ql, int qr, int o, int d) {
  int mid = (ql + qr) >> 1;
  for (int i = 1; i <= W; i++) f[d][i] = f[d - 1][i];
  if (ql < qr)
    for (int i = 0; i < st[o].size(); i++) {
      int x = st[o][i];
      if (r[x].s <= ql && qr <= r[x].t)
        for (int j = W; j >= r[x].w; j--)
          f[d][j] = max(f[d][j], f[d][j - r[x].w] + r[x].v);
      else {
        if (r[x].s <= mid) st[((o) << 1)].push_back(x);
        if (r[x].t > mid) st[((o) << 1 | 1)].push_back(x);
      }
    }
  else {
    for (int i = 0; i < st[o].size(); i++) {
      int x = st[o][i];
      if (r[x].s <= ql && qr <= r[x].t)
        for (int j = W; j >= r[x].w; j--)
          f[d][j] = max(f[d][j], f[d][j - r[x].w] + r[x].v);
    }
    if (bq[ql]) cout << calc(f[d]) << endl;
    return;
  }
  solve(ql, mid, ((o) << 1), d + 1);
  solve(mid + 1, qr, ((o) << 1 | 1), d + 1);
}
int main() {
  int o, x;
  lucky();
  for (int i = 1; i <= cnt; i++) r[i].t = m;
  for (int i = 1; i <= m; i++)
    if (cin >> o, o == 1)
      cnt++, r[cnt].s = i, r[cnt].t = m, cin >> r[cnt].v >> r[cnt].w;
    else if (o == 2)
      cin >> x, r[x].t = i - 1;
    else
      bq[i] = 1;
  pw[0] = 1;
  for (int i = 1; i <= W; i++) pw[i] = (pw[i - 1] * M1) % M2;
  for (int i = 1; i <= m; i++) st[1].push_back(i);
  solve(1, m, 1, 1);
  return 0;
}
