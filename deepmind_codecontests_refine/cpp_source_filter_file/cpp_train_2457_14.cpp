#include <bits/stdc++.h>
using namespace std;
const int N = 5003;
const int LOGN = (int)log2(N) + 2;
int SQRTN = (int)sqrt(N) + 7;
const long long infi = 1ll << 60;
long long n, arr[N], modo[N];
vector<long long> nums[100005], m[10];
vector<pair<long long, long long> > vec;
const int MAXN = 2 * N;
const int MAXM = 12 * N;
struct Edge {
  int v, c, w;
  Edge() {}
  Edge(int v, int c, int w) : v(v), c(c), w(w) {}
};
struct MinCostMaxFlow {
  int n, m, source, sink;
  vector<int> e[MAXN];
  Edge edge[MAXM * 2];
  void init(int n, int source, int sink) {
    this->n = n;
    this->m = 0;
    this->source = source;
    this->sink = sink;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }
  void addEdge(int a, int b, int c, int w) {
    edge[m] = Edge(b, c, w);
    e[a].push_back(m++);
    edge[m] = Edge(a, 0, -w);
    e[b].push_back(m++);
  }
  bool mark[MAXN];
  int maxc[MAXN];
  int minw[MAXN];
  int pre[MAXN];
  int d[MAXN];
  bool _spfa() {
    queue<int> q;
    fill(mark, mark + n, false);
    fill(maxc, maxc + n, 0);
    fill(minw, minw + n, numeric_limits<int>::max());
    fill(pre, pre + n, -1);
    fill(d, d + n, 0);
    mark[source] = true;
    maxc[source] = numeric_limits<int>::max();
    minw[source] = 0;
    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      mark[cur] = false;
      q.pop();
      for (size_t i = 0; i < e[cur].size(); ++i) {
        int id = e[cur][i];
        int v = edge[id].v;
        int c = min(maxc[cur], edge[id].c);
        if (c == 0) {
          continue;
        }
        int w = minw[cur] + edge[id].w;
        if (minw[v] > w || (minw[v] == w && maxc[v] < c)) {
          maxc[v] = c;
          minw[v] = w;
          pre[v] = id;
          d[v] = d[cur] + 1;
          if (d[v] >= n) {
            return false;
          }
          if (!mark[v]) {
            mark[v] = true;
            q.push(v);
          }
        }
      }
    }
    return true;
  }
  pair<int, int> GetMinCostMaxFlow() {
    int sumc = 0, sumw = 0;
    while (true) {
      _spfa();
      if (maxc[sink] == 0) {
        break;
      } else if (minw[sink] >= 0) {
        break;
      } else {
        int c = maxc[sink];
        sumc += c;
        sumw += c * minw[sink];
        int cur = sink;
        while (cur != source) {
          int id = pre[cur];
          edge[id].c -= c;
          edge[id ^ 1].c += c;
          cur = edge[id ^ 1].v;
        }
        vec.push_back({sumc, sumw});
        if (sumc == 4) break;
      }
    }
    return make_pair(sumc, sumw);
  }
};
set<pair<long long, long long> > st;
int main() {
  scanf("%lld", &n);
  ;
  int src = 0, snk = 2 * n + 1;
  vector<pair<long long, pair<long long, long long> > > edges;
  for (int(i) = (1); (i) <= (int)(n); ++(i)) {
    scanf("%lld", &arr[i]);
    ;
    modo[i] = arr[i] % 7;
    nums[arr[i]].push_back(i);
    m[modo[i]].push_back(i);
    edges.push_back({0, {src, i}});
    edges.push_back({0, {i + n, snk}});
    edges.push_back({0, {i, i + n}});
  }
  for (int(i) = (1); (i) <= (int)(n); ++(i)) {
    if ((long long)nums[arr[i] + 1].size()) {
      long long idx =
          upper_bound(nums[arr[i] + 1].begin(), nums[arr[i] + 1].end(), i) -
          nums[arr[i] + 1].begin();
      for (int(idxx) = (idx);
           (idxx) <=
           (int)(min(idx + 2, (long long)nums[arr[i] + 1].size() - 1));
           ++(idxx)) {
        int j = nums[arr[i] + 1][idxx];
        if (!st.count({i, j})) edges.push_back({-1, {i + n, j}});
        st.insert({i, j});
      }
    }
    if ((long long)nums[arr[i] - 1].size()) {
      long long idx =
          upper_bound(nums[arr[i] - 1].begin(), nums[arr[i] - 1].end(), i) -
          nums[arr[i] - 1].begin();
      for (int(idxx) = (idx);
           (idxx) <=
           (int)(min(idx + 2, (long long)nums[arr[i] - 1].size() - 1));
           ++(idxx)) {
        int j = nums[arr[i] - 1][idxx];
        if (!st.count({i, j})) edges.push_back({-1, {i + n, j}});
        st.insert({i, j});
      }
    }
    if ((long long)m[modo[i]].size()) {
      long long idx = upper_bound(m[modo[i]].begin(), m[modo[i]].end(), i) -
                      m[modo[i]].begin();
      for (int(idxx) = (idx);
           (idxx) <= (int)(min(idx + 2, (long long)m[modo[i]].size() - 1));
           ++(idxx)) {
        int j = m[modo[i]][idxx];
        if (!st.count({i, j})) edges.push_back({-1, {i + n, j}});
        st.insert({i, j});
      }
    }
  }
  MinCostMaxFlow mcf;
  mcf.init(2 * n + 2, src, snk);
  for (auto& cur : edges)
    mcf.addEdge(cur.second.first, cur.second.second, 1, cur.first);
  pair<long long, long long> koko = mcf.GetMinCostMaxFlow();
  long long ans = 2 - koko.second;
  if (koko.first == 1 && -koko.second + 1 == n) --ans;
  if (koko.second == 2 && vec[0].second == vec[1].second) ++ans;
  cout << ans << endl;
  return 0;
}
