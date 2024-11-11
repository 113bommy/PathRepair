#include <bits/stdc++.h>
using namespace std;
const int MAX = 20010;
const int MAX2 = 100100;
const int MAXT = 400;
const int INF = 2e9 + 1000;
const long long INFl = 2e18;
const int MOD = 1000000007;
const double EPS = 1e-10;
int time(int h, int m, int s) { return h * 3600 + m * 60 + s; }
int n, M, T;
int ti[MAX];
int outr[MAX];
struct st {
  int time, i;
  st(int t, int i) : time(t), i(i) {}
  st() {}
  bool operator<(const st other) const { return time > other.time; }
};
int all[MAX];
int check(int m) {
  priority_queue<st> pq;
  queue<int> q;
  int last = -1;
  for (int i = 0; i < m; ++i) {
    all[i] = 0;
    q.push(i);
  }
  bool out = false;
  int maxc = -1;
  int ucnt = 0;
  for (int i = 0; i < n; ++i) {
    while (!pq.empty() && pq.top().time <= ti[i]) {
      st c = pq.top();
      pq.pop();
      --all[c.i];
      if (all[c.i] == 0) {
        q.push(c.i);
        --ucnt;
      }
    }
    if (ucnt == M || q.empty()) {
      pq.push(st(ti[i] + T - 1, last));
      ++all[last];
      outr[i] = last;
    } else {
      int r = q.front();
      q.pop();
      pq.push(st(ti[i] + T - 1, r));
      ++all[r];
      if (all[r] == 1) ++ucnt;
      maxc = max(maxc, r);
      outr[i] = r;
      last = r;
    }
    if (ucnt == M) out = true;
    cout << endl;
  }
  int res = 0;
  if (out) res |= 1;
  if (maxc == m - 1) res |= 2;
  return res;
}
int main() {
  cin >> n >> M >> T;
  for (int i = 0; i < n; ++i) {
    char c;
    int h, m, s;
    cin >> h >> c >> m >> c >> s;
    ti[i] = time(h, m, s);
  }
  int l = 1, r = n;
  while (l < r) {
    int c = (l + r + 1) / 2;
    int re = check(c);
    if (!(re & 2))
      r = c - 1;
    else
      l = c;
  }
  int res = check(l);
  if (res & 1) {
    cout << l << endl;
    for (int i = 0; i < n; ++i) cout << outr[i] + 1 << "\n";
  } else {
    cout << "No solution\n";
  }
}
