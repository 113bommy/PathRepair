#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
inline long long read() {
  long long X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  putchar('\n');
}
pair<int, int> hero[maxn], que[maxn];
int idx[maxn], monn, heron, cur;
int monster[maxn], st[maxn];
class ST_Class {
 private:
  static const int maxnlog = 20;
  int n, rmq[maxn];
  int dp[maxn][maxnlog];

 public:
  void init() {
    rmq[1] = 0;
    for (int i = 2; i < maxn; i++) rmq[i] = rmq[i >> 1] + 1;
  }
  void resize(int siz) {
    n = siz;
    for (int i = 1; i <= n; i++) dp[i][0] = monster[i];
    for (int i = 1, maxlog = rmq[n]; i <= maxlog; i++)
      for (int j = 1; j + (1 << i) - 1 <= n; j++)
        dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
  }
  int query(int l, int r) {
    int tmp = rmq[r - l + 1];
    return max(dp[l][tmp], dp[r - (1 << tmp) + 1][tmp]);
  }
} ST;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool cal(int id) {
  int num = idx[id];
  if (num == -1)
    return false;
  else
    return que[num].second >= ST.query(cur + 1, min(monn, cur + id));
}
int find() {
  int l = 1, r = que[heron].first;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (l == mid) {
      if (cal(r))
        return r;
      else if (cal(l))
        return l;
      else
        return -1;
    }
    if (cal(mid))
      l = mid;
    else
      r = mid - 1;
  }
  return -1;
}
void debug() {
  for (int i = 1; i <= heron; i++) cout << que[i].second << " ";
  cout << endl;
}
int main() {
  ST.init();
  int T = read();
  while (T--) {
    monn = read();
    for (int i = 1; i <= monn; i++) monster[i] = read();
    ST.resize(monn);
    heron = read();
    for (int i = 1; i <= heron; i++) {
      int p = read(), s = read();
      hero[i] = make_pair(s, p);
    }
    sort(hero + 1, hero + 1 + heron, cmp);
    int cnt = 0;
    for (int i = 1; i <= heron; i++) {
      while (cnt and hero[i].second >= hero[st[cnt]].second) cnt--;
      st[++cnt] = i;
    }
    heron = cnt;
    for (int i = 1; i <= heron; i++) que[i] = hero[st[i]];
    for (int i = 1, flg = 1; i <= monn; i++) {
      while (flg <= heron and que[flg].first < i) flg++;
      idx[i] = que[flg].first >= i ? flg : -1;
    }
    cur = 0;
    int ans = 0;
    while (cur < monn) {
      int num = find();
      if (num == -1) {
        ans = -1;
        break;
      } else
        cur += num, ans++;
    }
    writeln(ans);
  }
  return 0;
}
