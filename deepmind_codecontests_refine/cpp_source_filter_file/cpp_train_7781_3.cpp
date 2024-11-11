#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 2010;
int dp[9][SIZE][715];
int cnt[SIZE];
int a[SIZE], b[SIZE];
int five[10];
vector<int> hh;
void dfs(int x, int now, int r) {
  if (x == 9 || r == 0) {
    hh.push_back(now);
    return;
  }
  for (int i = (0); i <= (r); ++i) {
    dfs(x + 1, now + five[x] * i, r - i);
  }
}
void build() {
  five[0] = 1;
  for (int i = (1); i < (10); ++i) five[i] = five[i - 1] * 5;
  dfs(0, 0, 4);
  (sort(hh.begin(), hh.end()),
   hh.resize(distance(hh.begin(), unique(hh.begin(), hh.end()))));
  for (int i = 0; i < (((int)(hh).size())); ++i) {
    int me = hh[i];
    while (me) {
      cnt[i] += me & 1;
      me >>= 1;
    }
  }
}
int get_id(int x) {
  int id = (lower_bound(hh.begin(), hh.end(), x) - hh.begin());
  if (id < ((int)(hh).size()) && hh[id] == x) return id;
  return -1;
}
struct DATA {
  int x, id, state;
  int v;
  DATA(int x, int id, int state, int v) : x(x), id(id), state(state), v(v) {}
  bool operator<(const DATA &B) const { return v > B.v; }
};
int get_num(int x, int v) { return x / five[v] % 5; }
bool update(int &x, int v) {
  if (x == -1 || x > v) {
    x = v;
    return 1;
  }
  return 0;
}
int main() {
  memset((dp), -1, sizeof((dp)));
  build();
  int n;
  R(n);
  for (int i = (1); i <= (n); ++i) {
    R(a[i], b[i]);
    a[i]--;
    b[i]--;
  }
  priority_queue<DATA> pq;
  memset((dp), -1, sizeof((dp)));
  dp[a[1]][1][get_id(five[b[1]])] = a[1];
  pq.push(DATA(a[1], 1, five[b[1]], a[1]));
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    if (now.id == n && now.state == 0) {
      W(now.v + n * 2);
      return 0;
    }
    if (dp[now.x][now.id][get_id(now.state)] != now.v) continue;
    {
      auto nxt = now;
      int v = get_num(nxt.state, nxt.x);
      nxt.state -= v * five[nxt.x];
      if (nxt.id + 1 <= n && a[nxt.id + 1] == nxt.x &&
          cnt[get_id(nxt.state)] < 4) {
        nxt.id++;
        nxt.state += five[b[nxt.id]];
      }
      if (update(dp[nxt.x][nxt.id][get_id(nxt.state)], nxt.v)) pq.push(nxt);
    }
    if (now.x <= 7) {
      auto nxt = now;
      nxt.v++;
      nxt.x++;
      int v = get_num(nxt.state, nxt.x);
      nxt.state -= v * five[nxt.x];
      if (nxt.id + 1 <= n && a[nxt.id + 1] == nxt.x &&
          cnt[get_id(nxt.state)] < 4) {
        nxt.id++;
        nxt.state += five[b[nxt.id]];
      }
      if (update(dp[nxt.x][nxt.id][get_id(nxt.state)], nxt.v)) pq.push(nxt);
    }
    if (now.x > 0) {
      auto nxt = now;
      nxt.v++;
      nxt.x--;
      int v = get_num(nxt.state, nxt.x);
      nxt.state -= v * five[nxt.x];
      if (nxt.id + 1 <= n && a[nxt.id + 1] == nxt.x &&
          cnt[get_id(nxt.state)] < 4) {
        nxt.id++;
        nxt.state += five[b[nxt.id]];
      }
      if (update(dp[nxt.x][nxt.id][get_id(nxt.state)], nxt.v)) pq.push(nxt);
    }
  }
  return 0;
}
