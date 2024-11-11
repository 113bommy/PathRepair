#include <bits/stdc++.h>
using namespace std;
int T, N;
char S[300007], p[300007];
int End[300007], ans[300007], length[300007], num[300007];
vector<int> Spot[300007];
set<int> mch[300007];
queue<int> q;
struct State {
  int next[26];
  int fail, cnt;
} Tree[300007];
struct Aho {
  int Size;
  void init() {
    Size = 1;
    while (!q.empty()) q.pop();
    memset(End, 0, sizeof(End));
    for (int i = 0; i < 300007; i++) ans[i] = 1e9;
    for (int i = 0; i < 300007; i++) {
      memset(Tree[i].next, 0, sizeof(Tree[i].next));
      Tree[i].fail = Tree[i].cnt = 0;
    }
  }
  void Add_string(char *S, int id, int tot) {
    int L = strlen(S);
    length[id] = L;
    int now = 0;
    for (int i = 0; i < L; i++) {
      char c = S[i];
      if (!Tree[now].next[c - 'a']) Tree[now].next[c - 'a'] = Size++;
      now = Tree[now].next[c - 'a'];
    }
    Tree[now].cnt++;
    End[now] = id;
    num[id] = tot;
  }
  void GetFail() {
    int now = 0;
    Tree[now].fail = -1;
    q.push(now);
    while (!q.empty()) {
      now = q.front();
      q.pop();
      for (int i = 0; i < 26; i++) {
        int to = Tree[now].next[i];
        if (to) {
          if (Tree[to].cnt) mch[to].insert(to);
          if (now == 0)
            Tree[to].fail = 0;
          else {
            int pos = Tree[now].fail;
            while (pos != -1) {
              if (Tree[pos].next[i]) {
                Tree[to].fail = Tree[pos].next[i];
                for (set<int>::iterator it = mch[Tree[to].fail].begin();
                     it != mch[Tree[to].fail].end(); it++) {
                  mch[to].insert(*it);
                }
                break;
              }
              pos = Tree[pos].fail;
            }
            if (pos == -1) Tree[to].fail = 0;
          }
          q.push(to);
        }
      }
    }
  }
  void match(char *S) {
    int L = strlen(S);
    int now = 0;
    for (int i = 0; i < L; i++) {
      char c = S[i];
      if (Tree[now].next[c - 'a'])
        now = Tree[now].next[c - 'a'];
      else {
        int pos = Tree[now].fail;
        while (pos != -1 && Tree[pos].next[c - 'a'] == 0) pos = Tree[pos].fail;
        if (pos == -1)
          now = 0;
        else
          now = Tree[pos].next[c - 'a'];
      }
      int temp = now;
      for (set<int>::iterator it = mch[now].begin(); it != mch[now].end();
           it++) {
        int id = End[*it];
        Spot[id].push_back(i);
        if (Spot[id].size() >= num[id] && num[id] > 0) {
          int last = Spot[id].size() - 1;
          ans[id] = min(ans[id], Spot[id][last] - Spot[id][last - num[id] + 1] +
                                     length[id]);
        }
      }
    }
    for (int i = 1; i <= N; i++) {
      if (ans[i] == 1e9)
        cout << -1 << endl;
      else
        cout << ans[i] << endl;
    }
  }
} aho;
int main() {
  std::ios::sync_with_stdio(false);
  T = 1;
  while (T--) {
    aho.init();
    cin >> S;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      cin >> p;
      aho.Add_string(p, i + 1, num);
    }
    aho.GetFail();
    aho.match(S);
  }
  return 0;
}
