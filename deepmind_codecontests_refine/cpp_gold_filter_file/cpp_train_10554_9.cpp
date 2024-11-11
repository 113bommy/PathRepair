#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ad;
int W[100000];
long long NP[100000], OP[100000], EP[100000];
long long cnt = 0;
void dfs(int i, int par) {
  W[i] = 1;
  long long add = 0, npwsum = 0, npsum = 0, opsum = 0;
  for (typeof(ad[i].begin()) it = ad[i].begin(); it != ad[i].end(); it++) {
    if (*it == par) continue;
    dfs(*it, i);
    W[i] += W[*it];
    npwsum += W[*it] * 1LL * NP[*it];
    npsum += NP[*it];
    opsum += OP[*it];
  }
  add += (W[i] - 1) * 1LL * (W[i] - 1) * 1LL * (npsum);
  add += (npsum)*npsum;
  NP[i] = (W[i] * 1LL * (W[i] - 1)) / 2;
  OP[i] = opsum + (W[i]) * npsum;
  EP[i] = npsum;
  for (typeof(ad[i].begin()) it = ad[i].begin(); it != ad[i].end(); it++) {
    if (*it == par) continue;
    long long sub = 2 * W[*it] * (npwsum - W[*it] * NP[*it]) +
                    W[*it] * 1LL * W[*it] * npsum + NP[*it] * NP[*it];
    OP[i] -= W[*it] * NP[*it];
    add -= sub;
  }
  add /= 2;
  add += (W[i]) * (opsum);
  add += (W[i] - 1) * npsum;
  for (typeof(ad[i].begin()) it = ad[i].begin(); it != ad[i].end(); it++) {
    if (*it == par) continue;
    long long sub = W[*it] * OP[*it] + W[*it] * NP[*it];
    add -= sub;
  }
  cnt += add;
}
int main() {
  int n;
  scanf("%d", &n);
  ad.resize(n);
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    u--;
    v--;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  dfs(0, -1);
  cout << cnt * 2 << endl;
  return 0;
}
