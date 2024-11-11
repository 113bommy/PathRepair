#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
template <typename first>
inline first abs(const first& a) {
  return a < 0 ? -a : a;
}
template <typename first>
inline first sqr(const first& a) {
  return a * a;
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;
const int N = 1000 + 3;
int n, k;
pair<int, int> p[N];
pair<int, pair<int, int> > d[N * N];
int szd;
int g[N][N], szg[N];
int vs[N], szvs;
int used[N], u;
bool WRITE;
int taken[N];
int need[N][N], szneed[N];
void halt() {
  int cntTaken = 0;
  for (int i = 0; i < int(n); i++)
    if (taken[i]) printf("%d ", i + 1), cntTaken++;
  puts("");
  assert(cntTaken == k);
  cerr << clock() << endl;
  exit(0);
}
int STEPS;
bool go(int idx, int rem) {
  if (++STEPS > 100 * 1000) return false;
  if (idx == szvs) {
    if (WRITE) halt();
    return true;
  }
  int v = vs[idx];
  if (taken[v]) return go(idx + 1, rem);
  int& cursz = szneed[idx];
  cursz = 0;
  bool ok = true;
  for (int i = 0; i < int(szg[v]); i++) {
    int to = g[v][i];
    if (!taken[to]) {
      need[idx][cursz++] = to;
      if (szg[to] == 1) {
        ok = false;
        break;
      }
    }
  }
  if (cursz == 0) return go(idx + 1, rem);
  if (rem >= cursz && ok) {
    for (int i = 0; i < int(cursz); i++) taken[need[idx][i]] = true;
    bool res = go(idx + 1, rem - cursz);
    for (int i = 0; i < int(cursz); i++) taken[need[idx][i]] = false;
    if (res) return true;
  }
  if (rem > 0 && (szg[v] > 1 || !ok)) {
    taken[v] = true;
    bool res = go(idx + 1, rem - 1);
    taken[v] = false;
    if (res) return true;
  }
  return false;
}
bool can(int cntEd) {
  szvs = 0, u++;
  for (int i = 0; i < int(cntEd); i++) {
    int a = d[i].second.first, b = d[i].second.second;
    if (used[a] != u) {
      used[a] = u;
      vs[szvs++] = a;
      szg[a] = 0;
    }
    if (used[b] != u) {
      used[b] = u;
      vs[szvs++] = b;
      szg[b] = 0;
    }
    g[a][szg[a]++] = b;
    g[b][szg[b]++] = a;
  }
  int cnt = 0;
  for (int i = 0; i < int(szvs); i++)
    if (szg[vs[i]] > k) taken[vs[i]] = true, cnt++;
  STEPS = 0;
  bool ans = (cnt > k ? false : go(0, k - cnt));
  for (int i = 0; i < int(szvs); i++)
    if (szg[vs[i]] > k) taken[vs[i]] = false, cnt++;
  return ans;
}
inline int dist2(const pair<int, int>& a, const pair<int, int>& b) {
  return sqr(a.first - b.first) + sqr(a.second - b.second);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < int(n); i++) scanf("%d%d", &p[i].first, &p[i].second);
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(i); j++)
      d[szd++] = make_pair((dist2(p[i], p[j])), (make_pair((j), (i))));
  sort(d, d + szd);
  reverse(d, d + szd);
  int lf = 1, rg = szd;
  while (lf != rg) {
    int mid = (lf + rg + 1) >> 1;
    if (can(mid))
      lf = mid;
    else
      rg = mid - 1;
  }
  WRITE = true;
  can(lf);
  return 0;
}
