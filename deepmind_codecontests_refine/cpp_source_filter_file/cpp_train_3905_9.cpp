#include <bits/stdc++.h>
using namespace std;
const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
struct aho_corasick {
  struct trie_node {
    map<char, int> next;
    int fail;
    bool is_leaf = false;
    trie_node() : fail(-1) {}
    bool have_next(char ch) { return next.find(ch) != next.end(); }
    int &operator[](char ch) { return next[ch]; }
  };
  vector<trie_node> t;
  void insert(const string &s) {
    int root = 0;
    for (const char &ch : s) {
      if (!t[root].have_next(ch)) {
        t.push_back(trie_node());
        t[root][ch] = t.size() - 1;
      }
      root = t[root][ch];
    }
    t[root].is_leaf = true;
  }
  aho_corasick() { t.push_back(trie_node()); }
  int next_state(int cur, char ch) {
    while (cur > 0 && !t[cur].have_next(ch)) cur = t[cur].fail;
    if (t[cur].have_next(ch)) return t[cur][ch];
    return 0;
  }
  void buildAhoTree() {
    queue<int> q;
    for (auto &child : t[0].next) {
      q.push(child.second);
      t[child.second].fail = 0;
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto &child : t[cur].next) {
        int k = next_state(t[cur].fail, child.first);
        t[child.second].fail = k;
        t[child.second].is_leaf |= t[k].is_leaf;
        q.push(child.second);
      }
    }
  }
} aho;
const int MOD = 1e9 + 7;
void add(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
string digit;
int mem[51][2000][2][2];
int solve(int idx, int state, bool equal, bool done) {
  if (idx == (int)(digit.size())) return done;
  int &rt = mem[idx][state][equal][done];
  if (~rt) return rt;
  rt = 0;
  char end = (equal ? digit[idx] : '9');
  for (char d = '0'; d <= end; d++) {
    int nxt = aho.next_state(state, d);
    add(rt, solve(idx + 1, nxt, equal && d == digit[idx],
                  done || aho.t[nxt].is_leaf));
  }
  return rt;
}
int solve(string x) {
  digit = x;
  memset(mem, -1, sizeof mem);
  return solve(0, 0, true, false);
}
int main() {
  run();
  string s, x, y;
  cin >> s >> x >> y;
  int d = x.size() / 2;
  string tmp;
  for (char ch : s) {
    tmp += ch;
    if ((int)(tmp.size()) > d) tmp.erase(0, 1);
    if ((int)(tmp.size()) == d) aho.insert(tmp);
  }
  aho.buildAhoTree();
  for (int i = x.size() - 1; i >= 0; i--) {
    if (x[i] != '0') {
      x[i]--;
      break;
    } else
      x[i] = '9';
  }
  cout << (solve(y) - solve(x) + MOD) % MOD << "\n";
}
