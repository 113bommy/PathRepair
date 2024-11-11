#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 26;
struct node {
  int pre = 0, sl = 0, id = 0;
  int go[M];
  node() {
    for (int i = 0; i < M; i++) go[i] = 0;
  }
};
node ah[2 * N];
int nxt = 1;
int k[N], ans[N], sz[N];
void trie(string s, int id) {
  int n = 0;
  for (char c : s) {
    if (!ah[n].go[c - 'a']) ah[n].go[c - 'a'] = nxt++;
    n = ah[n].go[c - 'a'];
  }
  ah[n].id = id;
}
void build_ah() {
  int n = 0, u, v;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    n = q.front();
    q.pop();
    for (int i = 0; i < M; i++) {
      if (!ah[n].go[i]) continue;
      u = ah[n].sl;
      v = ah[n].go[i];
      while (u && !ah[u].go[i]) u = ah[u].sl;
      u = ah[u].go[i];
      if (u != v) {
        ah[v].sl = u;
        ah[v].pre = ah[u].id ? u : ah[u].pre;
      }
      q.push(v);
    }
  }
}
void find(string s) {
  int n = 0, i = 0, id;
  vector<deque<int> > found(N);
  for (char c : s) {
    while (n && !ah[n].go[c - 'a']) n = ah[n].sl;
    n = ah[n].go[c - 'a'];
    for (int m = n; m > 0; m = ah[m].pre) {
      id = ah[m].id;
      if (!id) continue;
      deque<int> &dq = found[id];
      dq.push_back(i);
      while (dq.size() > k[id]) dq.pop_front();
      if (dq.size() == k[id])
        ans[id] = min(ans[id], dq.back() - dq.front() + sz[id]);
    }
    i++;
  }
}
int main() {
  string s, x;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i] >> x;
    sz[i] = x.size();
    trie(x, i);
    ans[i] = 2 * N;
  }
  build_ah();
  find(s);
  for (int i = 1; i <= n; i++) {
    if (ans[i] != 2 * N)
      cout << ans[i] << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
