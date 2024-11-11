#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
char s[MAXN];
char op[MAXN];
int a[MAXN];
stack<int> st;
int n, m, pl;
int p[MAXN], pre[MAXN], Next[MAXN];
int main() {
  scanf("%d%d%d\n", &n, &m, &pl);
  gets(s);
  gets(op);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(')
      st.push(i);
    else {
      p[st.top()] = i;
      p[i] = st.top();
      st.pop();
    }
  }
  Next[0] = 1;
  pre[0] = 0;
  for (int i = 1; i <= n; i++) {
    Next[i] = i + 1;
    pre[i] = i - 1;
  }
  pre[n + 1] = n;
  Next[n + 1] = n + 1;
  for (int i = 0; i < m; i++) {
    if (op[i] == 'L' && pre[pl] > 0)
      pl = pre[pl];
    else if (op[i] == 'R' && Next[pl] <= n)
      pl = Next[pl];
    else {
      int l = p[pl], r = pl;
      if (l > r) swap(l, r);
      pre[Next[r]] = pre[l];
      Next[pre[l]] = Next[r];
      if (Next[r] != n + 1)
        pl = Next[r];
      else
        pl = pre[pl];
    }
  }
  for (int i = 0; i != n + 1; i = Next[i])
    if (i != 0 && i != n + 1) printf("%c", s[i - 1]);
  printf("\n");
}
