#include <bits/stdc++.h>
using namespace std;
int p[200007];
int c1[200007];
int c2[200007];
bool used[200007];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c1[i]);
    c1[i]--;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c2[i]);
    c2[i]--;
  }
  priority_queue<pair<int, int>> q[3];
  for (int i = 0; i < n; ++i) {
    if (c1[i] == c2[i]) {
      q[c1[i]].push(make_pair(-p[i], i));
    } else {
      q[c1[i]].push(make_pair(-p[i], i));
      q[c2[i]].push(make_pair(-p[i], i));
    }
  }
  int m, x;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    x--;
    while (!q[x].empty() && used[q[x].top().second]) q[x].pop();
    if (q[x].empty())
      printf("-1 ");
    else {
      printf("%d ", -q[x].top().first);
      used[q[x].top().second] = 1;
      q[x].pop();
    }
  }
}
