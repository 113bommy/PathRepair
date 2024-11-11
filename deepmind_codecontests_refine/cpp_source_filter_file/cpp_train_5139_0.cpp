#include <bits/stdc++.h>
using namespace std;
int N;
bool indegree[200010];
int a[200010];
bool visited[200010];
vector<pair<int, int> > ans;
int main() {
  int i, j, k;
  scanf("%d", &N);
  for (i = (0); i < (N); i++) scanf("%d", a + i);
  for (i = (0); i < (N); i++) a[i]--;
  memset((visited), 0, sizeof(visited));
  ;
  memset((indegree), 0, sizeof(indegree));
  ;
  for (i = (0); i < (N); i++) indegree[a[i]] = true;
  bool f = false;
  for (i = (0); i < (N); i++) {
    if (indegree[i]) continue;
    f = true;
    int x = i;
    while (!visited[x]) {
      visited[x] = true;
      indegree[x] = true;
      x = a[x];
    }
    ans.push_back(make_pair(i, x));
  }
  for (i = (0); i < (N); i++) {
    if (visited[i]) continue;
    int x = i;
    while (!visited[x]) {
      visited[x] = true;
      x = a[x];
    }
    ans.push_back(make_pair(i, i));
  }
  if (!f && ans.size() < 2) {
    printf("0\n");
    return 0;
  }
  ans.push_back(ans[0]);
  printf("%d\n", ans.size() - 1);
  for (i = (0); i < (ans.size() - 1); i++)
    printf("%d %d\n", ans[i].second + 1, ans[i].first + 1);
  return 0;
}
