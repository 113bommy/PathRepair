#include <bits/stdc++.h>
using namespace std;
void Max(int &x, int y) { x = max(x, y); }
void Min(int &x, int y) { x = min(x, y); }
const int N = 1e5 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  os << '[';
  for (unsigned int i = 0; i < a.size(); i++)
    os << a[i] << (i < a.size() - 1 ? ", " : "");
  os << ']';
  return os;
}
vector<int> sta, en;
int Time = 0;
vector<vector<int> > a(N);
long long mark[N];
int sum[N];
int S;
void dfs(int u) {
  for (auto v : a[u]) dfs(v), mark[u] += mark[v];
}
struct SQRTtree {
  int val[N], lazy[N];
  SQRTtree() {
    memset(val, 0, sizeof(val));
    memset(lazy, 0, sizeof(lazy));
  }
  void update(int l, int r) {
    while (l <= r && l % S) val[l]++, l++;
    while (l <= r && r % S != S - 1) val[r]++, r--;
    if (l <= r)
      for (signed i = (l / S); i <= (r / S); i++) lazy[i]++;
  }
  int query(int x) { return val[x] + lazy[x / S]; }
} tree;
struct ahoCorasick {
  vector<vector<int> > ch;
  vector<int> fail, term;
  int peak = 0;
  ahoCorasick() {
    ch = vector<vector<int> >(N + 5, vector<int>(26, 0));
    sta = en = fail = term = vector<int>(N, 0);
  }
  int add(string s) {
    int u = 0;
    for (auto &it : s) {
      if (ch[u][it - 'a'] == 0) ch[u][it - 'a'] = ++peak;
      u = ch[u][it - 'a'];
    }
    return u;
  }
  void pdfs(int u) {
    sta[u] = ++Time;
    for (auto v : a[u]) pdfs(v);
    en[u] = Time;
  }
  void createTree() {
    for (signed i = (1); i <= (peak); i++) a[fail[i]].push_back(i);
    pdfs(0);
  }
  void createAho() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (signed i = (0); i <= (25); i++) {
        int v = ch[u][i];
        int fv = ch[fail[u]][i];
        if (v == 0)
          ch[u][i] = fv;
        else {
          if (fv == v)
            fail[v] = 0;
          else
            fail[v] = fv;
          q.push(v);
        }
      }
    }
    createTree();
  }
} Aho;
struct Query {
  int first, second, id;
  Query(int _fi, int _se, int _id) : first(_fi), second(_se), id(_id){};
};
vector<string> e;
vector<Query> bigQ[N];
vector<Query> smallQ[N];
int whEn[N];
long long ans_to_query[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  S = sqrt(n);
  for (signed i = (1); i <= (n); i++) {
    string s;
    cin >> s;
    e.push_back(s);
    whEn[i - 1] = Aho.add(s);
  }
  Aho.createAho();
  for (signed Q = (0); Q <= (q - 1); Q++) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    r--;
    k--;
    if (e[k].size() >= S)
      bigQ[k].push_back(Query(l, r, Q));
    else {
      if (l - 1 >= 0) smallQ[l - 1].push_back(Query(k, -1, Q));
      smallQ[r].push_back(Query(k, 1, Q));
    }
  }
  auto countOne = [&](string &s) {
    int u = 0;
    long long ret = 0;
    for (auto c : s) {
      u = Aho.ch[u][c - 'a'];
      ret += tree.query(sta[u]);
    }
    return ret;
  };
  auto countMany = [&](string &s) {
    memset(mark, 0, sizeof(mark));
    memset(sum, 0, sizeof(sum));
    int u = 0;
    for (auto &c : s) {
      u = Aho.ch[u][c - 'a'];
      mark[u]++;
    }
    dfs(0);
    for (signed i = (0); i <= (n - 1); i++)
      sum[i] = (i > 0 ? sum[i - 1] : 0) + mark[whEn[i]];
  };
  for (signed p = (0); p <= (n - 1); p++) {
    tree.update(sta[whEn[p]], en[whEn[p]]);
    if (e[p].size() >= S) {
      countMany(e[p]);
      for (auto &it : bigQ[p]) {
        ans_to_query[it.id] =
            sum[it.second] - (it.first > 0 ? sum[it.first - 1] : 0);
      }
    }
    for (auto &it : smallQ[p]) {
      int wh = it.first, sign = it.second;
      ans_to_query[it.id] += 1LL * sign * countOne(e[wh]);
    }
  }
  for (signed i = (0); i <= (q - 1); i++) {
    cout << ans_to_query[i] << '\n';
  }
}
