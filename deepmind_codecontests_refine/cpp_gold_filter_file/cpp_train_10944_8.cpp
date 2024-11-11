#include <bits/stdc++.h>
using namespace std;
const int offset = (1 << 18);
const int maxm = 210;
const int maxn = 100100;
const long long int inf = 1e18 + 100;
struct env {
  int s, t, d, w;
  env(int _s, int _t, int _d, int _w) {
    s = _s;
    t = _t;
    d = _d;
    w = _w;
  }
  friend bool operator<(env A, env B) {
    if (A.w != B.w) return A.w < B.w;
    return A.d < B.d;
  }
};
struct tournament {
  pair<int, int> maxi[2 * offset];
  void update(int cvor, int a, int b, int l, int r, pair<int, int> kolko) {
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      maxi[cvor] = kolko;
      return;
    }
    int mid = (l + r) / 2;
    update(cvor * 2, a, b, l, mid, kolko);
    update(cvor * 2 + 1, a, b, mid + 1, r, kolko);
    return;
  }
} T;
int n, m, k;
vector<env> svi;
pair<int, int> pravi[maxn];
long long int dp[maxn][maxm];
long long int rek(int poz, int bro) {
  if (dp[poz][bro] != -1) return dp[poz][bro];
  if (poz >= n) return dp[poz][bro] = 0;
  long long int mini = inf;
  if (bro > 0) {
    mini = min(mini, rek(poz + 1, bro - 1));
  }
  if (pravi[poz].second == -1)
    mini = min(mini, rek(poz + 1, bro));
  else {
    mini = min(mini, rek(pravi[poz].second + 1, bro) + pravi[poz].first);
  }
  return dp[poz][bro] = mini;
}
int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 1; i < 2 * offset; i++) {
    T.maxi[i].first = T.maxi[i].second = -1;
  }
  cin >> n >> m >> k;
  int s, t, d, w;
  for (int i = 0; i < k; i++) {
    scanf("%d%d%d%d", &s, &t, &d, &w);
    s--;
    t--;
    d--;
    svi.push_back(env(s, t, d, w));
  }
  sort(svi.begin(), svi.end());
  for (int i = 0; i < (int)svi.size(); i++) {
    T.update(1, svi[i].s, svi[i].t, 0, offset - 1,
             make_pair(svi[i].w, svi[i].d));
  }
  pair<int, int> trm;
  pair<int, int> potm;
  for (int i = 0; i < n; i++) {
    int tr = offset + i;
    trm.first = -1;
    trm.second = -1;
    while (tr) {
      potm = T.maxi[tr];
      if (potm.first > trm.first) {
        trm = potm;
      } else if (potm.first == trm.first && potm.second > trm.second) {
        trm = potm;
      }
      tr /= 2;
    }
    pravi[i] = trm;
  }
  printf("%lld\n", rek(0, m));
  return 0;
}
