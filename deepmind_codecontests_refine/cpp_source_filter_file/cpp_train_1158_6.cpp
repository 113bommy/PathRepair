#include <bits/stdc++.h>
using namespace std;
long long n, m, T, k, q;
const long long big = 1000000007;
const long long big2 = 998244353;
const long long MAXN = 300000;
vector<vector<long long> > C(MAXN, vector<long long>());
vector<vector<long long> > CB(MAXN, vector<long long>());
long long DEPTH[MAXN] = {0};
long long PAR[MAXN] = {0};
bool leaf[MAXN] = {0};
vector<long long> leaves;
bool mark[MAXN] = {0};
long long best = 0;
long long bd = 0;
void dfs(long long i, long long d) {
  DEPTH[i] = d;
  if (d > bd) {
    bd = d;
    best = i;
  }
  mark[i] = 1;
  leaf[i] = 1;
  for (int c1 = 0; c1 < (int)(C[i]).size(); c1++) {
    long long a = C[i][c1];
    if (!mark[a]) {
      leaf[i] = 0;
      PAR[a] = i;
      dfs(a, d + 1);
    } else {
      if (a != PAR[i]) CB[i].push_back(a);
    }
  }
  if (leaf[i]) leaves.push_back(i);
  return;
}
vector<vector<long long> > cyc;
vector<long long> cc;
void fix(long long i) {
  cc.clear();
  long long ai = CB[i][0];
  long long bi = CB[i][1];
  long long a = DEPTH[i] - DEPTH[ai];
  long long b = DEPTH[i] - DEPTH[bi];
  if (a > b) {
    swap(a, b);
    swap(ai, bi);
  }
  b = b - a;
  if ((a + 1) % 3 != 0) {
    cc.push_back(i);
    long long i2 = i;
    while (i2 != ai) {
      cc.push_back(PAR[i2]);
      i2 = PAR[i2];
    }
    cyc.push_back(cc);
    return;
  }
  if ((a + b + 1) % 3 != 0) {
    cc.push_back(i);
    long long i2 = i;
    while (i2 != bi) {
      cc.push_back(PAR[i2]);
      i2 = PAR[i2];
    }
    cyc.push_back(cc);
    return;
  }
  cc.push_back(i);
  cc.push_back(ai);
  long long i2 = ai;
  while (i2 != bi) {
    cc.push_back(PAR[i2]);
    i2 = PAR[i2];
  }
  cyc.push_back(cc);
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, e;
  cin >> n >> m >> k;
  for (int c1 = 0; c1 < m; c1++) {
    cin >> a >> b;
    a--;
    b--;
    C[a].push_back(b);
    C[b].push_back(a);
  }
  PAR[0] = -1;
  dfs(0, 0);
  if ((bd + 1) * k >= n) {
    cout << "PATH\n";
    cout << bd + 1 << "\n";
    a = best;
    while (a != -1) {
      cout << a + 1 << " ";
      a = PAR[a];
    }
    return 0;
  }
  cout << "CYCLE\n";
  for (int c1 = 0; c1 < k; c1++) {
    fix(leaves[c1]);
    cout << (int)(cyc[c1]).size() << "\n";
    for (int c2 = 0; c2 < (int)(cyc[c1]).size(); c2++) {
      cout << cyc[c1][c2] + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
