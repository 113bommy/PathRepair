#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> segs[2];
const int MAXN = 401005;
const int MOD = 1000000007;
pair<int, int> P[2][MAXN];
int las[2][MAXN], ep[2][MAXN];
long long F[2][MAXN], H[MAXN], bit[2][MAXN];
long long query(int p, int t) {
  long long ret = 0;
  for (; p; p -= p & -p) {
    ret += bit[t][p];
    if (ret >= MOD) ret -= MOD;
  }
  return ret;
}
void update(int p, long long v, int t) {
  for (; p < MAXN; p += p & -p) {
    bit[t][p] += v;
    if (bit[t][p] >= MOD) bit[t][p] -= MOD;
  }
}
long long modex(long long a, long long p, long long m = MOD) {
  if (!p) return 1;
  if (p & 1) return a * modex(a, p - 1, m) % m;
  long long v = modex(a, p >> 1, m);
  return v * v % m;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int main() {
  int K, N[2];
  scanf("%d%d%d", &K, &N[0], &N[1]);
  vector<int> impt = {1, K + 1};
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < N[k]; ++i)
      scanf("%d%d", &P[k][i].first, &P[k][i].second);
    sort(P[k], P[k] + N[k], cmp);
    for (int i = 0; i < N[k]; ++i) {
      while (!segs[k].empty() && P[k][i].second <= segs[k].back().second) {
        segs[k].pop_back();
      }
      segs[k].push_back(P[k][i]);
    }
    for (auto s : segs[k]) {
      impt.push_back(s.first);
      impt.push_back(s.second + 1);
    }
  }
  sort(impt.begin(), impt.end());
  impt.resize(unique(impt.begin(), impt.end()) - impt.begin());
  assert(impt.size() < MAXN);
  int lasv[2] = {0, 0};
  int n = impt.size();
  for (int i = 1; i <= n; ++i) {
    int x = impt[i - 1];
    for (int k = 0; k < 2; ++k) {
      while (lasv[k] < segs[k].size() && x >= segs[k][lasv[k]].first) ++lasv[k];
      las[k][i] = lasv[k];
    }
  }
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < segs[k].size(); ++i) {
      ep[k][i] = lower_bound(impt.begin(), impt.end(), segs[k][i].second + 1) -
                 impt.begin();
    }
    ep[k][segs[k].size()] = n;
  }
  assert(impt.back() == K + 1);
  F[0][n] = F[1][n] = 1;
  update(n, 1, 0);
  update(n, 1, 1);
  for (int i = n - 1; i >= 1; --i) {
    int x = impt[i - 1];
    for (int k = 0; k < 2; ++k) {
      int e = ep[1 - k][las[1 - k][i - 1]];
      long long v = query(e, 1 - k);
      F[k][i] = v;
    }
    int len = impt[i] - x;
    if (i == n - 1) {
      H[i] = modex(2, len) - 2;
      if (H[i] < 0) H[i] += MOD;
    } else {
      H[i] = (modex(2, len) - 2) * (H[i + 1] + F[0][i + 1] + F[1][i + 1]);
      H[i] %= MOD;
      if (H[i] < 0) H[i] += MOD;
    }
    update(i, (F[0][i] + H[i]) % MOD, 0);
    update(i, (F[1][i] + H[i]) % MOD, 1);
  }
  long long ans = (F[0][1] + F[1][1] + H[1]) % MOD;
  printf("%lld\n", ans);
}
