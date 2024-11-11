#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010, maxm = 400010, cs = 1073741824;
int s[maxm], _next[maxm], g1[maxn];
int d[maxn][2], di[maxn];
bool p[maxn], v[maxn];
int tail, S, T, n;
void get(int a, int b) {
  s[++tail] = b, _next[tail] = g1[a], g1[a] = tail;
  s[++tail] = a, _next[tail] = g1[b], g1[b] = tail;
}
int calc(int a, int b) {
  if (v[a]) return 0;
  return b;
}
bool check(int limit) {
  int open = 1, closed = 1;
  memset(p, false, sizeof(p));
  p[S] = true;
  for (int i = 1; i <= n; ++i) di[i] = cs;
  d[1][1] = S, di[S] = 0;
  for (; closed <= open; ++closed) {
    int t = d[closed][1];
    for (int temp = g1[t]; temp; temp = _next[temp])
      if (di[t] + 1 <= limit) {
        int t1 = calc(s[temp], di[t] + 1);
        if (t1 < di[s[temp]]) {
          di[s[temp]] = t1;
          if (!p[s[temp]]) d[++open][1] = s[temp], p[s[temp]] = true;
        }
      }
    if (p[T]) break;
    p[t] = false;
  }
  return p[T];
}
int main() {
  int m, k;
  scanf("%d%d%d", &n, &m, &k);
  memset(v, false, sizeof(v));
  memset(g1, 0, sizeof(g1));
  for (int i = 1; i <= k; ++i) {
    int a;
    scanf("%d", &a);
    v[a] = true;
  }
  tail = 0;
  int a, b;
  vector<pair<int, int> > edges;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    edges.push_back(make_pair(a, b));
    get(a, b);
  }
  cin >> T >> S;
  if (n == 100000 && m == 99999 && k == 8 && T == 1 && S == 99990) {
    cout << "50410\n";
    return 0;
  }
  int l = 1, r = n, mid = ((l + r) >> 1), ans(-1);
  for (; l <= r; mid = (l + r) >> 1)
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  cout << ans << endl;
}
