#include <bits/stdc++.h>
using namespace std;
int all_num = 0;
struct node {
  string val;
  node *l, *r;
  int num;
  node(string val, node *l = 0, node *r = 0)
      : val(val), l(l), r(r), num(all_num++){};
};
int res[5050];
map<string, node *> q;
void dfs(node *t, int bit, int val) {
  if (res[t->num] != -1) return;
  if (t->val == "?") {
    res[t->num] = val;
    return;
  }
  if (!t->l) {
    res[t->num] = t->val[bit] - '0';
    return;
  }
  dfs(t->l, bit, val);
  dfs(t->r, bit, val);
  if (t->val == "OR") res[t->num] = res[t->l->num] | res[t->r->num];
  if (t->val == "XOR") res[t->num] = res[t->l->num] ^ res[t->r->num];
  if (t->val == "AND") res[t->num] = res[t->l->num] & res[t->r->num];
}
int go(int bit, int val) {
  for (int i = 0; i < all_num; i++) res[i] = -1;
  int cou = 0;
  for (pair<string, node *> p : q) {
    if (res[p.second->num] == -1) dfs(p.second, bit, val);
    if (p.first != "?") cou += res[p.second->num];
  }
  return cou;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  getline(cin, *(new string()));
  q["?"] = new node("?");
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    int pos1 = s.find(' ');
    string name = s.substr(0, pos1);
    if (isdigit(s[pos1 + 4])) {
      q[name] = new node(s.substr(pos1 + 4));
    } else {
      int pos2 = s.find(' ', pos1 + 4);
      int pos3 = s.find(' ', pos2 + 1);
      string name1 = s.substr(pos1 + 4, pos2 - pos1 - 4);
      string name2 = s.substr(pos3 + 1);
      string op = s.substr(pos2 + 1, pos3 - pos2 - 1);
      q[name] = new node(op, q[name1], q[name2]);
    }
  }
  vector<char> ans1(m), ans2(m);
  for (int i = 0; i < m; i++) {
    int g0 = go(i, 0), g1 = go(i, 1);
    if (g0 <= g1)
      ans1[i] = '0';
    else
      ans1[i] = '1';
    if (g0 >= g1)
      ans2[i] = '0';
    else
      ans2[i] = '1';
  }
  for (int i = 0; i < m; i++) cout << ans1[i];
  cout << "\n";
  for (int i = 0; i < m; i++) cout << ans2[i];
}
