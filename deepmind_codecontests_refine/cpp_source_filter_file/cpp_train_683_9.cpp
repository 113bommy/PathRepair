#include <bits/stdc++.h>
inline long long sbt(long long x) { return __builtin_popcount(x); }
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
string s;
long long adj[200003][27];
long long lft[200003], rgt[200003];
long long p[200003];
long long slink[200003];
long long tv;
long long tp;
long long nd_idx;
long long la;
void add_leaf_r1(long long c) {
  adj[tv][c] = nd_idx;
  lft[nd_idx] = la;
  p[nd_idx++] = tv;
  tv = slink[tv];
  tp = rgt[tv] + 1;
}
void split_the_edge() {
  lft[nd_idx] = lft[tv];
  rgt[nd_idx] = tp - 1;
  p[nd_idx] = p[tv];
  adj[nd_idx][s[tp] - 'a'] = tv;
}
void add_c_transition_leaf(long long c) {
  adj[nd_idx][c] = nd_idx + 1;
  lft[nd_idx + 1] = la;
  p[nd_idx + 1] = nd_idx;
}
void go_down() {
  while (tp <= rgt[nd_idx - 2]) {
    tv = adj[tv][s[tp] - 'a'];
    tp += rgt[tv] - lft[tv] + 1;
  }
}
void st_iteration(long long c) {
slable:;
  if (rgt[tv] < tp) {
    if (adj[tv][c] == -1) {
      add_leaf_r1(c);
      goto slable;
    }
    tv = adj[tv][c];
    tp = lft[tv];
  }
  if (tp == -1 || c == s[tp] - 'a') {
    tp++;
  } else {
    split_the_edge();
    add_c_transition_leaf(c);
    lft[tv] = tp;
    p[tv] = nd_idx;
    adj[p[nd_idx]][s[lft[nd_idx]] - 'a'] = nd_idx;
    nd_idx += 2;
    tv = slink[p[nd_idx - 2]];
    tp = lft[nd_idx - 2];
    go_down();
    if (tp == rgt[nd_idx - 2] + 1)
      slink[nd_idx - 2] = tv;
    else
      slink[nd_idx - 2] = nd_idx;
    tp = rgt[tv] - (tp - rgt[nd_idx - 2]) + 2;
    goto slable;
  }
}
void init_st(long long start_idx) {
  tv = 0;
  tp = 0;
  nd_idx = start_idx;
  fill(rgt, rgt + 200003, s.size() - 1);
  memset(adj, -1, sizeof adj);
  slink[0] = 1;
  for (long long i = 0; i < start_idx; i++) {
    lft[i] = -1;
    rgt[i] = -1;
    if (i) memset(adj[i], 0, sizeof adj[i]);
  }
  long long m = s.size();
  for (la = 0; la < m; la++) st_iteration(s[la] - 'a');
}
long long l[200003], substring_starting[200003];
void dfs(long long i) {
  bool isleaf = 1;
  long long neeche = 0;
  long long endings = 0;
  for (long long ch = 0; ch <= 26; ch++) {
    if (adj[i][ch] != -1) {
      dfs(adj[i][ch]);
      endings += l[adj[i][ch]];
      neeche += substring_starting[adj[i][ch]];
      isleaf = 0;
    }
  }
  if (isleaf) {
    l[i] = 1;
  } else {
    l[i] = endings;
  }
  long long no_of_substr_on_edge =
      (rgt[i] - lft[i] + (rgt[i] != (s.size() - 1)));
  substring_starting[i] = (no_of_substr_on_edge * l[i] * l[i]);
}
long long n;
long long k, curr;
string res;
int32_t main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    memset(substring_starting, 0, sizeof substring_starting);
    memset(l, 0, sizeof l);
    cin >> s;
    n = s.size();
    s = s + '{';
    n++;
    init_st(2);
    dfs(0);
    long long res = 0;
    for (long long i = 1; i <= n + 1; i++) {
      res += (substring_starting[i]);
    }
    cout << res << endl;
  }
  return 0;
}
