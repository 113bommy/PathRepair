#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 212345;
using T2 = tuple<int, int>;
using T3 = tuple<int, int, int>;
priority_queue<T2> pc;
priority_queue<T3> sk;
int a[maxn], b[maxn];
int main(void) {
  int n, m, cnt = 0, cost = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (n); i++) {
    int tmp;
    scanf("%d", &tmp);
    pc.emplace(tmp, i);
  }
  for (int i = 0; i < (m); i++) {
    int tmp;
    scanf("%d", &tmp);
    sk.emplace(tmp, 0, i);
  }
  while (!pc.empty() && !sk.empty()) {
    if (get<0>(pc.top()) > get<0>(sk.top()))
      pc.pop();
    else if (get<0>(pc.top()) == get<0>(sk.top())) {
      cnt++;
      cost += a[get<2>(sk.top())] = get<1>(sk.top());
      b[get<1>(pc.top())] = get<2>(sk.top()) + 1;
      pc.pop();
      sk.pop();
    } else {
      T3 tmp = sk.top();
      sk.pop();
      get<0>(tmp) = get<0>(tmp) / 2 + get<0>(tmp) % 2;
      get<1>(tmp)++;
      sk.push(tmp);
    }
  }
  printf("%d %d\n", cnt, cost);
  for (int i = 0; i < (m); i++) printf("%d ", a[i]);
  puts("");
  for (int i = 0; i < (n); i++) printf("%d ", b[i]);
  puts("");
  return 0;
}
