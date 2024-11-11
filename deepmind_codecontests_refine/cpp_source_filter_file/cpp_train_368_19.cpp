#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 200007;
const int MAXS = MAXN * 4;
const int MAX = 8;
class stT {
 public:
  stT() {
    memset(data, 0, sizeof(data));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < MAXS; ++i)
      maxi[i] = make_pair(0, 0), mini[i] = make_pair(SINF, 0);
    memset(wc, false, sizeof(wc));
  }
  pair<int, int> getmax() { return maxi[1]; }
  pair<int, int> getmin() { return mini[1]; }
  int getsum() { return sum[1]; }
  void setwc(int pos, bool val, int now = 1, int l = 1, int r = MAX) {
    if (!pos) return;
    if (pos == l && pos == r) {
      wc[pos] = val;
      if (val)
        mini[now] = make_pair(data[now], pos), maxi[now] = make_pair(0, 0),
        sum[now] = (data[now] + 1) >> 1;
      else
        mini[now] = make_pair(SINF, 0), maxi[now] = make_pair(data[now], pos),
        sum[now] = data[now];
    } else if (pos >= l && pos <= r) {
      int mid = (l + r) >> 1;
      setwc(pos, val, now << 1, l, mid);
      setwc(pos, val, now << 1 ^ 1, mid + 1, r);
      sum[now] = sum[now << 1] + sum[now << 1 ^ 1];
      maxi[now] =
          (((maxi[now << 1]) > (maxi[now << 1 ^ 1])) ? (maxi[now << 1])
                                                     : (maxi[now << 1 ^ 1]));
      mini[now] =
          (((mini[now << 1]) < (mini[now << 1 ^ 1])) ? (mini[now << 1])
                                                     : (mini[now << 1 ^ 1]));
    }
  }
  void setpl(int pos, bool val, int now = 1, int l = 1, int r = MAX) {
    if (pos == l && pos == r) {
      if (val) {
        sum[now] = data[now];
        maxi[now] = make_pair(data[now], pos);
      } else {
        sum[now] = 0;
        wc[pos] = false;
        mini[now] = make_pair(SINF, 0), maxi[now] = make_pair(0, 0);
      }
    } else if (pos >= l && pos <= r) {
      int mid = (l + r) >> 1;
      setpl(pos, val, now << 1, l, mid);
      setpl(pos, val, now << 1 ^ 1, mid + 1, r);
      sum[now] = sum[now << 1] + sum[now << 1 ^ 1];
      maxi[now] =
          (((maxi[now << 1]) > (maxi[now << 1 ^ 1])) ? (maxi[now << 1])
                                                     : (maxi[now << 1 ^ 1]));
      mini[now] =
          (((mini[now << 1]) < (mini[now << 1 ^ 1])) ? (mini[now << 1])
                                                     : (mini[now << 1 ^ 1]));
    }
  }
  void setd(int pos, int val, int now = 1, int l = 1, int r = MAX) {
    if (pos == l && pos == r)
      data[now] = val;
    else if (pos >= l && pos <= r) {
      int mid = (l + r) >> 1;
      setd(pos, val, now << 1, l, mid);
      setd(pos, val, now << 1 ^ 1, mid + 1, r);
    }
  }

 private:
  int data[MAXS], sum[MAXS];
  pair<int, int> maxi[MAXS], mini[MAXS];
  bool wc[MAXS];
} st;
int n, w, k;
int a[MAXN], t[MAXN];
int pre[MAXN];
bool wc[MAXN];
void init();
void input();
void work();
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d%d", &n, &w, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
}
void work() {
  pre[0] = 0;
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
  t[n + 1] = 0;
  for (int i = 1; i <= n + 1; ++i) st.setd(i, t[i]);
  int l = 0, r = 0, ans = 0;
  pair<int, int> nm;
  memset(wc, false, sizeof(wc));
  while (1) {
    while (r <= n && st.getsum() <= k) {
      ++r;
      st.setpl(r, true);
      if (r - l <= w)
        st.setwc(r, true), wc[r] = true;
      else {
        nm = st.getmin();
        if (t[r] > nm.first) {
          st.setwc(nm.second, false), wc[nm.second] = false;
          st.setwc(r, true), wc[r] = true;
        }
      }
    }
    ans = (((ans) > (pre[r - 1] - pre[l])) ? (ans) : (pre[r - 1] - pre[l]));
    if (r > n) break;
    ++l;
    st.setpl(l, false);
    if (wc[l]) {
      wc[l] = false;
      nm = st.getmax();
      st.setwc(nm.second, true);
      wc[nm.second] = true;
    }
  }
  printf("%d\n", ans);
}
