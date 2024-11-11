#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > pq[2];
int main() {
  int n, i, c, s;
  cin >> n;
  int w1, b1;
  for (i = 0; i < (n); i++) {
    scanf("%d%d", &c, &s);
    pq[c].push(make_pair(-s, i + 1));
    if (c)
      w1 = i + 1;
    else
      b1 = i + 1;
  }
  pair<int, int> b, w;
  while (!pq[0].empty() && !pq[1].empty()) {
    b = pq[0].top();
    w = pq[1].top();
    pq[0].pop();
    pq[1].pop();
    b.first *= -1;
    w.first *= -1;
    if (b.first > w.first) {
      pq[0].push(make_pair(-(b.first - w.first), b.second));
    } else {
      pq[1].push(make_pair(-(w.first - b.first), w.second));
    }
    printf("%d %d %d\n", b.second, w.second,
           ((b.first) < (w.first) ? (b.first) : (w.first)));
  }
  if (((int)(pq[0]).size()) > 1) {
    pq[0].pop();
    while (!pq[0].empty()) {
      printf("%d %d %d\n", w1, pq[0].top().second, 0);
      pq[0].pop();
    }
  }
  if (((int)(pq[1]).size()) > 1) {
    pq[1].pop();
    while (!pq[1].empty()) {
      printf("%d %d %d\n", b1, pq[1].top().second, 0);
      pq[1].pop();
    }
  }
  return 0;
}
