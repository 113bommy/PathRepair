#include <bits/stdc++.h>
using namespace std;
long long int inf = 1000000000ll * +200;
long long int mod = 998244353;
const int maxn = 5e5 + 200;
vector<pair<pair<long long int, long long int>, int> > srt[maxn], tmp;
int sufarr[maxn], rnk[maxn * 2], mn[20][maxn], dp[maxn], ktd[maxn], n;
long long int p[maxn], hsh[maxn], lcp[maxn], mx[maxn * 4];
inline long long int gthsh(int l, int r) {
  long long int res = (hsh[r] - hsh[l - 1] * p[r - l + 1]) % mod;
  if (res < 0) res += mod;
  return res;
}
inline int gtlcp(int i, int j) {
  int l = 0, r = n - max(i, j) + 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (gthsh(i + 1, i + mid) == gthsh(j + 1, j + mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
inline void ADD(int s, int e, int v, int pos, int val) {
  while (e - s > 1) {
    int mid = (s + e) >> 1;
    if (pos < mid) {
      e = mid;
      v *= 2;
    } else {
      s = mid;
      v *= 2;
      v++;
    }
  }
  mx[v] = val;
  while (v != 1) {
    v /= 2;
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
  }
  return;
}
int sgt(int s, int e, int v, int l, int r) {
  if (l <= s && e <= r) {
    return mx[v];
  }
  if (l >= e || s >= r) {
    return 0;
  }
  int mid = (s + e) >> 1;
  return max(sgt(s, mid, 2 * v, l, r), sgt(mid, e, 2 * v + 1, l, r));
}
int gtmn(int l, int r) {
  if (l > r) return inf;
  int tmp = r - l + 1;
  return (min(mn[ktd[tmp]][l], mn[ktd[tmp]][l + tmp - (1 << ktd[tmp])]));
}
int bfr(int ind, int sz) {
  int lo = -1, hi = ind;
  while (hi - lo > 1) {
    int mid = (lo + hi) >> 1;
    if (gtmn(mid, ind - 1) >= sz) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return hi;
}
int aft(int ind, int sz) {
  int lo = ind, hi = n;
  while (hi - lo > 1) {
    int mid = (lo + hi) >> 1;
    if (gtmn(ind, mid - 1) >= sz) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t2 = 0;
  for (int i = 1; i < maxn; i++) {
    if (i > (1 << t2)) t2++;
    ktd[i] = t2;
  }
  p[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p[i] = (p[i - 1] * 727) % mod;
  }
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    hsh[i] = (hsh[i - 1] * 727 + int(s[i - 1])) % mod;
  }
  for (int i = 0; i < n; i++) {
    rnk[i] = int(s[i]);
  }
  for (int k = 0; (1 << k) < n; k++) {
    for (int i = 0; i < n; i++) {
      srt[rnk[i + (1 << k)]].push_back({{rnk[i], rnk[i + (1 << k)]}, i});
    }
    for (int i = 0; i < maxn; i++) {
      for (auto P : srt[i]) {
        tmp.push_back(P);
      }
      srt[i].clear();
    }
    for (auto P : tmp) {
      srt[P.first.first].push_back(P);
    }
    tmp.clear();
    for (int i = 0; i < maxn; i++) {
      for (auto P : srt[i]) {
        tmp.push_back(P);
      }
      srt[i].clear();
    }
    int cur = 1;
    rnk[tmp[0].second] = 1;
    for (int i = 1; i < n; i++) {
      if (tmp[i].first != tmp[i - 1].first) {
        cur++;
      }
      rnk[tmp[i].second] = cur;
    }
    tmp.clear();
  }
  for (int i = 0; i < n; i++) {
    sufarr[rnk[i] - 1] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    lcp[i] = gtlcp(sufarr[i], sufarr[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    mn[0][i] = lcp[i];
  }
  for (int k = 1; k < 20; k++) {
    for (int i = 0; i < n; i++) {
      mn[k][i] = mn[k - 1][i];
      int pos = i + (1 << (k - 1));
      if (pos < n) {
        mn[k][i] = min(mn[k][i], mn[k - 1][pos]);
      }
    }
  }
  int cur = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur++;
    while ((cur != 1 && sgt(0, n, 1, bfr(rnk[i] - 1, cur - 1),
                            aft(rnk[i] - 1, cur - 1) + 1) < cur - 1) &&
           (sgt(0, n, 1, bfr(rnk[i + 1] - 1, cur - 1),
                aft(rnk[i + 1] - 1, cur - 1) + 1) < cur - 1)) {
      cur--;
      if (i + cur >= n) continue;
      ADD(0, n, 1, rnk[i + cur] - 1, dp[i + cur]);
    }
    dp[i] = cur;
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
