#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
string s, t;
struct Node {
  int i, j, k;
  Node(int i = 0, int j = 0, int k = 0) : i(i), j(j), k(k) {}
};
Node f[maxn][maxn][maxn << 1];
void solve() {
  int n = s.length(), m = t.length();
  memset(f, -1, sizeof(f));
  queue<Node> q;
  q.push(Node(0, 0, 0));
  f[0][0][0] = Node(0, 0, 0);
  while (!q.empty()) {
    Node u = q.front();
    q.pop();
    int i = u.i, j = u.j, k = u.k;
    int vi, vj, vk;
    vi = i, vj = j, vk = k + 1;
    if (s[i] == '(') vi++;
    if (t[j] == '(') vj++;
    if (vk <= n + m && f[vi][vj][vk].i == -1) {
      f[vi][vj][vk] = u;
      q.push(Node(vi, vj, vk));
    }
    vi = i, vj = j, vk = k - 1;
    if (s[i] == ')') vi++;
    if (t[j] == ')') vj++;
    if (vk >= 0 && f[vi][vj][vk].i == -1) {
      f[vi][vj][vk] = u;
      q.push(Node(vi, vj, vk));
    }
  }
  Node t;
  int i = n, j = m, k = 0;
  string ans = "";
  while (i || j || k) {
    t = f[i][j][k];
    if (t.k > k)
      ans = ")" + ans;
    else
      ans = "(" + ans;
    i = t.i;
    j = t.j;
    k = t.k;
  }
  cout << ans << endl;
}
int main() {
  cin >> s >> t;
  solve();
  return 0;
}
