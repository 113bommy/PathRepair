#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int n, e[1000005];
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
vector<long long> ps;
map<long long, vector<pair<int, int> > > mp;
long long m, res = (long long)1e18;
vector<pair<int, int> > bst[5005];
int T;
namespace flows {
int match[15];
bool vis[15];
vector<int> nei[1000005];
bool go(int v) {
  int i;
  for (i = 0; i < (int)nei[v].size(); ++i) {
    int u = nei[v][i];
    if (match[u] == -1) {
      match[u] = v;
      return 1;
    }
    if (vis[u]) continue;
    vis[u] = 1;
    if (go(match[u])) {
      match[u] = v;
      return 1;
    }
  }
  return 0;
}
}  // namespace flows
int msks[15];
void go(int done, int cnt) {
  if (done == (1 << T) - 1) {
    int i, j, k;
    vector<pair<int, int> > all;
    using namespace flows;
    memset(match, -1, sizeof(match));
    for (i = 0; i < cnt; ++i) {
      for (j = 0; j < (int)bst[msks[i]].size(); ++j) {
        all.push_back(bst[msks[i]][j]);
        nei[bst[msks[i]][j].second].push_back(i);
      }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    long long sum = 0ll;
    int rc = 0;
    for (i = 0; i < (int)all.size(); ++i) {
      memset(vis, 0, sizeof(vis));
      if (go(all[i].second)) {
        ++rc;
        sum += (long long)all[i].first;
      }
    }
    if (rc == cnt && (long long)cnt * sum < res) res = (long long)cnt * sum;
    for (i = 0; i < (int)all.size(); ++i) {
      nei[all[i].second].clear();
    }
    return;
  }
  int all = (((1 << T) - 1) ^ done), low, i;
  for (low = 0; low < T; ++low) {
    if (all & (1 << low)) break;
  }
  all ^= (1 << low);
  msks[cnt] = (1 << low);
  go(done ^ (1 << low), cnt + 1);
  int ini = all;
  while (all) {
    msks[cnt] = (all | (1 << low));
    go(done ^ (all | (1 << low)), cnt + 1);
    all = ((all - 1) & ini);
  }
}
vector<pair<int, int> > mrg(vector<pair<int, int> > &A,
                            vector<pair<int, int> > &B) {
  int sA = (int)A.size(), sB = (int)B.size(), S = min(T, sA + sB);
  vector<pair<int, int> > ret(S);
  int pA = 0, pB = 0, i;
  for (i = 0; i < S; ++i) {
    if (pA == sA)
      ret[i] = B[pB++];
    else if (pB == sB || A[pA] < B[pB])
      ret[i] = A[pA++];
    else
      ret[i] = B[pB++];
  }
  return ret;
}
int main() {
  int i, j, k;
  scanf("%d%I64d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%I64d", a + i);
  }
  for (i = 0; i < n; ++i) {
    scanf("%d", e + i);
  }
  long long g = a[0];
  for (i = 1; i < n; ++i) g = gcd(g, a[i]);
  for (i = 2; (long long)i * (long long)i <= g; ++i) {
    if (!(g % (long long)i)) {
      ps.push_back((long long)i);
      while (!(g % (long long)i)) g /= (long long)i;
    }
  }
  if (g > 1ll) ps.push_back(g);
  T = (int)ps.size();
  if (!T) {
    printf("0\n");
    return 0;
  }
  for (i = 0; i < n; ++i) {
    long long cur = 1ll, tmp = a[i];
    for (j = 0; j < T; ++j) {
      while (!(tmp % ps[j])) {
        tmp /= ps[j];
        cur *= ps[j];
      }
    }
    mp[cur].push_back(make_pair(e[i], i));
  }
  map<long long, vector<pair<int, int> > >::iterator it;
  for (it = mp.begin(); it != mp.end(); ++it) {
    vector<pair<int, int> > S = it->second;
    sort(S.begin(), S.end());
    if ((int)S.size() > T) S.resize(T);
    long long fs = it->first;
    vector<long long> prs(0);
    prs.resize(T, 1ll);
    for (j = 0; j < T; ++j) {
      while (!(fs % ps[j])) {
        fs /= ps[j];
        prs[j] *= ps[j];
      }
    }
    for (j = 0; j < (1 << T); ++j) {
      long long req = 1ll;
      for (k = 0; k < T; ++k) {
        if (j & (1 << k)) req *= prs[k];
      }
      if (req <= m) {
        bst[j] = mrg(bst[j], S);
      }
    }
  }
  go(0, 0);
  if (res >= (long long)1e17)
    printf("-1\n");
  else
    printf("%I64d\n", res);
  return 0;
}
