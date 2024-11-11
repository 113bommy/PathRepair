#include <bits/stdc++.h>
using namespace std;
struct P {
  int value;
  int pos;
  P(int v = 0, int p = 0) { value = v, pos = p; }
  bool operator<(const P& t) const { return value > t.value; }
};
char buf[50002];
int main() {
  P tmp;
  priority_queue<P> q;
  int a, b, i, f;
  long long cost;
  scanf("%s", buf);
  cost = f = 0;
  for (i = 0; buf[i]; ++i) {
    if (buf[i] == '(')
      ++f;
    else if (buf[i] == ')')
      --f;
    else {
      buf[i] = ')';
      --f;
      scanf("%d%d", &a, &b);
      cost += b;
      q.push(P(a - b, i));
    }
    while (f < 0) {
      if (q.empty()) {
        puts("-1");
        return 0;
      }
      tmp = q.top();
      q.pop();
      cost += tmp.value;
      buf[tmp.pos] = '(';
      f += 2;
    }
  }
  if (f)
    puts("-1");
  else
    printf("%I64d\n%s\n", cost, buf);
  return 0;
}
