#include <bits/stdc++.h>
using namespace std;
int src, cost[2000] = {0};
int n, t;
int jmin = 0;
queue<int> q, v;
void BFS() {
  while (!q.empty()) {
    src = q.front();
    q.pop();
    for (int i = 0; i < 2; i++) {
      cost[(src * 2) + i] += cost[src];
      if ((src * 2) + i < pow(2, n)) q.push(src * 2 + i);
    }
  }
}
void jamals() {
  while (t--) {
    int a, b, max;
    a = v.front();
    v.pop();
    b = v.front();
    v.pop();
    if (a > b)
      max = a;
    else
      max = b;
    jmin += abs(a - b);
    v.push(max);
  }
}
int main() {
  cin >> n;
  for (int e = 2; e < pow(2, n + 1); e++) {
    cin >> cost[e];
  }
  q.push(1);
  BFS();
  for (int i = pow(2, n + 1) - pow(2, n); i < pow(2, n + 1); i++) {
    v.push(cost[i]);
  }
  int h = n ^ 2;
  t = pow(2, n + 1) - pow(2, n) - 1;
  jamals();
  cout << jmin;
  return 0;
}
