#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int l, r, num, fen[N], wh[N], a[N], Add[N];
long long tot, fen2[N];
void add(int x, int val) {
  for (; x < N; x += x & -x) {
    if (val > 0) {
      fen[x]++;
    } else {
      fen[x]--;
    }
    fen2[x] += val;
  }
}
pair<int, long long> get(int x) {
  int ret = 0;
  long long ret2 = 0;
  for (; x; x -= x & -x) {
    ret += fen[x];
    ret2 += fen2[x];
  }
  return {ret, ret2};
}
long long f(int l, int r) { return 1ll * (l + r) * (r - l + 1) / 2; }
long long Get(int pos) {
  pair<int, long long> p = get(pos);
  return p.second - f(l, l + p.first - 1) +
         1ll * f(r - (num - p.first) + 1, r) - (tot - p.second);
}
int check(int pos) {
  pair<int, long long> p = get(pos);
  return pos - l + 1 - p.first;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    wh[a[i]] = i;
  }
  for (int i = n; i > 0; i--) {
    Add[i] = get(a[i]).first;
    add(a[i], 1);
  }
  memset(fen, 0, sizeof(fen));
  memset(fen2, 0, sizeof(fen2));
  long long ans = 0;
  l = wh[1], r = wh[1];
  cout << "0 ";
  for (int i = 2; i <= n; i++) {
    int id = wh[i];
    if (id > l && id < r) {
      add(id, -id);
      tot -= id;
      num--;
    } else if (id > r) {
      while (++r < id) {
        num++;
        tot += r;
        add(r, r);
      }
    } else {
      while (--l > id) {
        num++;
        tot += l;
        add(l, l);
      }
    }
    int L = l - 1, R = r + 1;
    while (R - L > 1) {
      int m = (L + R) / 2;
      if (check(m) > i / 2)
        R = m;
      else
        L = m;
    }
    ans += Add[id];
    cout << ans + Get(L) << " ";
  }
  return 0;
}
