#include <bits/stdc++.h>
using namespace std;
class CompareDist {
 public:
  bool operator()(pair<pair<int, int>, int> n1, pair<pair<int, int>, int> n2) {
    if (n1.second > n2.second)
      return true;
    else
      return false;
  }
};
int main() {
  int n, x, y, d, c = 0;
  cin >> n;
  pair<int, int> p;
  pair<pair<int, int>, int> q;
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,
                 CompareDist>
      pq;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    if (x != 0) c += 2;
    if (y != 0) c += 2;
    p.first = x;
    p.second = y;
    d = abs(x) + abs(y);
    q.first = p;
    q.second = d;
    pq.push(q);
  }
  c += 2 * n;
  printf("%d\n", c);
  while (!pq.empty()) {
    x = ((pq.top()).first).first;
    y = ((pq.top()).first).second;
    pq.pop();
    if (x > 0)
      printf("1 %u R\n", abs(x));
    else if (x < 0)
      printf("1 %u L\n", abs(x));
    if (y > 0)
      printf("1 %u U\n", abs(y));
    else if (y < 0)
      printf("1 %u D\n", abs(y));
    printf("2\n");
    if (x > 0)
      printf("1 %u R\n", abs(x));
    else if (x < 0)
      printf("1 %u L\n", abs(x));
    if (y > 0)
      printf("1 %u U\n", abs(y));
    else if (y < 0)
      printf("1 %u D\n", abs(y));
    printf("3\n");
  }
  return 0;
}
