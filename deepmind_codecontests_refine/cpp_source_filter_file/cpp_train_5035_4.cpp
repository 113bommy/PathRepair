#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
char str[N][N];
int use[N];
int ans[N], tot;
int Ncnt, root;
struct Node {
  vector<int> ch;
  int color;
  int leaf;
  int kind;
  Node(void){};
} tree[N * N * 2];
void fail() {
  puts("NO");
  exit(0);
}
void build() {
  root = Ncnt;
  tree[root].kind = 0;
  for (int i = 1; i <= m; i++) {
    ++Ncnt;
    tree[Ncnt].leaf = i;
    tree[root].ch.push_back(Ncnt);
  }
}
void paint(int rt) {
  if (tree[rt].leaf) {
    if (use[tree[rt].leaf])
      tree[rt].color = 2;
    else
      tree[rt].color = 0;
    return;
  }
  int empty = 1, half = 0, full = 1;
  for (int i = 0; i < tree[rt].ch.size(); i++) {
    int v = tree[rt].ch[i];
    paint(v);
    if (tree[v].color) empty = 0;
    if (!tree[v].color) full = 0;
    if (tree[v].color == 1) half = 1;
  }
  if ((!empty && !full) || (half))
    tree[rt].color = 1;
  else if (full)
    tree[rt].color = 2;
  else if (empty)
    tree[rt].color = 0;
}
void clear(int rt) {
  vector<int> newch;
  for (int i = 0; i < tree[rt].ch.size(); i++) {
    int v = tree[rt].ch[i];
    if (tree[v].leaf) {
      newch.push_back(v);
      continue;
    }
    if (tree[v].ch.size() == 1)
      newch.push_back(tree[v].ch[0]);
    else
      newch.push_back(v);
  }
  tree[rt].ch = newch;
  if (tree[rt].ch.size() <= 2) tree[rt].kind = 0;
}
void arrange(int rt) {
  if (tree[rt].leaf) return;
  vector<int> son = tree[rt].ch, emp, ful;
  int d = -1;
  for (int i = 0; i < son.size(); i++) {
    int v = tree[rt].ch[i];
    if (tree[v].color == 1) {
      if (d != -1) fail();
      if (d == -1) d = i;
    }
    if (tree[v].color == 0) emp.push_back(i);
    if (tree[v].color == 2) ful.push_back(i);
  }
  if (d != -1) arrange(son[d]);
  int empn = emp.size(), fuln = ful.size();
  if (tree[rt].kind) {
    if ((empn && emp[empn - 1] - emp[0] != empn - 1) ||
        (fuln && ful[fuln - 1] - ful[0] != fuln - 1))
      fail();
    if (d != -1) {
      if (empn && fuln) {
        if (d == 0 || d == son.size() - 1) {
          fail();
        }
      }
    }
    if (empn && fuln) {
      if (emp[0] > ful[0]) {
        reverse(emp.begin(), emp.end());
        reverse(ful.begin(), ful.end());
      }
    }
    if (empn && !fuln && d != -1) {
      if (emp[0] > d) reverse(emp.begin(), emp.end());
    }
    if (fuln && !empn && d != -1) {
      if (ful[0] < d) reverse(ful.begin(), ful.end());
    }
    vector<int> newch;
    for (int i = 0; i < empn; i++) newch.push_back(son[emp[i]]);
    if (d != -1) {
      int v = son[d];
      for (int i = 0; i < tree[v].ch.size(); i++)
        newch.push_back(tree[v].ch[i]);
    }
    for (int i = 0; i < fuln; i++) newch.push_back(son[ful[i]]);
    tree[rt].ch = newch;
  } else {
    tree[rt].kind = 1;
    vector<int> newch;
    if (empn) {
      ++Ncnt;
      for (int i = 0; i < empn; i++) tree[Ncnt].ch.push_back(son[emp[i]]);
      clear(Ncnt);
      newch.push_back(Ncnt);
    }
    if (d != -1) {
      int v = son[d];
      for (int i = 0; i < tree[v].ch.size(); i++)
        newch.push_back(tree[v].ch[i]);
    }
    if (fuln) {
      ++Ncnt;
      for (int i = 0; i < fuln; i++) tree[Ncnt].ch.push_back(son[ful[i]]);
      clear(Ncnt);
      newch.push_back(Ncnt);
    }
    tree[rt].ch = newch;
  }
  clear(rt);
}
void solve(int rt) {
  if (tree[rt].leaf) return;
  int count = 0, full = 0;
  for (int i = 0; i < tree[rt].ch.size(); i++) {
    int v = tree[rt].ch[i];
    if (tree[v].color == 1) count++;
    if (tree[v].color == 2) full++;
  }
  if (count > 2) fail();
  if (full || count > 1) {
    vector<int> son = tree[rt].ch, ful, hlf;
    for (int i = 0; i < son.size(); i++) {
      int v = son[i];
      if (tree[v].color == 1) hlf.push_back(i);
      if (tree[v].color == 2) ful.push_back(i);
    }
    int fuln = ful.size(), hlfn = hlf.size();
    if (tree[rt].kind == 1) {
      if (fuln && ful[fuln - 1] - ful[0] != fuln - 1) fail();
      for (int i = 0; i < hlfn; i++)
        if (fuln && hlf[i] != ful[0] - 1 && hlf[i] != ful[fuln - 1] + 1) fail();
      if (count == 2)
        if (hlf[1] - hlf[0] != 1) fail();
      vector<int> newch;
      for (int i = 0; i < son.size(); i++) {
        if (tree[son[i]].color != 1)
          newch.push_back(son[i]);
        else {
          arrange(son[i]);
          vector<int> pp = tree[son[i]].ch;
          if ((hlfn != 1 && i != hlf[0]) ||
              (hlfn == 1 && fuln && hlf[0] == ful[fuln - 1] + 1))
            reverse(pp.begin(), pp.end());
          for (int i = 0; i < pp.size(); i++) newch.push_back(pp[i]);
        }
      }
      tree[rt].ch = newch;
    } else {
      vector<int> newch;
      for (int i = 0; i < hlfn; i++) arrange(son[hlf[i]]);
      for (int i = 0; i < son.size(); i++)
        if (tree[son[i]].color == 0) newch.push_back(son[i]);
      int nowq = ++Ncnt;
      tree[nowq].kind = 1;
      newch.push_back(nowq);
      if (hlfn) {
        int v = son[hlf[0]];
        for (int i = 0; i < tree[v].ch.size(); i++)
          tree[nowq].ch.push_back(tree[v].ch[i]);
      }
      if (fuln) {
        int nowp = ++Ncnt;
        tree[nowp].kind = 0;
        for (int i = 0; i < fuln; i++) tree[nowp].ch.push_back(son[ful[i]]);
        clear(nowp);
        tree[nowq].ch.push_back(nowp);
      }
      if (hlfn == 2) {
        int v = son[hlf[1]];
        for (int i = tree[v].ch.size() - 1; i >= 0; i--)
          tree[nowq].ch.push_back(tree[v].ch[i]);
      }
      clear(nowq);
      tree[rt].ch = newch;
    }
  } else {
    for (int i = 0; i < tree[rt].ch.size(); i++) {
      int v = tree[rt].ch[i];
      if (tree[v].color == 1) solve(v);
    }
  }
  clear(rt);
}
void dfs(int rt) {
  if (tree[rt].leaf) {
    ans[++tot] = tree[rt].leaf;
    return;
  }
  for (int i = 0; i < tree[rt].ch.size(); i++) dfs(tree[rt].ch[i]);
}
int main() {
  scanf("%d", &n);
  m = n;
  for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
  build();
  for (int i = 1; i <= n; i++) {
    memset(use, 0, sizeof use);
    for (int j = 1; j <= m; j++)
      if (str[i][j] == '1') use[j]++;
    paint(root);
    solve(root);
  }
  dfs(root);
  puts("YES");
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= n; j++) printf("%c", str[i][ans[j]]);
  return 0;
}
