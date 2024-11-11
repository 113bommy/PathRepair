#include <bits/stdc++.h>
using namespace std;
char s[110000];
struct node {
  char c;
  int ind;
};
int mark[110000];
stack<node> sk;
int main() {
  int n, m, i, j;
  node u, v;
  while (scanf("%s", s) != EOF) {
    int len = strlen(s);
    memset(mark, 0, sizeof(mark));
    while (!sk.empty()) sk.pop();
    for (i = 0; i < len; i++) {
      if (s[i] == '(' || s[i] == '[') {
        u.c = s[i];
        u.ind = i;
        sk.push(u);
      } else {
        v.c = 'c';
        if (s[i] == ')') {
          if (!sk.empty()) v = sk.top();
          if (v.c == '(' && !sk.empty()) {
            sk.pop();
          } else {
            u.c = s[i];
            u.ind = i;
            sk.push(u);
          }
        }
        if (s[i] == ']') {
          if (!sk.empty()) v = sk.top();
          if (v.c == '[' && !sk.empty())
            sk.pop();
          else {
            u.c = s[i];
            u.ind = i;
            sk.push(u);
          }
        }
      }
    }
    int cnt1 = 0;
    while (!sk.empty()) {
      u = sk.top();
      mark[u.ind] = 1;
      sk.pop();
      cnt1++;
    }
    if (cnt1 == len) {
      printf("0\n");
      continue;
    }
    int cnt = 0, ans = 0, l = 0, r = 0;
    for (i = 0; i < len; i++) {
      if (!mark[i]) {
        if (s[i] == '[') cnt++;
      } else {
        if (cnt > ans) ans = cnt, r = l;
        cnt = 0;
        l = i + 1;
      }
    }
    if (cnt >= ans) ans = cnt, r = l;
    printf("%d\n", ans);
    for (i = r; i < len; i++)
      if (!mark[i])
        printf("%c", s[i]);
      else
        break;
    printf("\n");
  }
  return 0;
}
