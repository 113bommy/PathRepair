#include <bits/stdc++.h>
using namespace std;
char str[111111];
int val[111111];
char match[222];
int sum(int l, int r) { return l == 0 ? val[r] : val[r] - val[l - 1]; }
struct node {
  int l, r;
};
bool in(node a, node b) { return b.l < a.l && a.r < b.r; }
bool link(node a, node b) { return a.r + 1 == b.l; }
int main() {
  match[')'] = '(';
  match[']'] = '[';
  gets(str);
  int len = 0;
  for (int i = 0; str[i]; i++) {
    len++;
    val[i] = str[i] == '[';
    if (i) val[i] += val[i - 1];
  }
  stack<node> ans;
  stack<int> st;
  for (int i = 0; str[i]; i++) {
    switch (str[i]) {
      case '(':
      case '[':
        st.push(i);
        break;
      case ')':
      case ']':
        if (st.size() == 0 || str[st.top()] != match[str[i]]) {
          while (st.size()) st.pop();
        } else {
          node tmp;
          tmp.l = st.top();
          st.pop();
          tmp.r = i;
          for (;;) {
            if (ans.size() && link(ans.top(), tmp)) {
              tmp.l = ans.top().l;
            } else if (ans.size() && in(ans.top(), tmp)) {
              ans.pop();
            } else {
              ans.push(tmp);
              break;
            }
          }
        }
    }
  }
  int ret = 0;
  int ll, rr;
  while (ans.size()) {
    int r = ans.top().r;
    int l = ans.top().l;
    ans.pop();
    int tmp = sum(l, r);
    if (tmp > ret) {
      ret = tmp;
      ll = l;
      rr = r;
    }
  }
  printf("%d\n", ret);
  if (ret) {
    for (int i = ll; i <= rr; i++) putchar(str[i]);
  }
  return 0;
}
