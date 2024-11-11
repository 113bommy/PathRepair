#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp1[4010][4010] = {0};
int dp2[4010] = {0};
int main() {
  int n, a[100100], dp1[100100] = {0}, visited[100100] = {0};
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      Q;
  scanf("%d", &n);
  Q.push(make_pair(0, 0));
  Q.push(make_pair(0, n + 1));
  for (int(i) = (1); (i) < (n + 1); ++(i)) {
    scanf("%d", &a[i]);
    Q.push(make_pair(a[i], i));
    dp1[i] = a[i];
  }
  while (!Q.empty()) {
    pair<int, int> v = Q.top();
    visited[v.second] = 1;
    Q.pop();
    if (v.second + 1 <= n && !visited[v.second + 1]) {
      visited[v.second + 1] = 1;
      dp1[v.second + 1] = min(dp1[v.second + 1], v.first + 1);
      Q.push(make_pair(v.first + 1, v.second + 1));
    }
    if (v.second - 1 >= 1 && !visited[v.second - 1]) {
      visited[v.second - 1] = 1;
      dp1[v.second - 1] = min(dp1[v.second - 1], v.first + 1);
      Q.push(make_pair(v.first + 1, v.second - 1));
    }
  }
  int max = 0;
  for (int(i) = (1); (i) < (n + 1); ++(i)) {
    if (dp1[i] > max) {
      max = dp1[i];
    }
  }
  printf("%d\n", max);
  return (0);
}
