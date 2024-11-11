#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * t;
}
const int N = 3e5 + 5;
int n, K, mp[N], L[N], R[N];
long long Ans;
struct Node {
  int l, r, v;
  friend bool operator<(Node A, Node B) { return A.l < B.l; }
};
struct Op {
  int p, v;
};
set<Node> S;
vector<Op> G[N];
set<Node>::iterator Split(int x) {
  set<Node>::iterator it = S.lower_bound((Node){x});
  if (it != S.end() && it->l == x) return it;
  Node t = *(--it);
  int l = t.l, r = t.r, v = t.v;
  S.erase(it), S.insert((Node){l, x - 1, v});
  return S.insert((Node){x, r, v}).first;
}
void Assign(int l, int r, int v) {
  set<Node>::iterator b = Split(r + 1), a = Split(l);
  for (set<Node>::iterator it = a; it != b; it++) {
    Node t = *it;
    G[v].push_back((Op){t.v, -(t.r - t.l + 1)});
  }
  S.erase(a, b), S.insert((Node){l, r, v});
  G[v].push_back((Op){v, r - l + 1});
}
bool Check(int len) {
  long long ans = 0, sum = 0, all = 0, num;
  int l = 1, now = 0;
  for (int i = 0; i <= n; i++) mp[i] = 0;
  for (int i = 1; i <= n; i++) {
    for (auto t : G[i]) {
      mp[t.p] += t.v;
      if (t.p >= l) now += t.v;
      if (t.p <= l)
        sum += 1ll * t.v * t.p;
      else
        all += t.v;
    }
    while (l < i && now - mp[l] >= len) {
      now -= mp[l], all -= mp[++l];
      sum += 1ll * mp[l] * l;
    }
    if (now >= len) num += l, ans += sum + all * l;
  }
  if (num < K) return 0;
  Ans = ans - 1ll * (num - K) * len;
  return 1;
}
int main() {
  n = read(), K = read();
  for (int i = 1; i <= n; i++) L[i] = read(), R[i] = read() - 1;
  S.insert((Node){1, 1000000000, 0});
  for (int i = 1; i <= n; i++) Assign(L[i], R[i], i);
  for (int i = 30, len = 0; ~i; i--)
    if (Check(len | (1 << i))) len |= (1 << i);
  cout << Ans;
  return 0;
}
