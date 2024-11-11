#include <bits/stdc++.h>
using namespace std;
const int dell[8][2] = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
long long mod = 1e9 + 7;
const long long inf = (1LL << 31) - 1;
const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int csize = 22;
int n, k, m, ar[maxn];
int p[maxn], s[maxn], h[maxn];
int le[maxn], ri[maxn];
int nex[maxn];
int ss[maxn];
pair<int, int> pp[maxn];
int main() {
  scanf("%d%d", &n, &m);
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &s[i], &h[i]);
    pp[i] = make_pair(s[i], h[i]);
    ss[s[i]] = i;
  }
  sort(pp + 1, pp + m + 1);
  for (int i = 1; i <= m; i++) {
    s[i] = pp[i].first;
    h[i] = pp[i].second;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  for (int i = 1; i <= m; i++) {
    int x = s[i], v = h[i];
    le[x] = ri[x] = x;
    for (int j = x - 1; j > 0; j--) {
      v += ar[j];
      if (v >= 0)
        le[x] = j;
      else
        break;
    }
    v = h[i];
    for (int j = x + 1; j <= n; j++) {
      v += ar[j];
      if (v >= 0)
        ri[x] = j;
      else
        break;
    }
  }
  int ans = 0, mid1 = 0, mid2 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[1] > i) continue;
    if (s[m] < i) continue;
    bool fond = 1;
    mid1 = mid2 = 0;
    memset(nex, 0, sizeof(nex));
    int pre = s[1];
    for (int j = 2; j <= m; j++) {
      if (s[j] > i) break;
      if (ri[pre] < s[j]) {
        fond = 0;
        break;
      }
      if (ri[pre] > ri[s[j]]) {
        nex[s[j]] = nex[pre];
        nex[pre] = s[j];
      } else {
        nex[s[j]] = pre;
        pre = s[j];
      }
    }
    mid1 = pre;
    if (!fond) continue;
    if (s[m] == i && ri[mid1] >= i) {
      ans = i;
      break;
    }
    pre = s[m];
    for (int j = m - 1; j >= 1; j--) {
      if (s[j] <= i) break;
      if (le[pre] > s[j]) {
        fond = 0;
        break;
      }
      if (le[pre] < le[s[j]]) {
        nex[s[j]] = nex[pre];
        nex[pre] = s[j];
      } else {
        nex[s[j]] = pre;
        pre = s[j];
      }
    }
    mid2 = pre;
    if (fond && (ri[mid1] >= i && le[mid2] <= i + 1 ||
                 ri[mid1] >= i - 1 && le[mid2] <= i)) {
      ans = i;
      break;
    }
  }
  if (ans) {
    printf("%d\n", ans);
    int ins = 0;
    int now = mid1;
    if (ri[mid1] < ans) {
      now = mid2;
      while (now) {
        printf("%d%c", ss[now], ++ins == m ? '\n' : ' ');
        now = nex[now];
      }
      now = mid1;
      while (now) {
        printf("%d%c", ss[now], ++ins == m ? '\n' : ' ');
        now = nex[now];
      }
      return 0;
    }
    while (now) {
      printf("%d%c", ss[now], ++ins == m ? '\n' : ' ');
      now = nex[now];
    }
    now = mid2;
    while (now) {
      printf("%d%c", ss[now], ++ins == m ? '\n' : ' ');
      now = nex[now];
    }
  } else
    printf("-1\n");
  return 0;
}
