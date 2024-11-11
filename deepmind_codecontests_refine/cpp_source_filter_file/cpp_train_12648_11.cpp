#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int maxm = 330;
const long long oo = 1ll << 62;
int n, a[maxn], size, cnt, L[maxn], R[maxn], cntused[maxn];
long long sumused[maxn], suf[maxn], B[maxn];
bool used[maxn];
struct poi {
  long long a, b;
  int p;
};
vector<poi> hull[maxm];
poi q[maxn];
bool operator<(poi x, poi y) { return x.a != y.a ? x.a < y.a : x.b < y.b; }
bool check(poi x, poi y, poi z) {
  if (y.a == z.a) return true;
  return 1ll * (x.b - y.b) * (z.a - y.a) >= 1ll * (y.a - x.a) * (y.b - z.b);
}
void rebuild(int num) {
  for (int i = L[num]; i <= R[num]; i++) B[i] = 0;
  int inpre = 0;
  for (int i = L[num]; i <= R[num]; i++)
    if (used[i])
      inpre++;
    else
      B[i] += 1ll * inpre * a[i];
  long long insuf = 0;
  for (int i = R[num]; i >= L[num]; i--)
    if (used[i])
      insuf += a[i];
    else
      B[i] += 1ll * insuf;
  hull[num].clear();
  for (int i = L[num]; i <= R[num]; i++)
    if (!used[i]) {
      hull[num].push_back((poi){a[i], B[i], i});
    }
  sort(hull[num].begin(), hull[num].end());
  int tl = 0;
  for (int i = 0; i < (int)hull[num].size(); i++) {
    while (tl >= 2 && check(q[tl - 1], q[tl], hull[num][i])) tl--;
    q[++tl] = hull[num][i];
  }
  hull[num].clear();
  for (int i = 1; i <= tl; i++) hull[num].push_back(q[i]);
}
long long calc(long long pr, poi o) { return pr * o.a + o.b; }
void upd(long long &ans, int &anspos, int pos, long long val) {
  if (val > ans) {
    anspos = pos;
    ans = val;
  }
}
void solve(long long &ans, int &anspos, int now, long long pr, long long suf) {
  if ((int)hull[now].size() == 0) return;
  if ((int)hull[now].size() == 1) {
    upd(ans, anspos, hull[now][0].p, calc(pr, hull[now][0]) + suf);
    return;
  }
  int l = 0, r = (int)hull[now].size() - 2;
  while (l <= r) {
    if (calc(pr, hull[now][((l + r) >> 1) + 1]) >=
        calc(pr, hull[now][((l + r) >> 1)]))
      l = ((l + r) >> 1) + 1;
    else
      r = ((l + r) >> 1) - 1;
  }
  upd(ans, anspos, hull[now][l].p, calc(pr, hull[now][l]) + suf);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  size = (int)sqrt(n);
  if (size * size < n) size++;
  cnt = -1;
  for (int i = 0; i <= n; i++) L[i] = n + 1, R[i] = -1;
  for (int i = 0; i < n; i++) {
    L[i / size] = min(L[i / size], i);
    R[i / size] = max(R[i / size], i);
    cnt = max(cnt, i / size);
  }
  cnt++;
  for (int i = 0; i < n; i++) used[i] = 0;
  for (int i = 0; i < cnt; i++) cntused[i] = 0, sumused[i] = 0;
  for (int i = 0; i < cnt; i++) rebuild(i);
  long long ans = -oo;
  long long cursum = 0;
  for (int num = 1; num <= n; num++) {
    long long now = -oo;
    int nowpos = -1;
    suf[cnt - 1] = 0;
    for (int i = cnt - 2; i >= 0; i--) suf[i] = suf[i + 1] + sumused[i + 1];
    int pr = 1;
    for (int i = 0; i < cnt; i++) {
      solve(now, nowpos, i, pr, suf[i]);
      pr += cntused[i];
    }
    if (nowpos == -1 || now == -oo) break;
    used[nowpos] = 1;
    cursum += now;
    ans = max(ans, cursum);
    cntused[nowpos / size]++;
    sumused[nowpos / size] += a[nowpos];
    rebuild(nowpos / size);
  }
  cout << ans << endl;
  return 0;
}
