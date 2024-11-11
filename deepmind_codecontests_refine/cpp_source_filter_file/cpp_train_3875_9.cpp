#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 20;
const int M = 1e5;
const int mod = 0;
const int inf = 2e9 + 3;
const long long INF = 1e18;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
void files() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int n, cnt, f;
unsigned long long h[N];
set<int> c;
map<long long, int> g;
pair<int, int> a[N], b[N];
vector<int> la[N], lb[N], da[N], db[N];
unsigned long long pref[3][2][N], suff[3][2][N];
long long rnd() {
  unsigned long long A, B;
  A = (rand() << 15) | rand();
  B = (rand() << 15) | rand();
  return (A << 15) | B;
}
int main() {
  srand(time(0));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d", &a[i].first, &a[i].second, &b[i].first, &b[i].second);
    c.insert(a[i].first);
    c.insert(a[i].second);
    c.insert(b[i].first);
    c.insert(b[i].second);
  }
  for (auto it : c) g[it] = ++cnt;
  for (int i = 1; i <= n; ++i) {
    a[i].first = g[a[i].first];
    a[i].second = g[a[i].second];
    b[i].first = g[b[i].first];
    b[i].second = g[b[i].second];
    la[a[i].first].push_back(i);
    da[a[i].second + 1].push_back(i);
    lb[b[i].first].push_back(i);
    db[b[i].second + 1].push_back(i);
    h[i] = rnd();
  }
  for (int i = 1; i <= cnt + 1; ++i) {
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 2; ++k) pref[j][k][i] = pref[j][k][i - 1];
    for (auto it : da[i]) {
      pref[0][0][i] += h[it];
      pref[1][0][i] ^= h[it];
      pref[2][0][i]++;
    }
    for (auto it : db[i]) {
      pref[0][1][i] += h[it];
      pref[1][1][i] ^= h[it];
      pref[2][1][i]++;
    }
  }
  for (int i = cnt + 1; i >= 1; --i) {
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 2; ++k) suff[j][k][i] = suff[j][k][i + 1];
    for (auto it : la[i]) {
      suff[0][0][i] += h[it];
      suff[1][0][i] ^= h[it];
      suff[2][0][i]++;
    }
    for (auto it : lb[i]) {
      suff[0][1][i] += h[it];
      suff[1][1][i] ^= h[it];
      suff[2][1][i]++;
    }
  }
  unsigned long long cnta, cntb;
  for (int i = 1; i <= n; ++i) {
    cnta = pref[0][0][a[i].first - 1] + suff[0][0][a[i].second + 1];
    cntb = pref[0][1][b[i].first - 1] + suff[0][1][b[i].second + 1];
    f |= (cnta != cntb);
    cnta = pref[1][0][a[i].first - 1] ^ suff[1][0][a[i].second + 1];
    cntb = pref[1][1][b[i].first - 1] ^ suff[1][1][b[i].second + 1];
    f |= (cnta != cntb);
    cnta = pref[2][0][a[i].first - 1] + suff[2][0][a[i].second + 1];
    cntb = pref[2][1][b[i].first - 1] + suff[2][1][b[i].second + 1];
    f |= (cnta != cntb);
  }
  if (!f)
    printf("YES\n");
  else
    printf("NO\n");
}
