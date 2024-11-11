#include <bits/stdc++.h>
using namespace std;
char ch;
priority_queue<int> p;
int main() {
  int n, k = 0;
  char s[200005];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    stack<char> q;
    int l = strlen(s), now = 0, ok = 1;
    for (int j = 0; j < l; j++) {
      if (s[j] == '(')
        now++;
      else
        now--;
      if (q.size()) {
        if (q.top() == '(' && s[j] == ')')
          q.pop();
        else
          q.push(s[j]);
      } else
        q.push(s[j]);
    }
    if (abs(now) != q.size() && q.size()) ok = 0;
    if (ok == 1) p.push(now);
  }
  int len = p.size(), ans[100005];
  for (int i = 1; i <= len; i++) {
    ans[i] = p.top();
    p.pop();
  }
  int l = 1, r = len, out = 0;
  while (l < r) {
    if (ans[l] + ans[r] == 0) {
      l++;
      r--;
      out++;
    } else {
      if (abs(ans[l]) < abs(ans[r]))
        r--;
      else
        l++;
    }
  }
  printf("%d\n", out);
  return 0;
}
