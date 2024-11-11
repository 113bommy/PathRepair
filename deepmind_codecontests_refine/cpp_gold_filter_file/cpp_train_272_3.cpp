#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
long long random2() { return (1ll << 31ll) * eng() + eng(); }
long long n, m, k, q, T;
const long long big = 1000000007;
const long long big2 = 1000000009;
const long long mod = 998244353;
const int MAXN = 200001;
vector<vector<int> > C(MAXN, vector<int>());
vector<vector<int> > C2(MAXN, vector<int>());
bool mark[MAXN] = {0};
int par[MAXN] = {0};
int start;
int win = -1;
int lose = -1;
bool dead_end[MAXN] = {0};
void dfs(int i) {
  if ((int)(C[i]).size() == 0) {
    if (i % 2 == 0) lose = i;
    if (i % 2 == 1) win = i;
  }
  mark[i] = 1;
  for (auto& y : C[i]) {
    if (!mark[y]) {
      par[y] = i;
      dfs(y);
    }
  }
}
int deg[MAXN] = {0};
void get_dead() {
  vector<int> Q;
  for (int c1 = 0; c1 < (2 * n); ++c1) {
    deg[c1] = (int)(C[c1]).size();
    if (deg[c1] == 0) {
      Q.push_back(c1);
    }
  }
  while (!Q.empty()) {
    int a = Q.back();
    Q.pop_back();
    dead_end[a] = 1;
    for (auto& y : C2[a]) {
      deg[y]--;
      if (deg[y] == 0) Q.push_back(y);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e;
  cin >> n >> m;
  for (int c1 = 0; c1 < (n); ++c1) {
    cin >> c;
    for (int c2 = 0; c2 < (c); ++c2) {
      cin >> a;
      a--;
      C[2 * c1].push_back(2 * a + 1);
      C[2 * c1 + 1].push_back(2 * a);
      C2[2 * a].push_back(2 * c1 + 1);
      C2[2 * a + 1].push_back(2 * c1);
    }
  }
  cin >> start;
  start--;
  dfs(2 * start);
  get_dead();
  if (win != -1) {
    cout << "Win\n";
    vector<int> ANS;
    while (win != 2 * start) {
      ANS.push_back(win / 2);
      win = par[win];
    }
    ANS.push_back(start);
    reverse(ANS.begin(), ANS.end());
    for (auto& y : ANS) {
      cout << y + 1 << " ";
    }
    cout << "\n";
  } else {
    if (dead_end[2 * start]) {
      cout << "Lose\n";
    } else {
      cout << "Draw\n";
    }
  }
  return 0;
}
