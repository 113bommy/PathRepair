#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXD = 6800;
const long long INF = 1e18;
long long a[MAXN];
long long a_k[MAXN];
int n;
long long k;
bool read() {
  if (scanf("%d%lld", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < (int)n; ++i) {
    scanf("%lld", &a[i]);
  }
  return true;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
vector<long long> gen_divs(long long x) {
  vector<long long> divs;
  for (long long d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      divs.push_back(d);
      if (d * d != x) {
        divs.push_back(x / d);
      }
    }
  }
  sort(begin(divs), end(divs));
  return divs;
}
pair<long long, long long> dp[MAXN][MAXD];
pair<int, int> prev_________________[MAXN][MAXD];
void restore(int i, int j, vector<int>& res) {
  if (prev_________________[i][j].first == -1) {
    return;
  }
  int pi, pj;
  tie(pi, pj) = prev_________________[i][j];
  assert(pi < i);
  assert(pi >= 0);
  if (pj != j) {
    res.push_back(pi);
  }
  restore(pi, pj, res);
}
void solve() {
  if (k == 1) {
    printf("1\n");
    printf("%d\n", (int)(min_element(a, a + n) - a) + 1);
    return;
  }
  auto divs = gen_divs(k);
  unordered_map<long long, int> pos;
  for (int i = 0; i < (int)((int)(divs).size()); ++i) {
    pos[divs[i]] = i;
  }
  for (int i = 0; i < (int)n; ++i) {
    a_k[i] = gcd(a[i], k);
  }
  for (int i = 0; i < (int)n + 1; ++i)
    for (int j = 0; j < (int)((int)(divs).size()); ++j) {
      dp[i][j] = make_pair(INF, INF);
      prev_________________[i][j] = make_pair(-1, -1);
    }
  dp[0][pos.at(k)] = make_pair(0, 0);
  for (int i = 0; i < (int)n + 1; ++i)
    for (int j = 0; j < (int)((int)(divs).size()); ++j) {
      if (dp[i][j].first == INF) {
        continue;
      }
      long long d = divs[j];
      long long give = gcd(a_k[i], d);
      long long nd = d / give;
      int nj = pos.at(nd);
      auto ndp = dp[i][j];
      ++ndp.first;
      ndp.second += a[i];
      if (ndp < dp[i + 1][nj]) {
        dp[i + 1][nj] = ndp;
        prev_________________[i + 1][nj] = make_pair(i, j);
      }
      if (dp[i][j] < dp[i + 1][j]) {
        dp[i + 1][j] = dp[i][j];
        prev_________________[i + 1][j] = prev_________________[i][j];
      }
    }
  if (dp[n][0].first >= INF) {
    puts("-1");
    return;
  }
  vector<int> res;
  restore(n, 0, res);
  sort(begin(res), end(res));
  printf("%d\n", ((int)(res).size()));
  for (int i : res) {
    printf("%d ", i + 1);
  }
  puts("");
}
int main() {
  while (read()) {
    solve();
  }
  return 0;
}
