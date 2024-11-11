#include <bits/stdc++.h>
using namespace std;
struct node {
  char x;
  vector<node*> ch;
  int ans[103];
  int q;
};
char c[2005][505];
int pref[25][25];
node root;
int k;
void add_string(const char* c) {
  int k = strlen(c);
  node* cur = &root;
  int i;
  for (i = 0; i < k; i++) {
    cur->q++;
    if (i < k - 1) {
      int sz = cur->ch.size();
      int j;
      for (j = 0; j < sz; j++) {
        if (cur->ch[j]->x == c[i + 1]) {
          break;
        }
      }
      if (j == sz) {
        node* tmp = new node;
        tmp->x = c[i + 1];
        tmp->q = 0;
        cur->ch.push_back(tmp);
      }
      cur = cur->ch[j];
    }
  }
}
void solve(node* cur, node* prev_child) {
  int sz = cur->ch.size();
  int i;
  node* lc = NULL;
  for (i = 0; i < sz; i++) {
    solve(cur->ch[i], (i > 0) ? cur->ch[i - 1] : NULL);
    lc = cur->ch[i];
  }
  for (i = 0; i <= k; i++) {
    cur->ans[i] = 0;
    int j;
    for (j = 0; j <= i; j++) {
      int last_ans = 0;
      if (prev_child) last_ans = prev_child->ans[i - j];
      int qq = min(cur->q, j);
      int ex = 0;
      int ss = 0;
      if (cur->x != '$' && cur->x != '#') {
        ss = qq * (qq - 1) / 2;
      }
      if (lc) {
        ex += lc->ans[j];
      }
      cur->ans[i] = max(cur->ans[i], last_ans + ss + ex);
    }
  }
}
int main() {
  int n;
  scanf("%d%d", &n, &k);
  int i;
  root.x = '$';
  root.q = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", c[i] + 1);
    c[i][0] = '$';
    int k = strlen(c[i]);
    c[i][k] = '#';
    c[i][k + 1] = '\0';
    add_string(c[i]);
  }
  int j;
  solve(&root, NULL);
  int ans = root.ans[k];
  printf("%d\n", ans);
  return 0;
}
