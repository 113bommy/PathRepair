#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long LINF = 2e16;
const int INF = 2e9;
const int magic = 348;
const double eps = 1e-10;
const double pi = 3.14159265;
inline int getint() {
  char ch;
  int res;
  bool f;
  while (!isdigit(ch = getchar()) && ch != '-') {
  }
  if (ch == '-')
    f = false, res = 0;
  else
    f = true, res = ch - '0';
  while (isdigit(ch = getchar())) res = res * 10 + ch - '0';
  return f ? res : -res;
}
int n;
struct EDGE {
  int to, len, ind;
};
vector<EDGE> v[200048];
pair<int, int> root[200048];
int rtot = 0;
bool incycle[200048];
long long intree[200048], depth[200048];
int bel[200048];
long long oncycle[200048];
long long cnt[200048];
long long sz[200048];
namespace cycle {
bool inq[200048];
bool found = false;
pair<int, int> seq[200048];
int stot = 0;
void getcycle(int starter) {
  int i, tmp = stot;
  while (seq[tmp].first != starter) tmp--;
  for (i = tmp; i <= stot; i++)
    root[++rtot] = seq[i], incycle[root[rtot].first] = true;
}
void find_cycle(int cur, int lastind) {
  int i;
  seq[++stot].first = cur;
  inq[cur] = true;
  for (i = 0; i < int(v[cur].size()); i++)
    if (v[cur][i].ind != lastind) {
      seq[stot].second = v[cur][i].len;
      if (inq[v[cur][i].to]) {
        found = true;
        getcycle(v[cur][i].to);
        return;
      }
      find_cycle(v[cur][i].to, v[cur][i].ind);
      if (found) return;
    }
  inq[seq[stot--].first] = false;
}
}  // namespace cycle
namespace gtree {
long long dpdown[200048], dpup[200048];
void dfs(int cur, int father) {
  sz[cur] = 1;
  dpdown[cur] = 0;
  for (int i = 0; i < int(v[cur].size()); i++)
    if (v[cur][i].to != father && !incycle[v[cur][i].to]) {
      depth[v[cur][i].to] = depth[cur] + v[cur][i].len;
      dfs(v[cur][i].to, cur);
      sz[cur] += sz[v[cur][i].to];
      dpdown[cur] += dpdown[v[cur][i].to] + v[cur][i].len * sz[v[cur][i].to];
    }
}
queue<pair<int, int> > q;
void getdown(int rt) {
  q.push(make_pair(rt, -1));
  dpup[rt] = 0;
  int i, cur, fa;
  while (!q.empty()) {
    cur = q.front().first;
    fa = q.front().second;
    q.pop();
    intree[cur] = dpdown[cur] + dpup[cur];
    bel[cur] = rt;
    for (i = 0; i < int(v[cur].size()); i++)
      if (v[cur][i].to != fa && !incycle[v[cur][i].to]) {
        dpup[v[cur][i].to] = dpup[cur] + dpdown[cur] - dpdown[v[cur][i].to] -
                             v[cur][i].len * sz[v[cur][i].to] +
                             v[cur][i].len * (sz[rt] - sz[v[cur][i].to]);
        q.push(make_pair(v[cur][i].to, cur));
      }
  }
}
void doit_intree() {
  int i;
  for (i = 1; i <= rtot; i++) {
    depth[root[i].first] = 0;
    dfs(root[i].first, -1);
    getdown(root[i].first);
  }
}
}  // namespace gtree
namespace gcycle {
int csum = 0;
pair<int, int> tmp[600048], tmp2[600048];
void solve(bool type) {
  int i, curcsum = 0, curtsum = 0, curcnt = 0, pt = 1;
  long long sum = 0;
  for (i = 1; i <= rtot; i++) {
    if (i != 1) {
      sum -= curcnt * tmp[i - 1].second;
      curtsum -= intree[tmp[i].first];
      curcsum -= tmp[i - 1].second;
      curcnt -= sz[tmp[i].first];
    }
    while (curcsum <= csum / 2) {
      if (type) {
        if (curcsum + tmp[pt].second > csum / 2) break;
      } else {
        if (csum % 2 == 1) {
          if (curcsum + tmp[pt].second > csum / 2) break;
        } else {
          if (curcsum + tmp[pt].second >= csum / 2) break;
        }
      }
      curcsum += tmp[pt].second;
      pt++;
      curtsum += intree[tmp[pt].first];
      sum += sz[tmp[pt].first] * curcsum;
      curcnt += sz[tmp[pt].first];
    }
    oncycle[tmp[i].first] += sum + curtsum;
    cnt[tmp[i].first] += curcnt;
  }
}
void Reverse() {
  int i, pt = 0;
  for (i = rtot * 2; i >= 1; i--) {
    tmp2[++pt].first = tmp[i].first;
    if (i != 1) tmp2[pt].second = tmp[i - 1].second;
  }
  for (i = 1; i <= rtot * 2; i++) tmp[i] = tmp2[i];
}
void doit_oncycle() {
  int i;
  for (i = 1; i <= rtot; i++) csum += root[i].second;
  for (i = 1; i <= rtot * 2; i++)
    tmp[i] = (i <= rtot ? root[i] : root[i - rtot]);
  solve(true);
  Reverse();
  solve(false);
}
}  // namespace gcycle
inline long long getans(int pt) {
  long long res = 0;
  int rt = bel[pt];
  res += intree[pt];
  res += oncycle[rt];
  res += depth[pt] * cnt[rt];
  return res;
}
int main() {
  int i, first, second, c;
  n = getint();
  for (i = 1; i <= n; i++) {
    first = getint();
    second = getint();
    c = getint();
    v[first].push_back(EDGE{second, c, i});
    v[second].push_back(EDGE{first, c, i});
  }
  cycle::find_cycle(1, -1);
  gtree::doit_intree();
  gcycle::doit_oncycle();
  for (i = 1; i <= n; i++) printf("%lld ", getans(i));
  printf("\n");
  return 0;
}
