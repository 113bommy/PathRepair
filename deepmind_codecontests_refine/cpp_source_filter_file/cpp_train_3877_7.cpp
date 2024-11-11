#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int K = 14;
const int L = 1000 + 10;
const int N = 400000 + 40;
struct ACAutomaton {
  struct Node {
    int child[K];
    int fail, val;
    void init() {
      memset(child, 0, sizeof(child));
      fail = val = 0;
    }
  };

 public:
  void init() {
    tot = 0;
    root = 0;
    nodes[root].init();
  }
  int newnode() {
    int k = ++tot;
    nodes[k].init();
    return k;
  }
  void add(const string &str, int val) {
    int p = root;
    for (char ch : str) {
      int idx = ch - 'a';
      if (nodes[p].child[idx] == 0) {
        nodes[p].child[idx] = newnode();
      }
      p = nodes[p].child[idx];
    }
    nodes[p].val += val;
  }
  void build() {
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i = 0; i < K; i++) {
        if (nodes[u].child[i]) {
          int v = nodes[u].child[i];
          if (u == root)
            nodes[v].fail = root;
          else
            nodes[v].fail = nodes[nodes[u].fail].child[i];
          nodes[v].val += nodes[nodes[v].fail].val;
          que.push(v);
        } else {
          if (u == root)
            nodes[u].child[i] = 0;
          else
            nodes[u].child[i] = nodes[nodes[u].fail].child[i];
        }
      }
    }
  }
  Node nodes[L];
  int tot;
  int root;
} automaton;
int n;
map<int, map<int, pair<int, long long> > > jump;
string str;
long long dp[L][1 << K];
int pos[N];
inline void check_max(long long &dp, long long candidate) {
  if (dp <= candidate) dp = candidate;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  automaton.init();
  for (int i = 0, val; i < n; i++) {
    cin >> str >> val;
    automaton.add(str, val);
  }
  cin >> str;
  automaton.build();
  int ques_marks = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '?') {
      ques_marks++;
      pos[ques_marks] = i;
      continue;
    }
    int j = i;
    while (j < str.length() && str[j] != '?') j++;
    for (int cur = 0; cur <= automaton.tot; cur++) {
      long long val = 0;
      int z = cur;
      for (int k = i; k < j; k++) {
        z = automaton.nodes[z].child[str[k] - 'a'];
        val += automaton.nodes[z].val;
      }
      jump[cur][i] = {z, val};
    }
    i = j - 1;
  }
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < (1 << K); j++) {
      dp[i][j] = -INF;
    }
  }
  if (str[0] == '?') {
    dp[0][0] = 0;
  } else {
    int nxt = jump[0][0].first;
    int val = jump[0][0].second;
    dp[nxt][0] = val;
  }
  for (int j = 0; j < (1 << K); j++) {
    int ones = __builtin_popcount(j);
    if (ones >= ques_marks) continue;
    for (int i = 0; i <= automaton.tot; i++) {
      if (dp[i][j] == -INF) continue;
      for (int k = 0; k < K; k++) {
        if (j >> k & 1) continue;
        int nxt = automaton.nodes[i].child[k];
        long long val = automaton.nodes[nxt].val;
        int p = pos[ones + 1];
        if (p + 1 < str.length() && str[p + 1] != '?') {
          val += jump[nxt][p + 1].second;
          nxt = jump[nxt][p + 1].first;
        }
        check_max(dp[nxt][j | (1 << k)], dp[i][j] + val);
      }
    }
  }
  long long ans = -INF;
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < (1 << K); j++) {
      if (__builtin_popcount(j) == ques_marks) {
        check_max(ans, dp[i][j]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
