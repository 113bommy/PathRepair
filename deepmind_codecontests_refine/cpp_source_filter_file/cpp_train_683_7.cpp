#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long inf = 1LL << 30;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const int Alpha = 28;
const int MAXLEN = 1e5 + 5;
class SuffixAutomata {
 public:
  struct state {
    int len, link;
    int next[Alpha];
    state() {
      len = link = 0;
      memset(next, -1, sizeof(next));
    }
  };
  long long mem[MAXLEN];
  int sz = 1, last = 0;
  vector<state> st;
  vector<int> terminal;
  void Init(int len) {
    st.clear();
    terminal.clear();
    st.resize(2 * len);
    terminal.resize(2 * len);
    sz = 1;
    last = 0;
    st[0].len = 0;
    st[0].link = -1;
    memset(mem, -1, sizeof(mem));
  }
  void extend(char ccc) {
    int c = ccc - 'a';
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && st[p].next[c] == -1) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = sz++;
        st[clone].len = st[p].len + 1;
        for (int j = 0; j < Alpha; j++) st[clone].next[j] = st[q].next[j];
        st[clone].link = st[q].link;
        while (p != -1 && st[p].next[c] == q) {
          st[p].next[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  void getTerminal() {
    int p = last;
    while (p > 0) terminal[p] = 1, p = st[p].link;
  }
  void build(string s) {
    Init(s.size());
    for (auto x : s) extend(x);
    getTerminal();
  }
  long long dp(int x) {
    long long &ret = mem[x];
    if (ret != -1) return ret;
    ret = terminal[x];
    for (int i = 0; i < Alpha; i++) {
      if (st[x].next[i] == -1) continue;
      ret += dp(st[x].next[i]);
    }
    return ret;
  }
  void solve(string s) {
    build(s);
    long long ans = 0;
    for (int nd = 1; nd < sz; nd++) {
      long long all_string = st[nd].len - st[st[nd].link].len;
      long long frq = dp(nd);
      ans += (frq * frq * all_string);
    }
    printf("%lld\n", ans);
  }
};
char a[100100];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    SuffixAutomata SA;
    scanf("%s", &a);
    SA.solve(a);
  }
}
