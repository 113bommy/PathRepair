#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000000;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int p;
    char s[10];
    priority_queue<int, vector<int>, greater<int> > a;
    priority_queue<int, vector<int>, greater<int> > b;
    priority_queue<int, vector<int>, greater<int> > c;
    priority_queue<int, vector<int>, greater<int> > ab;
    priority_queue<int, vector<int>, greater<int> > ac;
    priority_queue<int, vector<int>, greater<int> > bc;
    priority_queue<int, vector<int>, greater<int> > abc;
    while (n--) {
      memset(s, 0, sizeof(s));
      scanf("%d", &p);
      getchar();
      scanf("%s", s);
      int l = strlen(s);
      if (l == 1) {
        if (s[0] == 'A')
          a.push(p);
        else if (s[0] == 'B')
          b.push(p);
        else
          c.push(p);
      } else if (l == 2) {
        int k = s[0] - 'A' + s[1] - 'A';
        if (k == 1)
          ab.push(p);
        else if (k == 2)
          ac.push(p);
        else
          bc.push(p);
      } else
        abc.push(p);
    }
    int ans = maxn;
    if (!a.empty() && !b.empty() && !c.empty())
      ans = a.top() + b.top() + c.top();
    if (!a.empty() && !bc.empty()) ans = min(ans, a.top() + bc.top());
    if (!b.empty() && !ac.empty()) ans = min(ans, b.top() + ac.top());
    if (!c.empty() && !ab.empty()) ans = min(ans, c.top() + ab.top());
    if (!abc.empty()) ans = min(ans, abc.top());
    if (!ac.empty() && !bc.empty()) ans = min(ans, ac.top() + bc.top());
    if (!ac.empty() && !ab.empty()) ans = min(ans, ac.top() + ab.top());
    if (!ab.empty() && !bc.empty()) ans = min(ans, ab.top() + bc.top());
    if (ans == maxn)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
