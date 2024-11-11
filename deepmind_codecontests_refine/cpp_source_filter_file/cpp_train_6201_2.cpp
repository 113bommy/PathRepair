#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int maxn = 1e5 + 10;
struct Node {
  int x, y, sp;
  long long time;
} nodes[maxn];
int n, m, k;
map<int, vector<Node*> > M1, M2;
void calc_line(Node& st) {
  vector<Node*>& v = (st.sp == 1) ? M1[st.y - st.x] : M2[st.y + st.x];
  for (int i = 0; i < v.size(); ++i) {
    Node& p = *v[i];
    if (p.time == -1) p.time = abs(p.x - st.x) + st.time;
  }
  if (st.sp == 1)
    M1.erase(st.y - st.x);
  else
    M2.erase(st.y + st.x);
}
Node next_edge(Node& st) {
  Node ans;
  int a = st.x, b = st.y, sp = st.sp;
  int t = -a * sp + b;
  if (t >= 0 && t <= m) {
    ans.x = 0;
    ans.y = t;
    if (ans.x != st.x || ans.y != st.y) goto done;
  }
  t = b + (n - a) * sp;
  if (t >= 0 && t <= m) {
    ans.x = n;
    ans.y = t;
    if (ans.x != st.x || ans.y != st.y) goto done;
  }
  t = a + (-b) / sp;
  if (t >= 0 && t <= n) {
    ans.x = t;
    ans.y = 0;
    if (ans.x != st.x || ans.y != st.y) goto done;
  }
  t = a + (m - b) / sp;
  if (t >= 0 && t <= n) {
    ans.x = t;
    ans.y = m;
    if (ans.x != st.x || ans.y != st.y) goto done;
  }
done:
  ans.sp = -st.sp;
  ans.time = st.time + abs(st.x - ans.x);
  return ans;
}
bool isend(Node& u) {
  if (u.x == 0 && u.y == 0) return true;
  if (u.x == 0 && u.y == m) return true;
  if (u.x == n && u.y == m) return true;
  if (u.x == n && u.y == 0) return true;
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) scanf("%d%d", &nodes[i].x, &nodes[i].y);
  for (int i = 0; i < k; ++i) nodes[i].time = -1;
  for (int i = 0; i < k; ++i) {
    Node& p = nodes[i];
    M1[p.y - p.x].push_back(&p);
    M2[p.y + p.x].push_back(&p);
  }
  Node st;
  st.x = 0, st.y = 0, st.sp = 1;
  st.time = 0;
  do {
    calc_line(st);
    st = next_edge(st);
  } while (!isend(st));
  for (int i = 0; i < k; ++i) {
    printf("%d\n", nodes[i].time);
  }
}
